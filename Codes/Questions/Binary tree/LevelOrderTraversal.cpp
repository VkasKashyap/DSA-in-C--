#include<iostream>
#include<vector>
#include<queue>
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

vector< vector<int> > levelOrderTraversal(Node* root){
    vector< vector<int> > ans;
    if(!root)   return ans;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i=0 ; i<size ; i++){
            Node* node = q.front();
            q.pop();
            
            if(node -> left)    q.push(node -> left);
            if(node -> right)   q.push(node -> right);
            level.push_back(node -> data);
        }
        ans.push_back(level);
    }
    return ans;
}

void printLevelOrder(Node* node){
    vector< vector<int> > ans = levelOrderTraversal(node);
    cout<<"{";
    for(int i=0 ; i<ans.size() ; i++){
        cout<<"{";
        for(int j=0 ; j<ans[i].size() ; j++){
            cout<<ans[i][j];
        }
        cout<<"}";
    }
    cout<<"}";
}

int main(){
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);

    cout<<"level order Traversal of the tree : ";
    printLevelOrder(root);       //output {{1}{23}{45}}
    cout<<endl;

    return 0;
}
