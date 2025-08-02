#include <iostream>
#include <vector> 
using namespace std;

bool check(vector<int>& nums) {
    int count = 0; // Counter for "break points"
    int n = nums.size(); 
    // A break point occurs when a current element is smaller than the previous one.
    for (int i = 1; i < n; i++) {
        if (nums[i - 1] > nums[i]) {
            count++; // Increment count if a disorder is found
        }
    }

    if (nums[n - 1] > nums[0]) {
        count++; // Increment count if the wrap-around is a break point
    }

    // An array is sorted and rotated if and only if it has 0 or 1 break points.
    // 0 break points means it's fully sorted (which is also a valid rotation).
    // 1 break point means it's sorted with exactly one rotation point.
    return count <= 1;
}


int main() {

    // Test Case 1: Sorted and rotated (e.g., [3,4,5,1,2])
    vector<int> nums1 = {3, 4, 5, 1, 2};
    cout << "Array: ";
    for (int x : nums1) cout << x << " ";
    cout << " -> Is Sorted and Rotated? " << (check(nums1) ? "Yes" : "No") << endl; // Expected: Yes

    return 0; // Indicate successful program execution
}