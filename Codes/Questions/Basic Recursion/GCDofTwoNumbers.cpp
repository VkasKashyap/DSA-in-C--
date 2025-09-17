#include<iostream>
using namespace std;
//Find The GCD(HCF) of Two Numbers

int GCD(int a, int b){
    if(b==0)    return a;
    return GCD(b,a%b);     
}
/*
The gcd function uses the Euclidean algorithm, 
which states that the GCD of two numbers a and b is the same as the GCD of b and a % b.
*/

int main(){
    int a,b;
    cin>>a>>b;
    cout<<GCD(a,b);

    return 0;
}