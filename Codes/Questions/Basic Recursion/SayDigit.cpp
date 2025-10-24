/*
given an number 123 
print one two three
*/
#include<iostream>
#include<vector>
using namespace std;

void sayDigit(int n , vector<string>& num){
    if(n == 0)  return;
    int digit = n%10;
    n = n/10;
    sayDigit(n,num);
    cout<<num[digit]<<" ";
}
int main(){
    vector<string> num = {"zero" , "one" , "two" , "three" , "four" , "five" , "six" , "seven" , "eight" , "nine"};
    int n;
    cin>>n;
    cout<<endl;
    sayDigit(n,num);
    return 0;
}