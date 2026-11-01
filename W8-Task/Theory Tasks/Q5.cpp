
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

void merge(string arr[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = 0;

    string temp[100];

    while (i <= mid && j <= high)
    {
        if (priority(arr[i]) > priority(arr[j]))
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }

        k++;
    }

    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (i = low, k = 0; i <= high; i++, k++)
    {
        arr[i] = temp[k];
    }
}

void mergeSort(string arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

int main()
{
    string arr[] = {"EMP", "CFO", "MGR", "EMP",
                    "VP", "CTO", "MGR", "CEO"};

    int n = 8;

    cout << "Before Sorting: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    mergeSort(arr, 0, n - 1);

    cout << "\nAfter Sorting: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
