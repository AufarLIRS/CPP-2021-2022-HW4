#include <iostream>
#include <limits>
#include <string>

struct result {
    int x = 0;
    int y = 0;
    int output = 0;
};
void rowSum(int** array, unsigned rows_count, unsigned cols_count)
{
    result i;
    do
    {
        do
            i.output += *(*(array + i.x) + i.y);
        while (++i.y != rows_count);
        std::cout << i.output << std::endl;
        i.y = 0;
        i.output = 0;
    }
    while (++i.x != cols_count);
}
int colSum(int** array, unsigned rows_count, unsigned cols_count)
{
    int min { std::numeric_limits<int>::min() };
    result i;
    do
    {
        do
            i.output += *(*(array + i.x) + i.y);
        while (++i.y != cols_count);
        min = i.output > min ? i.output : min;
        i.y = 0;
        i.output = 0;
    } while (++i.x != rows_count);
    return min;
}

char* resize(char* str, unsigned size, unsigned new_size)
{
    if (new_size < size)
        return nullptr;

    char* newstr = new char[new_size];
    size--; // избавляемся от нуль-терминатора
    do
        newstr[size] = *(str + size);
    while (--size < new_size);
    newstr[new_size] = '\0';
    delete [] str;
    return newstr;
}

int** CreateArray()
{
    int** array = new int* [3];
    for (int a = 0; a < 3; a++)
        array[a] = new int[3]{ 1, 2, 3 };
    return array;
}
void DisplayMatrix(int** array, int x, int y) {
    result i;
    do
    {
        do
            std::cout << *(*(array + i.x) + i.y) << '\t';
        while (++i.y != x);
        i.y = 0;
        std::cout << '\n';
    } while (++i.x != y);
}

void Task1()
{
    int** array = CreateArray();
    rowSum(array, 3, 3);
    DisplayMatrix(array, 3, 3);
}
void Task2()
{
    int** array = CreateArray();
    int max = { colSum(array, 3, 3) };

    std::cout << max << '\n';

    DisplayMatrix(array, 3, 3);
}
void Task3() {
    char* str = new char[4]{ '1', 'z', 'y', '\0' };
    std::cout << strlen(str) << std::endl << str << std::endl;

    char* res = resize(str, 3, 33);
    std::cout << strlen(res) << std::endl << res << std::endl;
}

class Rational
{
public:
    Rational();
    Rational(int n);
    Rational(int n, int d);

    Rational operator * (Rational r);
    Rational operator / (Rational r);
    Rational operator + (Rational r);
    Rational operator - (Rational r);
    
    Rational& operator ++();
    Rational operator ++(int i);
    Rational& operator --();
    Rational operator --(int d);
    
    bool operator >(Rational r);
    bool operator <(Rational r);
    bool operator <=(Rational r);
    bool operator >=(Rational r);
    bool operator ==(Rational r);
    bool operator !=(Rational r);

    double operator * (double d);
    double operator / (double d);
    double operator + (double d);
    double operator - (double d);

    bool operator >(int i);
    bool operator <(int i);
    bool operator <=(int i);
    bool operator >=(int i);
    bool operator ==(int i);
    bool operator !=(int i);
    
    void write() {
        std::cout << numerator_ << '/' << denominator_ << '\n';
    }
private:
    int numerator_;
    int denominator_;
    int gcd() {
        int result = numerator_ < denominator_ ? numerator_ : denominator_;
        do
            if (numerator_ % result == 0 && denominator_ % result == 0)
                break;
        while (--result > 0);
        return result;
    }
    void Reduct() {
        int gcd = this->gcd();
        numerator_ /= gcd;
        denominator_ /= gcd;
        if (denominator_ < 0)
        {
            numerator_ *= -1;
            denominator_ *= -1;
        }
    }
    
};

Rational::Rational()
{
    numerator_ = 0;
    denominator_ = 1;
}
Rational::Rational(int n)
{
    numerator_ = n;
    denominator_ = 1;
}
Rational::Rational(int n, int d)
{
    numerator_ = n;
    denominator_ = d;
}

Rational Rational::operator *(Rational r)
{
    Rational result(numerator_ * r.numerator_, denominator_* r.denominator_);
    result.Reduct();
    return result;
}
Rational Rational::operator /(Rational r)
{
    Rational result(numerator_ * r.denominator_, denominator_ * r.numerator_);
    result.Reduct();
    return result;
}
Rational Rational::operator +(Rational r)
{
    int base = denominator_ * r.denominator_;
    Rational result(numerator_ * r.denominator_ + r.numerator_ * denominator_, base);
    result.Reduct();
    return result;
}
Rational Rational::operator -(Rational r)
{
    int base = denominator_ * r.denominator_;
    Rational result(numerator_ * r.denominator_ - r.numerator_ * denominator_, base);
    result.Reduct();
    return result;
}

Rational& Rational::operator ++() {
    numerator_ += denominator_;
    Reduct();
    return *this;
}
Rational Rational::operator ++(int i) {
    Rational prev = *this;
    ++* this;
    Reduct();
    return prev;
}
Rational& Rational::operator --() {
    numerator_ -= denominator_;
    Reduct();
    return *this;
}
Rational Rational::operator --(int i) {
    Rational prev = *this;
    --* this;
    Reduct();
    return prev;
}

bool Rational::operator >(Rational r) {
    return numerator_ * r.denominator_ > r.numerator_ * denominator_;
}
bool Rational::operator <(Rational r) {
    return numerator_ * r.denominator_ < r.numerator_ * denominator_;
}
bool Rational::operator >=(Rational r) {
    return numerator_ * r.denominator_ >= r.numerator_ * denominator_;
}
bool Rational::operator <=(Rational r) {
    return numerator_ * r.denominator_ <= r.numerator_* denominator_;
}
bool Rational::operator ==(Rational r) {
    Reduct();
    r.Reduct();
    return numerator_ == r.numerator_ && denominator_ == r.denominator_;
}
bool Rational::operator !=(Rational r) {
    Reduct();
    r.Reduct();
    return numerator_ != r.numerator_ || denominator_ != r.denominator_;
}

double Rational::operator *(double d)
{
    double result = ((double)numerator_ / (double)denominator_) * d;
    return result;
}
double Rational::operator /(double d)
{
    double result = ((double)numerator_ / (double)denominator_) / d;
    return result;
}
double Rational::operator +(double d)
{
    double result = ((double)numerator_ / (double)denominator_) + d;
    return result;
}
double Rational::operator -(double d)
{
    double result = ((double)numerator_ / (double)denominator_) - d;
    return result;
}

bool Rational::operator >(int i) {
    return ((double)numerator_ / (double)denominator_) > i;
}
bool Rational::operator <(int i) {
    return ((double)numerator_ / (double)denominator_) < i;
}
bool Rational::operator >=(int i) {
    return ((double)numerator_ / (double)denominator_) >= i;
}
bool Rational::operator <= (int i) {
    return ((double)numerator_ / (double)denominator_) <= i;
}
bool Rational::operator ==(int i) {
    Reduct();
    return numerator_ == i && denominator_ == 1;
}
bool Rational::operator !=(int i) {
    Reduct();
    return numerator_ != i || denominator_ != 1;
}


int main()
{
    //Task1();
    //Task2();
    //Task3();
}