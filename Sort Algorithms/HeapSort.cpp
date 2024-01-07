#include <iostream>
#include <iomanip>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// heapsort
void heapify(int *arr, int n, int i) // n là số phần tử của mảng, i là gốc
{
    int largest = i;       // khởi tạo largest là gốc
    int left = 2 * i + 1;  // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // nếu left lớn hơn gốc
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // nếu right lớn hơn largest
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // nếu largest không phải là gốc
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // đệ quy lại hàm heapify
        heapify(arr, n, largest);
    }
}

void heapSort(int *arr, int n) // n là số phần tử của mảng
{
    int k = n / 2 - 1; // từ k trở về 0 là các gốc của các cây con có nốt lá, nên ta chỉ cần xây dựng heap từ các gốc này
    // xây dựng max heap
    for (int i = k; i >= 0; i--)
        heapify(arr, n, i);

    // trích xuất từng phần tử từ heap
    for (int i = n - 1; i >= 0; i--)
    {
        // di chuyển root đến cuối mảng
        swap(arr[0], arr[i]);

        // gọi heapify trên cấu trúc heap đã sắp xếp
        heapify(arr, i, 0);
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int *arr = new int[n]; // tạo mảng động
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {

        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }
    heapSort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << setw(8);
    return 0;
}