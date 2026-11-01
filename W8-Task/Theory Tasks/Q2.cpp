
#include <iostream>
using namespace std;

class Date
{
public:
    int day, month, year;

    void input()
    {
        cout << "Enter day: ";
        cin >> day;

        cout << "Enter month: ";
        cin >> month;

        cout << "Enter year: ";
        cin >> year;
    }

    void display()
    {
        if (day < 10)
            cout << "0";
        cout << day << "/";

        if (month < 10)
            cout << "0";
        cout << month << "/" << year;
    }
};

int compare(Date a, Date b)
{
    if (a.year < b.year)
        return 1;

    if (a.year > b.year)
        return 0;

    if (a.month < b.month)
        return 1;

    if (a.month > b.month)
        return 0;

    if (a.day < b.day)
        return 1;

    return 0;
}

void merge(Date arr[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = 0;

    Date temp[100];

    while (i <= mid && j <= high)
    {
        if (compare(arr[i], arr[j]))
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

void mergeSort(Date arr[], int low, int high)
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
    Date dates[100];
    int n;

    cout << "Enter number of dates (at least 5): ";
    cin >> n;

    if (n < 5 || n > 100)
    {
        cout << "Please enter between 5 and 100 dates.";
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter date " << i + 1 << ":\n";
        dates[i].input();
    }

    cout << "\nOriginal Dates:\n";

    for (int i = 0; i < n; i++)
    {
        dates[i].display();
        cout << endl;
    }

    mergeSort(dates, 0, n - 1);

    cout << "\nSorted Dates (Ascending):\n";

    for (int i = 0; i < n; i++)
    {
        dates[i].display();
        cout << endl;
    }

    return 0;
}
