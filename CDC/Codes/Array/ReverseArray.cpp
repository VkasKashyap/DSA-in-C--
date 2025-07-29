#include<iostream>
#include<vector>
using namespace std;

void reverse(vector<int>& nums){
    int start = 0;
    int end = nums.size() - 1;
    while(start < end){
        swap(nums[start] , nums[end]);
        start++;
        end--;
    }
}

void printArray(vector<int>& nums){
    for(int num : nums){
        cout<< num <<" ";
    }
}

int main(){
    vector<int> nums = {10,15,20,-100};
    reverse(nums);
    cout<<"Reverse of the given array is : ";
    printArray(nums);

    return 0;
}