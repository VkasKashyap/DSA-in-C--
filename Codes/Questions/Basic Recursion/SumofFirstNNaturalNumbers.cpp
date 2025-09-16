#include<iostream>
using namespace std;

// Sum of First N Natural Numbers

int Sum(int n){
    if(n == 1)  return 1;
    
    return n+Sum(n-1);
}

int main(){
    int n;
    cin>>n;
    int sum = Sum(n);
    cout<<sum;

    return 0;
}