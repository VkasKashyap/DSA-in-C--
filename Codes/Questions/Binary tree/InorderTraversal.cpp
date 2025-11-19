#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void printInorderTraversal(Node* node){
    if(!node)   return;

    printInorderTraversal(node -> left);
    cout<<node -> data<<" ";
    printInorderTraversal(node -> right);
}

int main(){
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);

    cout<<"In order Traversal of the tree : ";
    printInorderTraversal(root);       //output 4 2 5 1 3
    cout<<endl;

    return 0;
}