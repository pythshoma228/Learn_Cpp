#include <iostream>
#include <time.h>
using namespace std;

void fillArray(int arr[][5], const int ROW, const int COL) 
{
    
    srand(time(NULL));
    for (int i = 0; i < ROW; ++i)
    {
        for (int j = 0; j < COL; ++j) 
        {
            arr[i][j] = rand() % 60;
        }
    }
}

int minimumArray(int arr[][3], const int ROW, const int COL) 
{
    int minValue = arr[0][0];

    for (int i = 0; i < ROW; ++i)
    {
        for(int j = 1; j < COL; ++j)
        {
            if (arr[i][j] < minValue) 
            {
                minValue = arr[i][j];
            }
        }
    }
    return minValue;
}

int maximumArray(int arr[][5], const int ROW, const int COL)
{
    int maxValue = arr[0][0];

    for (int i = 0; i < ROW; ++i)
    {
        for (int j = 1; j < COL; ++j)
        {
            if (arr[i][j] > maxValue)
            {
                maxValue = arr[i][j];
            }
        }
    }
    return maxValue;
}

int main()
{
    setlocale(LC_ALL, "Rus");

    const int ROW = 5;
    const int COL = 5;

    int arr[ROW][COL];

    fillArray(arr, ROW, COL);
    cout << "Наименьшое значение элемента " << minimumArray(arr, ROW, COL) << endl;
    cout << "Наибольшое значение элемента " << maximumArray(arr, ROW, COL) << endl;

    system("pause");
    return 0;
}