#include<iostream>
using namespace std;

void PrintNumbers(int n){
    if(n == 0)  return;
    cout<<n<<" ";
    PrintNumbers(n-1);
}

int main(){

    int n;
    cin>>n;
    PrintNumbers(n);

    return 0;
}