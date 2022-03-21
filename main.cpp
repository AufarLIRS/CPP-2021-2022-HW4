#include <iostream>

void rowSum(int** array, unsigned rows_count, unsigned cols_count)
{
  for (int i = 0; i < rows_count; i++)
  {
    int sum = 0;
    for (int j = 0; j < cols_count; j++)
    {
      sum += array[i][j];
    }
    std::cout << "Сумма " << i + 1 <<"й строки = " << sum << std::endl;
  }
}

int colSum(int** array, unsigned rows_count, unsigned cols_count)
{
  int max = 0;
  for (int i = 0; i < cols_count; i++)
  {
    int sum = 0;
    for (int j = 0; j < rows_count; j++)
    {
      sum += array[j][i];
    }
    if (max < sum)
    {
      max = sum;
    }
    std::cout << "Сумма " << i + 1 << "ого столбца = " << sum << std::endl; 
  }
  return max;
}

char* resize(char* str, unsigned size, unsigned new_size)
{
  if ( new_size < size )
  {
    return new char[0];
  }

  char* newstr = new char[new_size];
  for (int i = 0; i < size; i++)
  {
    newstr[i] = str[i];
  }
  delete str;
  return newstr;
}
class Rational
{
private:
	int numerator_;
	int denominator_;
};

int main()
{
  int x = 5;
  int y = 5;
  int new_x = 10;
  char* new_array = new char[5]{ '1', '2', '3', '4','5' };
  int** array = new int*[x];
  for (int i = 0; i < x; i++)
  {
    array[i] = new int[y]; 
  }
  for (int i = 0; i < x; i++)
  {
    for (int j = 0; j < y; j++)
    {
      array[i][j] = rand() % 10;
      std::cout << array[i][j] << " ";  
    }
    std::cout << std::endl;
  }
  rowSum(array, x, y);
  colSum(array, x, y);  
  char* func = resize(new_array, x, new_x); 
}

