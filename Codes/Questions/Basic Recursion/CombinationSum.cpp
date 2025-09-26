#include<iostream>
#include<vector>
using namespace std;

void function(vector<int>& nums, int target, vector<vector<int>>& ans, vector<int> ds, int index){
    if(index == nums.size()){
        if(target == 0){
            ans.push_back(ds);
        }
        return;
    }
    if(nums[index] <= target){
        ds.push_back(nums[index]);
        function(nums,target-nums[index],ans,ds,index);
        ds.pop_back();
    }
    function(nums,target,ans,ds,index+1);
}

int main(){
    vector<int> nums = {2,3,6,7};
    int target = 7;
    vector<vector<int>> ans;
    vector<int> ds;
    function(nums,target,ans,ds,0);
    cout<<"{";
    for(auto i : ans){
        cout<<"{";
        for(auto j : i){
            cout<<j<<",";
        }
        cout<<"}";
    }
    cout<<"}";

    return 0;
}