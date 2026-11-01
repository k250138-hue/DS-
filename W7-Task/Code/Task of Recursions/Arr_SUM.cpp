#include <iostream>
using namespace std;

int arrSum(int arr[], int n)
{
    if (n < 0)
    {
        return 0;
    }

    return arr[n] + arrSum(arr, n - 1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};

    int n = sizeof(arr) / sizeof(arr[0]);

    int sum = arrSum(arr, n - 1);

    cout << "Sum = " << sum;

    return 0;
}