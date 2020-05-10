#include <iostream>
using namespace std;

void fillArray(double arr[], int size);
void showArray(double arr[], int size);
void cleanArray(double arr[], int size);


inline void makePlace()
{
    int choice;
    int size;
    cout << "Enter the amount of elements" << endl;
    cin >> size;
    double* arr = new double[size];
    double* parr = arr;
    fillArray(arr, size);

    cout << "There are some values" << endl;
    showArray(arr, size);
    cleanArray(arr, size);
link:

    cout << "Want to repeat? yes - 1, no - 0" << endl;
    cin >> choice;
    if (choice == 1)
        makePlace();

    if (choice == 0) { NULL; }

    else { goto link; } // link on line 20

}

void fillArray(double arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        arr[i] = 0.1 * (rand() % 50);
    }
}

void showArray(double arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << endl;
    }
}

void cleanArray(double arr[], int size)
{
    delete[] arr;
    arr = nullptr;
}

int main()
{
    setlocale(LC_ALL, "Rus");

    makePlace();


    system("pause");
    return 0;

}
