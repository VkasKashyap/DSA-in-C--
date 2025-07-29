/*
Given an integer n denoting the Length of a line segment. 
You need to cut the line segment in such a way that the cut length of a 
line segment each time is either x , y or z. Here x, y, and z are integers.
After performing all the cut operations, your total number of cut segments
 must be maximum. Return the maximum number of cut segments possible.

Note: if no segment can be cut then return 0.
*/
#include<iostream>
using namespace std;

int maxCut(int n, int x, int y, int z){
    if(n==0)    return 0;
    if(n<0) return -1;
    int a = maxCut(n-x,x,y,z);
    int b = maxCut(n-y,x,y,z);
    int c = maxCut(n-z,x,y,z);

    return max(max(a,b) , max(a,c)) + 1;
}
int main(){
    int n;
    cout<<"Enter the length of the segment : ";
    cin>>n;
    cout<<"maximum cuts in the segements are : "<<maxCut(n,2,1,1);

    return 0;
}