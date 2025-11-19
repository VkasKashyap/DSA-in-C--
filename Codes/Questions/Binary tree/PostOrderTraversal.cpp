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

void postOrderTraversal(Node* node){
    if(!node)   return;

    postOrderTraversal(node -> left);
    postOrderTraversal(node -> right);
    cout<<node -> data<<" ";
}

int main(){
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);

    cout<<"post order Traversal of the tree : ";
    postOrderTraversal(root);       //output    4 5 2 3 1
    cout<<endl;

    return 0;
}