// Include necessary libraries
#include<iostream>
#include<vector>

// Use the standard namespace
using namespace std;

/**
 * Finds the first occurrence of an element in a sorted vector.
 * @return The index of the first occurrence, or -1 if not found.
 */
int firstOccurance(vector<int>& nums, int element){
    // Initialize search boundaries and answer
    int start = 0;
    int end = nums.size() - 1;
    int ans = -1;

    // Perform binary search
    while(start <= end){
        // Calculate mid-point safely
        int mid = start + (end-start)/2;

        // If a match is found
        if(nums[mid] == element){
            // Store the index and search in the left half for an earlier occurrence
            ans = mid;
            end = mid - 1;
        }
        // If mid is greater, search left
        else if(nums[mid] > element){
            end = mid-1;
        }
        // If mid is smaller, search right
        else{
            start = mid+1;
        }
    }
    // Return the final answer
    return ans;
}

/**
 * Finds the last occurrence of an element in a sorted vector.
 * @return The index of the last occurrence, or -1 if not found.
 */
int lastOccurance(vector<int>& nums, int element){
    // Initialize search boundaries and answer
    int start = 0;
    int end = nums.size()-1;
    int ans = -1;

    // Perform binary search
    while(start <= end){
        // Calculate mid-point safely
        int mid = start + (end-start)/2;

        // If a match is found
        if(nums[mid] == element){
            // Store the index and search in the right half for a later occurrence
            ans = mid;
            start = mid + 1;
        }
        // If mid is smaller, search right
        else if(nums[mid] < element){
            start = mid + 1;
        }
        // If mid is greater, search left
        else{
            end = mid-1;
        }
    }
    // Return the final answer
    return ans;
}

// Main function to demonstrate the code
int main() {
    // A sorted vector with duplicate elements
    vector<int> nums = {1, 3, 5, 5, 5, 5, 67, 123, 125};
    // The element to find
    int element_to_find = 5;

    // Find the first and last occurrences
    int first_index = firstOccurance(nums, element_to_find);
    int last_index = lastOccurance(nums, element_to_find);

    // Print the results
    cout << "The sorted array is: {1, 3, 5, 5, 5, 5, 67, 123, 125}" << endl;
    cout << "Searching for element: " << element_to_find << endl;
    cout << "First occurrence is at index: " << first_index << endl;
    cout << "Last occurrence is at index: " << last_index << endl;

    // Calculate and print the total count
    if (first_index != -1) {
        int count = last_index - first_index + 1;
        cout << "Total occurrences: " << count << endl;
    }

    // Indicate successful execution
    return 0;
}
