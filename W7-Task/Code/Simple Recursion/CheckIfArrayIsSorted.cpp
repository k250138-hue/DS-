#include <iostream>
using namespace std;

// bool IsArraySorted(int arr[], int index, int n) {
//     if (index >= n - 1) {
//         return true;
//     }
//     if (arr[index] > arr[index + 1]) {
//         return false;
//     }
//     return IsArraySorted(arr, index + 1, n);
// }

bool IsArraySorted(int arr[], int n) {
    if (n==0 || n==1) {
        return true;
    }
    if (arr[n-1] < arr[n-2]) {
        return false;
    }
    return IsArraySorted(arr,n-1);
}



int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    cout << (IsArraySorted(arr, n) ? "Array Sorted" : "Not");
    return 0;
}