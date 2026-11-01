#include<iostream>
#include<string.h>
using namespace std;

int Minimum(int arr[],int n,int max){
    if(n<0){
    return max;
}
if(arr[n]>max){
    max=arr[n];
}
return Minimum(arr,n-1,max);

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
int max=arr[0];
max=Minimum(arr,n-1,max);
cout<<max;
return 0;
}