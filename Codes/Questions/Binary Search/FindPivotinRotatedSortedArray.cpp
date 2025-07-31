#include<iostream>
#include<vector>
using namespace std;

// This function finds the pivot index in a rotated sorted array.
// The pivot is the index of the smallest element.
int pivot(vector<int>& nums){
    // Initialize start and end pointers for the search range.
    int start = 0;
    int end = nums.size()-1;

    // Perform binary search until the start and end pointers converge.
    while(start < end){
        // Calculate the middle index to prevent potential integer overflow.
        int mid = start + (end - start)/2;

        // Check if the middle element is in the first sorted line (larger values).
        if(nums[mid] >= nums[0]){
            // If so, the pivot must be in the right half of the array.
            start = mid + 1;
        }
        // Otherwise, the middle element is in the second sorted line (smaller values).
         else{
            // The pivot is in the left half, so we narrow the search from the end.
            end = mid;
        }
    }
    // The loop terminates when 'start' points to the smallest element.
    return start;
}


// Main function to test the pivot finding logic.
int main() {
    // Create a sample rotated sorted array.
    vector<int> arr = {7, 9, 10, 1, 2, 3};

    // Find the pivot index using the pivot function.
    int pivotIndex = pivot(arr);

    // Print the results.
    cout << "The array is: ";
    for(int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    cout << "The pivot element is " << arr[pivotIndex] << " at index " << pivotIndex << "." << endl;

    return 0; // Indicate successful execution.
}