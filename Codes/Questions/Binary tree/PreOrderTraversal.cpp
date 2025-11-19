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

void printPreorderTraversal(Node* node){
    if(!node)   return;
    cout<<node -> data<<" ";
    printPreorderTraversal(node -> left);
    printPreorderTraversal(node -> right);
}

int main(){
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);

    cout<<"Pre order Traversal of the tree : ";
    printPreorderTraversal(root);       //output 1 2 4 5 3
    cout<<endl;

    return 0;
}
