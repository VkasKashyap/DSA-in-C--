#include<iostream>
using namespace std;

int stairs(int n){
    if(n==1)    return 1;
    if(n==2)    return 2;

    return stairs(n-1)+stairs(n-2);
}

int main(){
    int n;
    cout<<"Enter no. of steps in the stairs : ";
    cin>>n;
    cout<<"possible way to climb the stair are : "<<stairs(n);

    return 0;
}