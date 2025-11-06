/*
You are given an integer array arr. Sort the integers in the array in ascending order by the number of 1's 
in their binary representation and in case of two or more integers have the same number of 1's you have to 
sort them in ascending order.

Return the array after sorting it.

Example 1:

Input: arr = [0,1,2,3,4,5,6,7,8]
Output: [0,1,2,4,8,3,5,6,7]
Explantion: [0] is the only integer with 0 bits.
[1,2,4,8] all have 1 bit.
[3,5,6] have 2 bits.
[7] has 3 bits.
The sorted array by bits is [0,1,2,4,8,3,5,6,7]
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int find1BitsCount(int num){
    int count = 0;
    while(num != 0){
        count += (num&1);
        num >>= 1;
    }
    return count;
}

vector<int> sortByBits(vector<int>& arr) {

    auto lamda = [&] (int &a, int &b){
        int count_a =/* __builtin_popcount(a);*/              find1BitsCount(a);
        int count_b =/* __builtin_popcount(b);  */            find1BitsCount(b);
        if(count_a == count_b)  return a<b;
        return count_a < count_b;
    };


    sort(arr.begin(), arr.end(), lamda);
    return arr;
}
void print(vector<int>& nums){
    for(int num : nums){
        cout<<num<<" ";
    }
}

int main(){
    vector<int> nums = {0,1,2,3,4,5,6,7,8};
    vector<int> ans = sortByBits(nums);
    print(ans);

    return 0;
}