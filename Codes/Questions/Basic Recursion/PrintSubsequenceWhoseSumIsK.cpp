#include<iostream>
#include<vector>
using namespace std;

void function(int i, vector<int>& nums, int k, vector<int>& ans, int sum, int n){
    if(i == n){
        if(sum == k){
            for(int num : ans){
                cout<<num<<" ";
            }
            cout<<endl;
        }
        return;
    }
    ans.push_back(nums[i]);
    sum += nums[i];
    function(i+1,nums,k,ans,sum,n);
    ans.pop_back();
    sum -= nums[i];
    function(i+1,nums,k,ans,sum,n);
}

int main(){
    vector<int> nums = {1,2,1};
    int k = 2;
    int sum = 0;
    vector<int> ans;
    function(0,nums,k,ans,sum,nums.size());

    return 0;
}