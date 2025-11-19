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

void inOrder(Node* root, int & count){
    if(!root)   return;

    inOrder(root -> left,count);
    if(root -> right == NULL && root -> left == NULL){
        count++;
    }
    inOrder(root -> right , count);
}

int countLeafNode(Node* root){
    int count = 0;
    inOrder(root,count);

    return count;
}

int main(){
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);

    int n = countLeafNode(root);
    cout<<"No. of leaf Nodes are : "<<n<<endl;

    return 0;
}