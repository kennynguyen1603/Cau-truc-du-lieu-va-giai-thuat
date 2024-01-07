#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
// selectionSort: sắp xếp mảng arr có n phần tử
void selectionSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++) // duyệt n - 1 lần
    {
        int minIndex = i; // giả sử phần tử đầu tiên là nhỏ nhất
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIndex])  // nếu phần tử thứ j nhỏ hơn phần tử nhỏ nhất
                minIndex = j;            // cập nhật lại chỉ số phần tử nhỏ nhất
        if (minIndex != i)               // nếu phần tử nhỏ nhất không phải là phần tử đầu tiên
            swap(arr[i], arr[minIndex]); // đổi chỗ phần tử nhỏ nhất với phần tử đầu tiên
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
    selectionSort(arr, n);
    cout << "Sorted array: ";
    printArray(arr, n);
    delete[] arr;
    return 0;
}