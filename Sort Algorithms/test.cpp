#include <iostream>
#include <iomanip>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
// chọn chốt là phần tử ở giữa của mảng
int partition(int *arr, int low, int high)
{
    int pivot = arr[(low + high) / 2]; // chọn chốt là phần tử ở giữa của mảng
    int i = low, j = high;
    while (i <= j)
    {
        while (arr[i] < pivot) // tìm phần tử >= pivot
            i++;
        while (arr[j] > pivot) // tìm phần tử <= pivot
            j--;
        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return i;
}

void quickSort(int *arr, int low, int high)
{
    int index = partition(arr, low, high);
    if (low < index - 1) // nếu còn phần tử bên trái chốt
        quickSort(arr, low, index - 1);
    if (index < high) // nếu còn phần tử bên phải chốt
        quickSort(arr, index, high);
}

// chọn chốt là phần tử ở giữa của mảng
int partition2(int *arr, int low, int high)
{
    int pivot = arr[(low + high) / 2]; // chọn chốt là phần tử ở giữa của mảng
    int i = low, j = high;
    while (i <= j)
    {
        while (arr[i] < pivot) // tìm phần tử >= pivot
            i++;
        while (arr[j] > pivot) // tìm phần tử <= pivot
            j--;
        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return i;
}

void quickSort2(int *arr, int low, int high)
{
    int index = partition2(arr, low, high);
    if (low < index - 1) // nếu còn phần tử bên trái chốt
        quickSort2(arr, low, index - 1);
    if (index < high) // nếu còn phần tử bên phải chốt
        quickSort2(arr, index, high);
}

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << setw(8);
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
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: ";
    printArray(arr, n);
    cout << endl;
    int max = arr[n - 1];
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == max)
            count++;
    }
    cout << "Max cua mang la: " << max << endl;
    cout << "So lan xuat hien cua " << max << " la: " << count << endl;
    delete[] arr;
    return 0;
}
