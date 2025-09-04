#include<iostream>
#include<vector>
using namespace std;

int isPresent(vector<vector<int>>& nums , int target){
    int row = nums.size();
    int column = nums[0].size();

    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < column ; j++){
            if(nums[i][j] == target){
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    vector<vector<int>> nums = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int target;
    cout<<"Enter the value to be Searched : ";
    cout<<endl;
    cin>>target;

    if(isPresent(nums,target)){
        cout<<"Value is Present";
    }
    else{
        cout<<"Value is not Present";
    }

    return 0;

}