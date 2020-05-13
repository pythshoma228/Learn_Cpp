#include <iostream>
using namespace std;

template <typename typeArr, typeValue>
void push_everywhere(typeArr *& arr, int& size, typeValue value, int element)
{
    typeArr* newArray = new typeArr[size + 1];
    int j = 0;

    for (int i = 0; i <= size; i++)
    {
        if (i == element)
        {
            newArray[i] = value;
            j++;
        }
        newArray[i + j] = arr[i];
    }
    size++;
    delete[] arr;
    arr = newArray;
}

template <typename T>
void pop_everywhere(T *& arr, int& size, int element)
{
    T* newArray = new T[size - 1];
    arr[element] = newArray[size];
    int j = 0;

    for (int i = 0; i < size; i++)
    {
        if (i == element)
        {
            newArray[i] = arr[i + 1];
            j++;
        }
        newArray[i] = arr[i + j];
    }
    size--;
    delete[] arr;
    arr = newArray;
}

int main()
{
    setlocale(LC_ALL, "Rus");

    int size = 5;
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 10; // make new elements
    }
    for (int i = 0; i < size; i++) { cout << arr[i] << "\t"; } // show array

    cout << endl;
    push_everywhere(arr, size, 12, 3); //enter new elements
    for (int i = 0; i < size; i++) { cout << arr[i] << "\t"; }

    cout << endl;
    pop_everywhere(arr, size, 3); //delete new elements
    for (int i = 0; i < size; i++) { cout << arr[i] << "\t"; }

    delete[] arr;
    return 0;
}
