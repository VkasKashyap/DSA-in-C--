#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Checks if the frequency of each number in an array is unique.
bool UniqueOccurance(vector<int>& nums){
    // Sort the array to group identical numbers together.
    sort(nums.begin(),nums.end());
    
    // Vector to store the counts of each unique number.
    vector<int> v;
    int n = nums.size();
    
    // Iterate through the sorted array to find counts.
    for(int i=0;i<n;i++){
        int count = 1;
        // Count all consecutive occurrences of the current number.
        while(i+1<n && nums[i]==nums[i+1]){
            count ++;
            i++;
        }
        // Add the final count to the new vector.
        v.push_back(count);
    }
    
    // Sort the counts vector to easily find duplicates.
    sort(v.begin(), v.end());
    int s = v.size();
    
    // Check if any two adjacent counts are the same.
    for(int i=1;i < s;i++){
        if(v[i] == v[i-1]){
            // If a duplicate count is found, return false.
            return false;
        }
    }
    
    // If no duplicate counts were found, return true.
    return true;
}

// Main driver function.
int main(){
    // Sample input array.
    vector<int> nums = {-3,0,1,-3,1,1,1,-3,10,0};
    
    // Call the function and print the boolean result.
    if(UniqueOccurance(nums)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}