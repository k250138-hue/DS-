
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

void countingSort(int arr[], int n, int place)
{
    int output[100];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
    {
        int digit = (arr[i] / place) % 10;
        count[digit]++;
    }

    for (int i = 8; i >= 0; i--)
    {
        count[i] = count[i] + count[i + 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / place) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n)
{
    int max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    for (int place = 1; max / place > 0; place *= 10)
    {
        countingSort(arr, n, place);
    }
}

int main()
{
    string employees[] = {"EMP", "CFO", "MGR", "EMP",
                          "VP", "CTO", "MGR", "CEO"};

    int arr[100];
    int n = 8;

    cout << "Before Sorting: ";

    for (int i = 0; i < n; i++)
    {
        cout << employees[i] << " ";
        arr[i] = priority(employees[i]);
    }

    radixSort(arr, n);

    cout << "\nAfter Sorting: ";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == priority(employees[j]))
            {
                cout << employees[j] << " ";
                employees[j] = "";
                break;
            }   
        }
    }

    return 0;
}
