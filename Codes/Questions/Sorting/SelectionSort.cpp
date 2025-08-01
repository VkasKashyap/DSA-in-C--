#include<iostream>
#include<vector>

using namespace std;

// Sorts a vector using the Selection Sort algorithm.
void selectionSort(vector<int>& nums) {
    int n = nums.size();
    // Iterate through the array. The last element will be sorted by default.
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // Assume the current element is the minimum.

        // Find the minimum element in the unsorted part of the array.
        for (int j = i + 1; j < n; j++) {
            if (nums[j] < nums[minIndex]) {
                minIndex = j; // Update the index of the minimum element.
            }
        }
        // Swap the found minimum element with the first element of the unsorted part.
        swap(nums[minIndex], nums[i]);
    }
}

// Helper function to print a vector.
void printVector(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

// Main function to run the code.
int main() {
    // Sample input vector.
    vector<int> data = {64, 25, 12, 22, 11};

    // Print the original vector.
    cout << "Original array: ";
    printVector(data);

    // Call the sorting function.
    selectionSort(data);

    // Print the sorted vector.
    cout << "Sorted array:   ";
    printVector(data);

    return 0;
}