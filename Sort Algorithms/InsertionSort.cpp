#include <iostream>
#include <iomanip>
using namespace std;

void insertionSort(int *arr, int n) // arr la mang can sap xep, n la so phan tu cua mang
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = arr[i]; // chon phan tu arr[i] de chen vao day da sap xep
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << setw(10);
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int *arr = new int[n]; // tao mang dong
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }
    insertionSort(arr, n);
    cout << "Sorted array: ";
    printArray(arr, n);
    delete[] arr;
    return 0;
}