#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

// Finds all duplicate numbers in a given array.
vector<int> findDuplicates(vector<int>& nums){
    // Vector to store the duplicate numbers.
    vector<int> result;
    int n = nums.size();

    // Iterate through the array.
    for(int i = 0 ; i < n ; ++i){
        // Get the positive value of the current number.
        int num = abs(nums[i]);
        // Calculate the index corresponding to the number.
        int index = num-1;

        // If the value at the index is already negative, it's a duplicate.
        if(nums[index] < 0){
            result.push_back(num);
        }
        // Otherwise, mark it as seen by making it negative.
        else{
            nums[index] = -nums[index];
        }
    }
    // Return the list of duplicates.
    return result;
}

// Helper function to print a vector.
void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i] << (i == vec.size() - 1 ? "" : ",");
    }
    cout << "]" << endl;
}

// Main function for testing.
int main() {

    // Example 1
    vector<int> nums1 = {4, 3, 2, 7, 8, 2, 3, 1};
    cout << "Input: [4,3,2,7,8,2,3,1]" << endl;
    vector<int> result1 = findDuplicates(nums1);
    cout << "Output: ";
    printVector(result1); // Expected: [2,3]
    cout << "--------------------" << endl;

    // Example 2
    vector<int> nums2 = {1, 1, 2};
    cout << "Input: [1,1,2]" << endl;
    vector<int> result2 = findDuplicates(nums2);
    cout << "Output: ";
    printVector(result2); // Expected: [1]
    cout << "--------------------" << endl;

    // Example 3
    vector<int> nums3 = {1};
    cout << "Input: [1]" << endl;
    vector<int> result3 = findDuplicates(nums3);
    cout << "Output: ";
    printVector(result3); // Expected: []
    cout << "--------------------" << endl;

    return 0;
}