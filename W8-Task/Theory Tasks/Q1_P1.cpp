
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

int partition(Date arr[], int low, int high)
{
    Date pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (compare(arr[j], pivot))
        {
            i++;

            Date temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    Date temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(Date arr[], int low, int high)
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

    quickSort(dates, 0, n - 1);

    cout << "\nSorted Dates (Ascending):\n";

    for (int i = 0; i < n; i++)
    {
        dates[i].display();
        cout << endl;
    }

    return 0;
}
