#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &arr, bool ascending)
{
    int size = arr.size();
    for (int i = 0; i < size - 1; i++)
    {
        int m = i;
        for (int j = i + 1; j < size; j++)
        {
            if (ascending ? (arr[j] < arr[m]) : (arr[j] > arr[m]))
            {
                m = j;
            }
        }
        if (m != i)
        {
            swap(arr[i], arr[m]);
        }
    }
}

int main()
{
    vector<int> A = {1, 1, 2, 3, 4, 5, 6, 7};
    vector<int> even, odd, sortedA;

    // Phân loại số chẵn và lẻ
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] % 2 == 0)
        {
            even.push_back(A[i]);
        }
        else
        {
            odd.push_back(A[i]);
        }
    }

    // Sắp xếp các số chẵn và lẻ
    selectionSort(even, true); // Sắp xếp tăng dần
    selectionSort(odd, false); // Sắp xếp giảm dần

    // Kết hợp lại dãy số
    int evenIndex = 0, oddIndex = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] % 2 == 0)
        {
            sortedA.push_back(even[evenIndex++]);
        }
        else
        {
            sortedA.push_back(odd[oddIndex++]);
        }
    }

    // In dãy số đã sắp xếp
    for (int i = 0; i < sortedA.size(); i++)
    {
        cout << sortedA[i] << " ";
    }
    cout << endl;

    return 0;
}
