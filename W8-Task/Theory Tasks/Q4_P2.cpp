
#include <iostream>
using namespace std;

int priority(string designation)
{
    if (designation == "CEO")
        return 6;
    else if (designation == "CTO")
        return 5;
    else if (designation == "CFO")
        return 4;
    else if (designation == "VP")
        return 3;
    else if (designation == "MGR")
        return 2;
    else if (designation == "EMP")
        return 1;

    return 0;
}

int partition(string arr[], int low, int high)
{
    int pivot = priority(arr[high]);
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (priority(arr[j]) > pivot)
        {
            i++;

            string temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    string temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(string arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main()
{
    string arr[] = {"EMP", "CFO", "MGR", "EMP",
                    "VP", "CTO", "MGR", "CEO"};

    int n = 8;

    cout << "Before Sorting: ";

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    quickSort(arr, 0, n - 1);

    cout << "\nAfter Sorting: ";

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
