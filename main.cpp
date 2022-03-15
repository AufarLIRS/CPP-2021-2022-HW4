#include <iostream>

void rowSum(int** array, unsigned rows_count, unsigned cols_count)
{
  for (int i = 0; i < rows_count; i++)
  {
    int result = 0;
    for (int j = 0; j < cols_count; j++)
    {
      result += array[i][j];
    }
    std::cout << "Сумма строки #" << i + 1 << " = " << result << std::endl;
  }
}

int colSum(int** array, unsigned rows_count, unsigned cols_count)
{
  int max = 0;
  for (int i = 0; i < cols_count; i++)
  {
    int result = 0;
    for (int j = 0; j < rows_count; j++)
    {
      result += array[j][i];
    }
    if (max < result)
    {
      max = result;
    }
    // std::cout << "Сумма столбца #" << i + 1 << " = " << result << std::endl; //вывести сумму столбцов
  }
  return max;
}

char* resize(char* str, unsigned size, unsigned new_size)
{
  if (size > new_size)
  {
    char* new_arr = new char[0];
    return new_arr;
  }

  char* new_arr = new char[new_size];
  for (int i = 0; i < size; i++)
  {
    new_arr[i] = str[i];
  }
  delete str;
  return new_arr;
}

int main()
{
  int x = 2;
  int y = 3;
  int** arr = new int*[x];  // Создаем массив указателей
  for (int i = 0; i < x; i++)
  {
    arr[i] = new int[y];  // Создаем элементы
  }

  for (int i = 0; i < x; i++)
  {
    for (int j = 0; j < y; j++)
    {
      arr[i][j] = rand() % 10;
      std::cout << arr[i][j] << " ";  // Вывести элементы на консольку
    }
    std::cout << std::endl;
  }

  // rowSum(arr, 2, 4);   //Task1

  // std::cout << colSum(arr, 2, 4);    //Task2

  char* arrChar = new char[4]{ 'w', 'a', 's', 'd' };
  char* nc = resize(arrChar, 4, 8);  // Task3  (не нашел рабочие способы выведения размера массива)

  // Task 4 маловероятно, что сделаю как надо...
}
