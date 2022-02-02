#include <iostream>
using namespace std;

int swap(int *a, int *b)
{
    int temp;
    temp = *b;
    *b = *a;
    *a = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void QuickSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int pi = partition(arr, l, h);
        QuickSort(arr, l, pi - 1);
        QuickSort(arr, pi + 1, h);
    }
}

void PrintArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int arr[7] = {6, 3, 9, 5, 2, 8, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted Array: \n";
    PrintArray(arr, size);

    QuickSort(arr, 0, size - 1);
    cout << "Sorted Array:\n";
    PrintArray(arr, size);
    return 0;
}
