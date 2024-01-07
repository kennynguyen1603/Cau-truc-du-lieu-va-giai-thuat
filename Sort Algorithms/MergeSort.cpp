#include <iostream>
#include <iomanip>
using namespace std;

// chia mảng thành 2 mảng con đã sắp xếp và trộn 2 mảng con đã sắp xếp
void merge(int *arr, int low, int mid, int high) // arr là mảng, low là chỉ số phần tử đầu, mid là chỉ số phần tử giữa, high là chỉ số phần tử cuối
{
    int *temp = new int[high - low + 1]; // tạo mảng tạm
    int i = low, j = mid + 1, k = 0;     // i là chỉ số phần tử đầu mảng con bên trái, j là chỉ số phần tử đầu mảng con bên phải, k là chỉ số phần tử đầu mảng tạm
    // trộn 2 mảng con đã sắp xếp
    while (i <= mid && j <= high) // nếu cả 2 mảng con đều còn phần tử
    {
        // if (arr[i] > arr[j]) // nếu muốn sắp xếp giảm dần thì đổi dấu > thành <
        if (arr[i] < arr[j])
            // temp[k] = arr[i];
            // k++;
            // i++;
            // tương đương với cách viết dưới
            temp[k++] = arr[i++]; // nếu phần tử mảng con bên trái nhỏ hơn phần tử mảng con bên phải thì đưa phần tử mảng con bên trái vào mảng tạm
        else
            temp[k++] = arr[j++]; // nếu phần tử mảng con bên phải nhỏ hơn phần tử mảng con bên trái thì đưa phần tử mảng con bên phải vào mảng tạm
    }
    while (i <= mid) // nếu mảng con bên trái còn phần tử thì đưa hết vào mảng tạm
        temp[k++] = arr[i++];
    while (j <= high) // nếu mảng con bên phải còn phần tử thì đưa hết vào mảng tạm
        temp[k++] = arr[j++];
    for (int i = low; i <= high; i++) // đưa mảng tạm vào mảng
        arr[i] = temp[i - low];       // i - low là chỉ số phần tử đầu mảng tạm
    delete[] temp;                    // xóa mảng tạm
}

void mergeSort(int *arr, int low, int high) // arr là mảng, low là chỉ số phần tử đầu, high là chỉ số phần tử cuối
{
    if (low < high)
    {
        int mid = (low + high) / 2;    // chia mảng thành 2 mảng con
        mergeSort(arr, low, mid);      // sắp xếp mảng con bên trái
        mergeSort(arr, mid + 1, high); // sắp xếp mảng con bên phải
        merge(arr, low, mid, high);    // trộn 2 mảng con đã sắp xếp
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int *arr = new int[n]; // tạo mảng động
    cout << "Enter elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }
    mergeSort(arr, 0, n - 1);
    cout << "Sorted array:" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << setw(8);
    delete[] arr;
    return 0;
}