#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int *arr, int n) // arr: mảng cần sắp xếp, n: số phần tử của mảng
{
    for (int i = 0; i < n - 1; i++) // n - 1 lần
    {
        for (int j = n - 1; j > i; j--) // n - 1 lần
        {
            if (arr[j] < arr[j - 1])
                swap(arr[j], arr[j - 1]);
        }
    }
}

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << "\t";
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int *arr = new int[n]; // tạo mảng động
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }
    bubbleSort(arr, n);
    cout << "Sorted array: ";
    printArray(arr, n);
    delete[] arr;
    return 0;
}