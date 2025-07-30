// Include necessary libraries
#include<iostream>
#include<vector>
#include<algorithm> // Required for std::sort

// Use the standard namespace
using namespace std;

// Function to find all triplets that sum to a target value
vector<vector<int>> tripletSum(vector<int>& nums, int Target){
    // Vector to store the resulting triplets
    vector<vector<int>> ans;
    // Get the size of the input array
    int n = nums.size();

    // First loop to select the first element
    for(int i = 0 ; i < n ; i++){
        // Second loop to select the second element
        for(int j = i+1 ; j < n ; j++){
            // Third loop to select the third element (bug fixed here: k < n)
            for(int k = j+1 ; k < n ; k++){
                // Check if the sum of the three elements equals the target
                if(nums[i] + nums[j] + nums[k] == Target){
                    // Create a temporary vector to hold the triplet
                    vector<int> temp;
                    // Add the three elements to the temp vector
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    // Sort the individual triplet for consistent ordering
                    sort(temp.begin(), temp.end());
                    // Add the sorted triplet to the answer list
                    ans.push_back(temp);
                }
            }
        }
    }
    // Sort the final list of triplets
    sort(ans.begin(), ans.end());
    // Return the result
    return ans;
}

// Main function to demonstrate the tripletSum function
int main() {
    // Create a sample vector of numbers
    vector<int> arr = {1, 2, 3, 4, 5, 6, 0};
    // Set the target sum
    int targetValue = 6;

    // Call the function to find the triplets
    vector<vector<int>> result = tripletSum(arr, targetValue);

    // Print the output
    cout << "Triplets that sum to " << targetValue << ":" << endl;
    
    // Check if any triplets were found
    if (result.empty()) {
        cout << "No triplets found." << endl;
    } else {
        // Loop through the result and print each triplet
        for (const auto& triplet : result) {
            cout << "{" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "}" << endl;
        }
    }

    // Indicate successful execution
    return 0;
}