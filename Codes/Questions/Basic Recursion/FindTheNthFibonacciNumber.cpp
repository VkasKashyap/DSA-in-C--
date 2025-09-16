#include<iostream>
using namespace std;

//Find the Nth Fibonacci Number

int fibonacci(int n){
    if(n <= 1)  return n;

    return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
    int n;
    cin>>n;
    int fib = fibonacci(n);
    cout<<fib;

    return 0;
}