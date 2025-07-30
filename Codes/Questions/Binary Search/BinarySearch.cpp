// Include necessary libraries
#include<iostream>
#include<vector>

// Use the standard namespace
using namespace std;

// Function to perform binary search on a sorted vector
int binarySearch(vector<int>& nums, int key){
    // Get the size of the vector
    int n = nums.size();
    // Initialize start pointer
    int start = 0;
    // Initialize end pointer
    int end = n-1;

    // Loop until the start pointer crosses the end pointer
    while(start <= end){
        // Calculate the middle index to avoid overflow
        int mid = start + (end - start)/2;

        // If the middle element is the key, return its index
        if(nums[mid] == key){
            return mid;
        }
        // If the key is greater, search in the right half
        if(key > nums[mid]){
            start = mid + 1;
        }
        // If the key is smaller, search in the left half
        else{
            end = mid - 1;
        }
    }
    // Return -1 if the key is not found in the vector
    return -1;
}

// Main function to test the binary search
int main() {
    // Create a sorted vector of integers
    vector<int> sorted_nums = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    // Define the key to search for
    int key_to_find = 23;

    // Call the binary search function
    int result_index = binarySearch(sorted_nums, key_to_find);

    // Check the result and print the output
    if (result_index != -1) {
        cout << "Element " << key_to_find << " found at index: " << result_index << endl;
    } else {
        cout << "Element " << key_to_find << " not found in the array." << endl;
    }

    // Indicate successful program execution
    return 0;
}
