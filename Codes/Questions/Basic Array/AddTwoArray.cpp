#include<iostream> 
#include<vector>   
#include<algorithm> 

using namespace std; 

vector<int> findArraySum(vector<int>& a, vector<int>& b){
    int i = a.size() - 1;
    int j = b.size() - 1;

    vector<int> ans;
    int carry = 0;   // Variable to store carry-over from addition

    // Loop while both arrays have digits to process
    // (Corrected condition: should be i >= 0 and j >= 0)
    while(i >= 0 && j >= 0){
        int val1 = a[i]; // Get digit from array 'a'
        int val2 = b[j]; // Get digit from array 'b'

        int sum = val1 + val2 + carry; // Calculate sum of digits and carry

        carry = sum / 10; // Update carry
        sum = sum % 10;   // Get the last digit of the sum
        ans.push_back(sum); // Add the digit to the result
        
        i--; // Move to the previous digit in 'a'
        j--; // Move to the previous digit in 'b'
    }

    // Process remaining digits in array 'a' (if any)
    while(i >= 0){
        int sum = a[i] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
    }

    // Process remaining digits in array 'b' (if any)
    // NOTE: Original code had 'a[j]' which is incorrect, should be 'b[j]'
    // Corrected to 'b[j]' as per typical array sum logic for remaining elements
    while(j >= 0){
        int sum = b[j] + carry; // Corrected from a[j] to b[j]
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        j--;
    }

    // Add any final carry-over
    while(carry != 0){
        int sum = carry; // The remaining carry is the sum itself
        carry = sum / 10; // Update carry (will be 0 for single-digit carry)
        sum = sum % 10;   // Get the digit
        ans.push_back(sum);
    }

    // The digits are added from right to left, so the result is reversed.
    // Reverse the 'ans' vector to get the correct order (most significant digit first).
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){

    vector<int> a = {1, 2, 3, 4}; // Represents 1234
    vector<int> b = {5, 6, 7};    // Represents 567
    vector<int> sum = findArraySum(a,b);
    cout << "Sum of {1,2,3,4} and {5,6,7}: ";
    for(int digit : sum) {
        cout << digit;
    }
    cout << endl << endl; // Expected: 1801

    return 0; // Indicate successful program execution
}