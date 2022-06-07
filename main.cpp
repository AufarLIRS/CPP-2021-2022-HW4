#include <iostream>
#include <limits>

using namespace std;

// Создает двумерный динамический массив
// с выводом массива на экран
int** create_array(size_t rows, size_t cols)
{
  // Объявляем двумерный массив в куче 10x10
  int** mas = new int*[rows];
  for (size_t i = 0; i < rows; i++)
    mas[i] = new int[cols];

  // Заполняем двумерный массив случайными значениями от 0 до 99
  srand(size_t(time(0)));
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < cols; j++)
    {
      mas[i][j] = rand() % 100;
    }
  }

  // Массив на экран
  cout << "\nSource array: \n";
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < cols; j++)
    {
      cout << setw(4) << mas[i][j];
    }
    cout << endl;
  }

  return mas;
}

// Удаление двумерного массива
void delete_array(int** mas, size_t rows)
{
  for (size_t i = 0; i < rows; i++)
    delete[] mas[i];
  delete[] mas;
}

// Считает суммы двумерного массива построчно
// с выводом сумм на экран
void rowSum(int** array, unsigned rows_count, unsigned cols_count)
{
  cout << "\nSum of rows: \n";
  for (size_t i = 0; i < rows_count; i++)
  {
    int sum = 0;
    for (size_t j = 0; j < cols_count; j++)
    {
      sum += array[i][j];
    }
    cout << sum << endl;
  }
}

// Считает суммы двумерного массива построчно
// с выводом сумм на экран
int colSum(int** array, unsigned rows_count, unsigned cols_count)
{
  int maxsum = std::numeric_limits<int>::min();
  cout << "\nSum of columns: \n";
  for (size_t i = 0; i < cols_count; i++)
  {
    int sum = 0;
    for (size_t j = 0; j < rows_count; j++)
    {
      sum += array[j][i];
    }
    if (maxsum < sum)
      maxsum = sum;
    cout << sum << endl;
  }
  return maxsum;
}

// Основная функция
int main()
{
  // Task 1
  // Создаем двумерный динамический массив и печатаем его на экран
  int** mas = create_array(8, 10);

  // Считаем суммы каждой строки с выводом на экран
  rowSum(mas, 8, 10);

  // Удаляем массив
  delete_array(mas, 8);

  // Task 2
  // Создаем двумерный динамический массив и печатаем его на экран
  int** mas2 = create_array(5, 8);

  // Считаем суммы каждого столбца с выводом на экран
  cout << "Max sum column: " << colSum(mas2, 5, 8) << endl;

  // Удаляем массив
  delete_array(mas2, 5);
  
  return 0;
}
