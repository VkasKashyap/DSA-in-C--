#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void subsetSum(vector<int>& nums, int index, int sum, vector<int>& ans){
    if(index == nums.size()){
        ans.push_back(sum);
        return;
    }
    subsetSum(nums,index+1,sum+nums[index],ans);    
    subsetSum(nums,index+1,sum,ans);
}

void print(vector<int> ans){
    sort(ans.begin(), ans.end());
    cout<<"{";
    for(int num : ans){
        cout<<num<<" ";
    }
    cout<<"}";
}

int main(){
    vector<int> nums = {3,1,2};
    vector<int> ans;
    subsetSum(nums,0,0,ans);
    print(ans);

    return 0;
}
