#include<iostream>
#include<vector>
using namespace std;

// Finds the duplicate element in an array of size n containing numbers from 1 to n-1.
int findDuplicates(vector<int>& nums){
    // Initialize the answer variable.
    int ans = 0;
    int n = nums.size();
    
    // First, XOR all the elements in the array.
    for(int i = 0 ; i < n ; i++){
        ans = ans ^ nums[i];
    }
    
    // Then, XOR with all numbers from 1 to n-1.
    for(int i = 1 ; i < n ; i++){
        // The XOR property cancels out all unique numbers.
        ans = ans ^ i;
    }
    
    // The remaining value is the duplicate element.
    return ans;
}

// Main driver function.
int main(){
    // Create a sample vector where '2' is the duplicate.
    vector<int> nums = {5,1,2,3,4,2};
    
    // Call the function and print the result.
    cout<<"duplicate element is : "<<findDuplicates(nums);

    return 0;
}