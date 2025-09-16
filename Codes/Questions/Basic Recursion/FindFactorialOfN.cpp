#include<iostream>
using namespace std;

// FInd the Factorial of N

int fact(int n){
    if(n == 1)  return 1;
    return n*fact(n-1);
}

int main(){
    int n;
    cin>>n;
    int factorial = fact(n);
    cout<<"Factorial of "<<n<<" is "<<factorial<<".";
    return 0;
}