#include<iostream>
using namespace std;

void printNumbers(int n, int i){
    if(i > n)  return;
    cout<<i<<" ";
    printNumbers(n,i+1);
}

int main(){
    printNumbers(10,1);
    cout<<endl;
    printNumbers(20,2);

    return 0;
}