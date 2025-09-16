#include<iostream>
using namespace std;
// Find the Sum of Digits of the Number

int sumDigits(int n){
    if (n == 0) return 0;
    return (n%10 + sumDigits(n/10));
}

int main(){
    int n;
    cin>>n;
    int sum = sumDigits(n);
    cout<<sum;

    return 0;
}