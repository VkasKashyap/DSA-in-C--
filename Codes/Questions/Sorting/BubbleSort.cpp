#include <iostream>
#include <vector>
#include <algorithm> // For std::swap

using namespace std;

void bubbleSort(vector<int>& nums) {
    int n = nums.size();
    bool swapped; // Flag to detect if a swap happened in a pass.

    // Outer loop for passes through the array.
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        // Inner loop for comparing adjacent elements.
        // The last 'i' elements are already in place.
        for (int j = 0; j < n - i - 1; j++) {
            // If the current element is greater than the next, swap them.
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
                swapped = true; // A swap occurred in this pass.
            }
        }
        // If no swaps occurred, the array is sorted.
        if (!swapped) {
            break;
        }
    }
}

void printVector(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Main function to test the bubbleSort implementation.
int main() {
    // Create a sample vector.
    vector<int> data = {64, 34, 25, 12, 22, 11, 90};

    // Show the original vector.
    cout << "Original vector: ";
    printVector(data);

    // Sort the vector.
    bubbleSort(data);

    // Show the sorted vector.
    cout << "Sorted vector:   ";
    printVector(data);

    return 0; // Indicate successful execution.
}