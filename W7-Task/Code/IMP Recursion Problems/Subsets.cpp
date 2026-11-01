
#include <iostream>
using namespace std;

void powerSet(int arr[], int n, int index, int ans[], int size)
{
    if (index == n)
    {
        cout << "{ ";
        for (int i = 0; i < size; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "}" << endl;
        return;
    }

    powerSet(arr, n, index + 1, ans, size);

    ans[size] = arr[index];

    powerSet(arr, n, index + 1, ans, size + 1);
}

int main()
{
    int n;

    cout << "Enter the size of array: ";
    cin >> n;

    int arr[100];
    int ans[100];

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Power Set:" << endl;

    powerSet(arr, n, 0, ans, 0);

    return 0;
}
