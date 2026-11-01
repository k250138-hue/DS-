#include<iostream>
#include<string.h>
using namespace std;

int Minimum(int arr[],int n){
if(n==0){
    return arr[0];
}
int min =Minimum(arr,n-1);
if(arr[n]<min){
    return arr[n];
}
return min;
}

int Sum(int arr[], int n) {
    if (n == 0)
        return arr[0];      // base case?

    int smaller = Sum(arr, n - 1);
    return smaller+arr[n];          // combine?
}

int main(){
int n;
cout<<"Enter the size of Array:";
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
    cout<<"Enter the Element"<<i+1<<":";
    cin>>arr[i];
}
int min;
min=Minimum(arr,n-1);
cout<<min;
return 0;
}