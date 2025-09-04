#include<iostream>
#include<vector>
using namespace std;

void PrintSum(vector<vector<int>>& nums){
    int m = nums.size();
    if (m == 0) return;
    int n = nums[0].size();

    for(int i=0 ; i<m ; i++){
        int sum = 0;
        for(int j=0 ; j<n ; j++){
            sum += nums[i][j];
        }
        cout<<sum<<" ";
    }
}

int main(){
    int m, n;
    cout<<"Enter the Rows of The Matrix : ";
    cin>>m;
    cout<<"Enter the Column of The Matrix : ";
    cin>>n;

    vector<vector<int>> nums(m, vector<int>(n));

    cout<<"Enter the Elements in the Matrix"<<endl;
    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            cin>>nums[i][j];
        }
    }

    cout<<"Row Wise Sum of The Matrix Is : ";
    PrintSum(nums);
    cout << endl;

    return 0;
}