#include<iostream>
#include<vector>
using namespace std;
int function(vector<int>& nums, int k, int i, int sum, int n){
    if(i == n){
        if(sum == k){
            return 1;
        }
        return 0;
    }
    sum += nums[i];
    int l = function(nums,k,i+1,sum,n);
    sum -= nums[i];
    int r = function(nums,k,i+1,sum,n);

    return l+r;
}

int main(){
    vector<int> nums = {1,2,3,4,5};
    int k = 8;
    int sum = 0;
    cout<<function(nums,k,0,sum,nums.size());

    return 0;

}
