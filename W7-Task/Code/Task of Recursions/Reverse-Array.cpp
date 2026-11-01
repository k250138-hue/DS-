#include<iostream>
#include<string.h>
using namespace std;

void reverseArr(int arr[], int left, int right) {
    if (left >= right)
        return;

    swap(arr[left], arr[right]);
    reverseArr(arr, left + 1, right - 1);
}

// call: reverseArr(arr, 0, size - 1);



int main(){

int arr[] = {1, 2, 3, 4, 5};
int n = sizeof(arr) / sizeof(arr[0]);

reverseArr(arr,0,n-1);
for(int i=0;i<n;i++){
    cout<<arr[n]<<" ";
}
return 0;
}