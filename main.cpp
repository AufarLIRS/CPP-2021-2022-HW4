#include "iostream"


void rowSum(int ** array, unsigned rows_count, unsigned cols_count)
{
    int mas[rows_count] = { 0 };

    for (int i{0}; i < cols_count; i++)
    {
        for (int j{0}; j < rows_count; j++)
        {
            mas[j] += array[i][j];

            std::cout << array[i][j] << " ";
        }
        std::cout << "" << std::endl;
    }
    
    std::cout << "" << std::endl;

    for (int i{0}; i < cols_count; i++)
    {
        std::cout << i << " строка = " << mas[i] << std::endl; 
    }
}

int colSum(int ** array, unsigned rows_count, unsigned cols_count)
{

    int mas[cols_count] = { 0 };

    for (int i{0}; i < rows_count; i++)
    {
        for (int j{0}; j < cols_count; j++)
        {
            mas[j] += array[i][j];

            std::cout << array[i][j] << " ";
        }
        std::cout << "" << std::endl;
    }
    
    std::cout << "" << std::endl;

    int max{mas[0]};

    for (int i{0}; i < cols_count; i++)
    {
        if (max < mas[i])
        {
            max = mas[i];
        }
        std::cout << i << " столбец = " << mas[i] << std::endl; 
    }
    
    
    return max;
}

char* resize(char* str, unsigned size, unsigned new_size) 
{ 
    if (new_size < size)
    {
        return nullptr;
    }

    char* new_mas = new char[new_size];
    
    for(int i = 0; i < size; i++)
    {
        new_mas[i] = str[i]; 
    }

    delete[] str;
	return new_mas;
}

int main()
{   

    // Task 1

    // {
    //     int** mas = new int*[2];
    //     mas[0] = new int[5]{1, 2, 3, 4, 5};
    //     mas[1] = new int[5]{6, 7, 8, 9, 10};

    //     rowSum(mas, 2, 5);
    //     delete[] mas;
    // }



    // Task 2

    // {
    //     int** mas = new int*[2];
    //     mas[0] = new int[5]{1, 2, 3, 4, 5};
    //     mas[1] = new int[5]{6, 7, 8, 9, 10};

    //     int res = rowSum(mas, 2, 5);
    //     std::cout << "max_sum_cols = " << res << std::endl;
    //     delete[] mas;
    // }


    // Task 3



    // {
    //     char* mas = new char[4];
    //     char* new_mas = (resize(mas, 4, 8));
    //     std::cout << &mas[0] << std::endl;
    //     delete [] mas;
    // }


}