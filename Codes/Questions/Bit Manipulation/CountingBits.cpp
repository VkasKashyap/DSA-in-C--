/*
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), 
ans[i] is the number of 1's in the binary representation of i.

Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
*/
#include<iostream>
#include<vector>
using namespace std;

vector<int> countingBits(int n){
    vector<int> result(n+1);
    if(n == 0)  return result;
    result[0] = 0;
    for(int i=1 ; i<=n ; i++){
        if(i%2 != 0){
            result[i] = result[i/2] + 1;
        }
        else{
            result[i] = result[i/2];
        }
    }
    return result;
}
void print(vector<int>& nums){
    for(int num : nums){
        cout<<num<<" ";
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> ans;
    ans = countingBits(n);
    print(ans);

    return 0;
}