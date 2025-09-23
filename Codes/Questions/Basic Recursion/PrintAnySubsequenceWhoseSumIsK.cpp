#include<iostream>
#include<vector>
using namespace std;

bool function(vector<int>& nums, int i, int k, vector<int> ans, int sum, int n){
    if(i == n){
        if(sum == k){
            for(int num : ans){
                cout<<num<<" ";
            }
            return true;
        }
        return false;
    }
    ans.push_back(nums[i]);
    sum += nums[i];
    if(function(nums,i+1,k,ans,sum,n) == true)  return true;
    ans.pop_back();
    sum -= nums[i];
    if(function(nums,i+1,k,ans,sum,n) == true)  return true;

    return false;
}

int main(){
    vector<int> nums = {1,2,3,4,5};
    int k = 8;
    int sum = 0;
    vector<int> ans;
    function(nums,0,k,ans,sum,nums.size());

    return 0;
}