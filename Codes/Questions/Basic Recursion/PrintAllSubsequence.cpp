#include<iostream>
#include<vector>
using namespace std;
void subsequence(int i, vector<int>& nums, vector<int> & ans){
    if(i == nums.size()){
        for(int num : ans){
            cout<<num<<" ";
        }
        cout<<endl;
        return;
    }
    ans.push_back(nums[i]);
    subsequence(i+1 , nums, ans);
    ans.pop_back();
    subsequence(i+1,nums,ans);
}
int main(){
    vector<int> nums = {1,2,3};
    vector<int> ans;
    subsequence(0,nums,ans);

    return 0;
}