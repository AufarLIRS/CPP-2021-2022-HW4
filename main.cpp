#include<iostream>

void rowSum(int ** array, unsigned rows_count, unsigned cols_count)
{ 
    int result = 0;

    for(int i = 0; i < rows_count; i++)
    {
        for(int j = 0; j < cols_count; j++)
        {
            result += array[i][j]; 
        }
        std::cout << result << std::endl;
        result = 0;
    }
}

int colSum(int ** array, unsigned rows_count, unsigned cols_count)
{
    int result = 0;
    int maxResult = 0;

    for(int i = 0; i < cols_count; i++)
    {
        for(int j = 0; j < rows_count; j++)
        {
            result += array[j][i];
        }
        std::cout << result << std::endl;
        if(maxResult <= result )
        {
            maxResult = result;
        }
        result = 0;
    }
    return maxResult;
}

char* resize(char* str, unsigned size, unsigned new_size) 
{ 
    if(new_size < size)
    {
        return new char[0];
    }

    char* newStr = new char[new_size];

    for(int i = 0; i < size; i++)
    {
        newStr[i] = str[i]; 
    }

    delete[] str;
	return newStr;
}


class Rational
{
	private:
		int numerator_;
		int denominator_;
	public:
		Rational()
		{}

		Rational(int numerator, int denominator) : numerator_(numerator), denominator_(denominator)
		{
			if(numerator_ > denominator_) // Используем Алгоритм Евклида для нахождения НОД
			{
				int a = numerator_;
				int b = denominator_;
				while(a != b && a != 0)
				{
					if(a > b)
					{
						a -= b;
					}
					else 
					{
						b -= a;
					}
				}
				if(a == 0)
				{
					numerator_ /= denominator_;
					denominator_ = 1;
				}
				else
				{
					numerator_ /= a;
					denominator_ /= a;
				}
			}
		}
		//////////////////Арифметические операторы операторы с double 
		Rational operator * (double num)
		{
			Rational result(numerator_ * num, denominator_);
			return result;
		}
		Rational operator / (double num)
		{
			Rational result(numerator_, denominator_ * num);
			return result;
		}

		Rational operator + (double num)
		{
			Rational result(numerator_ + num * denominator_ , denominator_ );
			return result;
		}

		Rational operator - (double num)
		{
			Rational result(numerator_ + num * denominator_ , denominator_ );
			return result;
		}
		//////////////////Арифметические операторы операторы с Rational
		Rational operator * (Rational r)
		{
			Rational result(numerator_ * r.numerator_, denominator_ * r.denominator_);
			return result;
		}
		Rational operator / (Rational r)
		{
			Rational result(numerator_ * r.denominator_ , denominator_ * r.numerator_);
			return result;
		}

		Rational operator + (Rational r)
		{
			Rational result(numerator_  * r.denominator_  + r.numerator_ * denominator_, denominator_ * r.denominator_);
			return result;
		}

		Rational operator - (Rational r)
		{
			Rational result(numerator_  * r.denominator_  - r.numerator_ * denominator_, denominator_ * r.denominator_);
			return result;
		}
		//////////////////Инкременты и декременты
		Rational operator ++ () //Префиксный инкремент
		{
			Rational result(numerator_ +  denominator_ , denominator_ );
			return result;
		}

		Rational operator++ (int)//Постфиксный инкремент
		{
			Rational prev = *this;
			++*this;
			return prev;
		}

		Rational Rational::operator -- ()//Префиксный декремент
		{
			Rational result(numerator_ -  denominator_ , denominator_ );
			return result;
		}

		Rational operator-- (int)//Постфиксный декремент
		{
			Rational prev = *this;
			--*this;
			return prev;
		}
		//////////////////Операторы сравнения с Rational
		bool operator == (Rational c2)
		{
			return numerator_ * c2.denominator_ == denominator_ * c2.numerator_;
		}

		bool operator != (Rational c2)
		{
			return numerator_ * c2.denominator_ != denominator_ * c2.numerator_;
		}

		bool operator > (Rational c2)
		{
			return numerator_ * c2.denominator_ > denominator_ * c2.numerator_;
		}

		bool operator >= (Rational c2)
		{
			return numerator_ * c2.denominator_ >= denominator_ * c2.numerator_;
		}

		bool operator < (Rational c2)
		{
			return numerator_ * c2.denominator_ < denominator_ * c2.numerator_;
		}

		bool operator <= (Rational c2)
		{
			return numerator_ * c2.denominator_ <= denominator_ * c2.numerator_;
		}

		//////////////////Операторы сравнения с целочисленными значениями
		bool operator == (int n)
		{
			return numerator_  == denominator_ * n;
		}

		bool operator != (int n)
		{
			return numerator_  != denominator_ * n;
		}

		bool operator > (int n)
		{
			return numerator_  > denominator_ * n;
		}

		bool operator >= (int n)
		{
			return numerator_  >= denominator_ * n;
		}

		bool operator < (int n)
		{
			return numerator_  < denominator_ * n;
		}

		bool operator <= (int n)
		{
			return numerator_  <= denominator_ * n;
		}
};


int main()
{
	int length = 5;
    int width = 5;
    int** array = new int*[length]; 
    for (int i = 0; i < length; i++)
        {
            array[i] = new int[width];  
        }
    for(int i = 0; i < length; i++)
    {
        for(int j = 0; j < width; j++)
        {
            array[i][j] = i+j;
        }
    }

    for(int i = 0; i < length; i++)
    {
        for(int j = 0; j < width; j++)
        {
            std::cout << array[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    rowSum(array, length, width);
    std::cout << colSum(array, length, width) << std::endl;


    char* charArray = new char[length]{ '0', '1', '2', '3','4' };

    int newLength = 10;
    char* newcharArray = resize(charArray, length, newLength);
    for(int i = 0,k = 0; i < sizeof(newcharArray);i+=sizeof(newcharArray[0]),k++)
    {
        std::cout << newcharArray[k] << ' ';
    }

    std::cout << std::endl << sizeof(newcharArray)/sizeof(newcharArray[0]);//вывод получился 8, хотя ожидался 10, странно...
}