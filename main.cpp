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
/*
class Rational 
{
...
private:                        в процессе разработки
	int numerator_;
	int denominator_;
}
*/
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