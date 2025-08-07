#include<iostream>
#include<vector>

using namespace std;

// Function to find the intersection of two sorted vectors using a two-pointer approach
vector<int> intersection(vector<int>& nums1, vector<int> nums2){
    // Vector to store the resulting intersection
    vector<int> ans;
    // Get the size of the first vector
    int n = nums1.size();
    // Get the size of the second vector
    int m = nums2.size();
    // Initialize pointer for nums1
    int i = 0;
    // Initialize pointer for nums2
    int j = 0;

    // Loop while both pointers are within their vector's bounds.
    // This condition has been corrected to prevent out-of-bounds access.
    while(i < n && j < m){
        // If elements are equal, it's an intersection
        if(nums1[i] == nums2[j]){
            // Add the common element to the answer
            ans.push_back(nums1[i]);
            // Move both pointers forward
            i++;
            j++;
        }
        // If the element in nums1 is smaller, move its pointer forward to find a match
        else if(nums1[i] < nums2[j]){
            i++;
        }
        // If the element in nums2 is smaller, move its pointer forward
        else{
            j++;
        }
    }
    // Return the final intersection vector
    return ans;
}

// Main function where the program starts
int main(){
    // Define the first sorted input vector
    vector<int> nums1 = {1,2,3,4,5,6,7,8,9};
    // Define the second sorted input vector
    vector<int> nums2 = {5,9,12};
    // Call the function to get the intersection
    vector<int> result = intersection(nums1,nums2);

    // Print the output heading
    cout<<"Intersection of given array is : ";
    // Loop through the result vector and print each element
    for(int num : result){
        cout<<num<<" ";
    }

    // Indicate successful program execution
    return 0;
}