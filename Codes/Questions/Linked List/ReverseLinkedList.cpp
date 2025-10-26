#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};
void reverse(Node*& head, Node* curr, Node* prev){
    if(curr == NULL){
        head = prev;
        return;
    }
    
    Node* forward = curr -> next;
    reverse(head, forward, curr); 
    curr -> next = prev;          
}

class LinkedList{
public:
    Node* head;
    LinkedList(){
        head = NULL;
    }

    void InsertAtEnd(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = newNode;
    }

    void PrintList(){
        Node* temp = head;
        if(temp == NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        while(temp != NULL){
            cout<<temp -> data<< " --> ";
            temp = temp -> next;
        }
        cout<<"NULL"<<endl;
    }
};

int main(){
    LinkedList mylist;
    mylist.InsertAtEnd(10);
    mylist.InsertAtEnd(20);
    mylist.InsertAtEnd(30);
    mylist.InsertAtEnd(40);

    cout << "Original list: " << endl;
    mylist.PrintList();

    Node* prev = NULL;
    Node* curr = mylist.head; 
    reverse(mylist.head, curr, prev);

    cout << "Reversed list: " << endl;
    mylist.PrintList();

    return 0;
}