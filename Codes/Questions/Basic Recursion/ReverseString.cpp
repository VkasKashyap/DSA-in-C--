#include<iostream>
using namespace std;
//Reverse a string using recursion

string reverseString(string s){
    if(s.empty()){
        return s;
    }
    return reverseString(s.substr(1))+s[0];
}

int main() {
    string str = "hello";
    cout << reverseString(str) << endl;  // Output: "olleh"
    return 0;
}


