#include<iostream>
#include<string.h>
using namespace std;

string ispalindrome(string a,int left,int right){
    if(a[left]!=a[right]){
        return "Not Palindrome";
    }
    if(left>=right){
        return "Palindrome";
    }
    return ispalindrome(a,left+1,right-1);

}


int main(){
string a="tenet";
cout<<ispalindrome(a,0,a.length()-1);

return 0;
}