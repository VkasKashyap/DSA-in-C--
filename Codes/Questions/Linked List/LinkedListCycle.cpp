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

bool floydCycleDetect(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast){
            return true;
        }
    }
    return false;
}



int main(){
    LinkedList mylist;
    mylist.InsertAtEnd(10);
    mylist.InsertAtEnd(20);
    mylist.InsertAtEnd(30);
    mylist.InsertAtEnd(40);

    cout << "Original list: " << endl;
    mylist.PrintList();
    if(floydCycleDetect(mylist.head)){
        cout<<"Linked List is Cyclic."<<endl;
    }
    else{
        cout<<"Linked List is not Cyclic."<<endl;
    }




    return 0;
}