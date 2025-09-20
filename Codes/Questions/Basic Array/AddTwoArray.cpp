#include<iostream> 
#include<vector>   
#include<algorithm> 

using namespace std; 

vector<int> findArraySum(vector<int>& a, vector<int>& b){
    int i = a.size() - 1;
    int j = b.size() - 1;

    vector<int> ans;
    int carry = 0;   
    while(i >= 0 && j >= 0){
        int val1 = a[i]; 
        int val2 = b[j];

        int sum = val1 + val2 + carry;

        carry = sum / 10;
        sum = sum % 10; 
        ans.push_back(sum);
        
        i--;
        j--; 
    }
    while(i >= 0){
        int sum = a[i] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
    }
    while(j >= 0){
        int sum = b[j] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        j--;
    }
    while(carry != 0){
        int sum = carry;
        carry = sum / 10; 
        sum = sum % 10;  
        ans.push_back(sum);
    }
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

    return 0; 
}