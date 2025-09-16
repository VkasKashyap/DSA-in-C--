#include<iostream>
using namespace std;
// Reverse the number
void Reverse(int n){
    if(n < 10){
        cout<<n;
        return;
    }
    else{
        cout<<n%10;
        Reverse(n/10);
    }
}
int main(){
    int n;
    cin>>n;
    Reverse(n);
    return 0;
}