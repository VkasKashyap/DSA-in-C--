#include<iostream>
#include<vector>
#include<algorithm>

// Use the standard namespace to avoid prefixing with std::
using namespace std;

// Function to swap elements in pairs (1st with 2nd, 3rd with 4th, etc.)
void swapAlternateCorrect(vector<int>& nums){
    int n = nums.size();
    // Loop through the vector, taking two steps at a time
    for(int i = 0; i < n; i += 2){
        // Check if a pair exists to be swapped
        if(i + 1 < n){
            swap(nums[i], nums[i + 1]);
        }
    }
}

// Utility function to print all elements in the vector
void printArray(const vector<int>& nums){
    for(int val : nums){
        cout << val << " ";
    }
    cout << endl;
}

// Main driver function
int main(){
    // Initialize a sample vector of integers
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    // Call the function to modify the vector
    swapAlternateCorrect(nums);

    // Print the final, modified vector
    cout << "After swapping alternatively the array becomes: ";
    printArray(nums);

    return 0; // Indicate successful execution
}