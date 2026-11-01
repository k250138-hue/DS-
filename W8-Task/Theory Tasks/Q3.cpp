
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
// 0 digits right side par → multiply by \(1\)
// 1 digit → multiply by \(10\)
// 2 digits → multiply by \(100\)
// 3 digits → multiply by \(1000\)
// 4 digits → multiply by \(10000\)
    int getValue()
    {
        return year * 10000 + month * 100 + day;
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

int getMax(Date arr[], int n)
{
    int max = arr[0].getValue();

    for (int i = 1; i < n; i++)
    {
        if (arr[i].getValue() > max)
            max = arr[i].getValue();
    }

    return max;
}

void countingSort(Date arr[], int n, int place)
{
    Date output[100];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
    {
        int digit = (arr[i].getValue() / place) % 10;
        count[digit]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] = count[i] + count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i].getValue() / place) % 10;

        output[count[digit] - 1] = arr[i];

        count[digit]--;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

void radixSort(Date arr[], int n)
{
    int max = getMax(arr, n);

    for (int place = 1; max / place > 0; place = place * 10)
    {
        countingSort(arr, n, place);
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

    radixSort(dates, n);

    cout << "\nSorted Dates (Ascending):\n";

    for (int i = 0; i < n; i++)
    {
        dates[i].display();
        cout << endl;
    }

    return 0;
}
