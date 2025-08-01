#include <iostream>
#include <vector>

// Use the standard namespace to avoid prefixing with std::
using namespace std;

void insertionSort(vector<int>& nums) {
    int n = nums.size();
    // Start from the second element (the first element is trivially sorted).
    for (int i = 1; i < n; i++) {
        // The element to be inserted into the sorted portion.
        int key = nums[i];
        int j = i - 1;

        // Move elements of the sorted portion [0...i-1] that are greater
        // than the key one position ahead of their current position.
        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            j = j - 1;
        }
        // Place the key at its correct location in the sorted portion.
        nums[j + 1] = key;
    }
}

void printVector(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Main function to test the insertionSort implementation.
int main() {
    // Create a sample vector.
    vector<int> data = {12, 11, 13, 5, 6};

    // Show the original vector.
    cout << "Original vector: ";
    printVector(data);

    // Sort the vector.
    insertionSort(data);

    // Show the sorted vector.
    cout << "Sorted vector:   ";
    printVector(data);

    return 0; // Indicate successful execution.
}