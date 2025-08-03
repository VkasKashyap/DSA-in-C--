#include<iostream>
using namespace std;

bool checkPalindrome(char name[],int n){
    int s = 0 ;
    int e = n-1;
    while(s <= e){
        if(name[s] == name[e]){
            s++;
            e--;
        }
        else{
            return false;
        }
    }
    return true;
}
int getLength(char name[]){
    int count = 0;
    for(int i = 0 ; name[i] != '\0' ; i++){
        count++;
    }
    return count;
}
int main(){
    char name[20];
    cout<<"Enter a String : ";
    cin>>name;
    int n = getLength(name);
    cout<<checkPalindrome(name,n);

    return 0;
}