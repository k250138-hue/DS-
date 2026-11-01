#include <iostream>
using namespace std;

int BinarySearch(int arr[], int left, int right, int key) {
    if (left > right) {
        return -1;              // not found
    }
    int mid = left + (right - left) / 2;
    if (arr[mid] == key) {
        return mid;             // return the index
    }
    if (arr[mid] < key) {
        return BinarySearch(arr, mid + 1, right, key);
    } else {
        return BinarySearch(arr, left, mid - 1, key);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    cout << BinarySearch(arr, 0, n - 1, 2);   // prints 1
    return 0;
}