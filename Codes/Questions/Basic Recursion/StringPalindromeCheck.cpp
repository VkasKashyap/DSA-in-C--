#include<iostream>
using namespace std;

bool palindrome(string s , int left, int right){
    if(left >= right){
        return true;
    }
    if(s[left] != s[right]){
        return false;
    }
    return palindrome(s, left++ , right--);
}

int main(){
    string s;
    cin>>s;
    
    cout<<palindrome(s,0,s.length()-1);
}