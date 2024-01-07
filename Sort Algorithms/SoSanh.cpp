#include <iostream>
#include <chrono>
#include <vector>
using namespace std;
using namespace std::chrono;

long long assignments = 0, comparisons = 0;

// cài đặt selection sort
void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            comparisons++;
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        swap(arr[min_idx], arr[i]);
        assignments += 3;
    }
}

// cài đặt heap sort
void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
        comparisons++;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
        comparisons++;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        assignments += 3;
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        assignments += 3;
        heapify(arr, i, 0);
    }
}

// cài đặt merge sort
void merge(vector<int> &arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        comparisons++;
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
        assignments++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
        assignments++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
        assignments++;
    }
}

void mergeSort(vector<int> &arr, int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

// cài đặt quick sort
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        comparisons++;
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
            assignments += 3;
        }
    }
    swap(arr[i + 1], arr[high]);
    assignments += 3;
    return (i + 1);
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void measureAndCompare(vector<int> arr, void (*sortFunction)(vector<int> &))
{
    vector<int> arrCopy = arr;
    auto start = high_resolution_clock::now();
    sortFunction(arrCopy);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken (Thoi gian so sanh): " << duration.count() << " microseconds" << endl;
    cout << "Comparisons (So phep so sanh): " << comparisons << endl;
    cout << "Assignments (So phep gan): " << assignments << endl;
    assignments = 0;
    comparisons = 0;
}

void mergeSortWrapper(vector<int> &arr)
{
    mergeSort(arr, 0, arr.size() - 1);
}

void quickSortWrapper(vector<int> &arr)
{
    quickSort(arr, 0, arr.size() - 1);
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "\nSelection Sort:" << endl;
    measureAndCompare(arr, selectionSort);

    cout << "\nHeap Sort:" << endl;
    measureAndCompare(arr, heapSort);

    cout << "\nMerge Sort:" << endl;
    measureAndCompare(arr, mergeSortWrapper);

    cout << "\nQuick Sort:" << endl;
    measureAndCompare(arr, quickSortWrapper);

    return 0;
}
