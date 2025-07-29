#include<iostream>
#include<vector>
using namespace std;

void moveZeroes(vector<int>& nums){
    int i = 0;
    for(int j = 0; j < nums.size() ; j++){
        if(nums[j] != 0){
            swap(nums[j] , nums[i]);
            i++;
        }
    }
}

int main(){
    vector<int> nums = {1,2,3,4,5,6,7,0,0,9,0};
    moveZeroes(nums);
    for(int val : nums){
        cout<<val<<" ";
    }
    cout<<endl;

    return 0;
}