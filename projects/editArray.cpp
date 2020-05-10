#include <iostream>
using namespace std;

void push_in_front(int*& arr, int& size, int value)
{
    int* newArray = new int[size + 1];

    for (int i = 0; i < size; i++)
    {
        newArray[i + 1] = arr[i];
    }
    newArray[0] = value;
    ++size;
    delete[] arr;
    arr = newArray;
}

void push_in_mid(int*& arr, int& size, int value)
{
    int* newArray = new int[size + 1];
    int j = 0;

    for (int i = 0; i < size; i++)
    {
        if (i == ((size - 1) / 2))
        {
            j++;
            newArray[i] = value;
        }
        newArray[i + j] = arr[i];
    }
    size++;
    delete[] arr;
    arr = newArray;
}


void pop_in_front(int*& arr, int& size)
{
    int* newArray = new int[size];
    for (int i = 0; i < size; i++)
    {
        if (i == 0)
            continue;
        newArray[i - 1] = arr[i];
    }
    size--;
    delete[] arr;
    arr = newArray;
}

void pop_in_mid(int*& arr, int& size)
{
    int* newArray = new int[size];
    int j = 0;

    for (int i = 0; i < size; i++)
    {
        if (i == ((size - 1) / 2)) {
            newArray[i] = arr[i + 1];
            j++;
            continue;
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
        arr[i] = rand() % 10;
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
    push_in_front(arr, size, 55);
    for (int i = 0; i < size; i++) { cout << arr[i] << "\t"; }

    cout << endl;
    pop_in_front(arr, size);
    for (int i = 0; i < size; i++) { cout << arr[i] << "\t"; }

    cout << endl;
    push_in_mid(arr, size, 157);
    for (int i = 0; i < size; i++) { cout << arr[i] << "\t"; }

    cout << endl;
    pop_in_mid(arr, size);
    for (int i = 0; i < size; i++) { cout << arr[i] << "\t"; }

    delete[] arr;
    return 0;

}
