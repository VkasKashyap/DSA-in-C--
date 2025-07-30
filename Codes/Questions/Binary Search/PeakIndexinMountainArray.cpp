// Include necessary libraries
#include<iostream>
#include<vector>

// Use the standard namespace
using namespace std;

/**
 * Finds the index of the peak element in a mountain array.
 * A mountain array is one that first increases and then decreases.
 * @return The index of the peak element.
 */
int peakIndex(vector<int>& nums){
    // Initialize start and end pointers for the search range
    int start = 0;
    int end = nums.size() - 1;

    // Loop until start and end pointers meet
    while(start < end){
        // Calculate the middle index safely
        int mid = start + (end-start)/2;

        // If we are on the increasing part of the array, the peak is to the right
        if(nums[mid] < nums[mid+1]){
            start = mid + 1;
        }
        // If we are at the peak or on the decreasing part, the peak is at or to the left
        else{
            end = mid;
        }
    }
    // Start and end will meet at the peak index
    return start;
}

// Main function to demonstrate the peakIndex function
int main() {
    // Create a sample mountain array
    vector<int> mountain = {0, 10, 5, 2};

    // Call the function to find the peak index
    int peak = peakIndex(mountain);

    // Print the result
    cout << "Array: {0, 10, 5, 2}" << endl;
    cout << "The peak element is at index: " << peak << endl;
    cout << "The peak value is: " << mountain[peak] << endl;

    // Indicate successful execution
    return 0;
}