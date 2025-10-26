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

Node* reverseKGroup(Node* head, int k){
    Node* check = head;
    int checkCount = 0;
    while(check != NULL){
        check = check -> next;
        checkCount++;
    }
    if(checkCount < k){
        return head;
    }

    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count = 0;
    while(curr != NULL && count < k){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if(next != NULL){
        head -> next = reverseKGroup(next,k);
    }
    return prev;
}

int main(){
    LinkedList mylist;
    mylist.InsertAtEnd(10);
    mylist.InsertAtEnd(20);
    mylist.InsertAtEnd(30);
    mylist.InsertAtEnd(40);

    cout << "Original list: " << endl;
    mylist.PrintList();
    Node* newHead= reverseKGroup(mylist.head,2);
    mylist.head = newHead;
    cout<<"New List : "<< endl;
    mylist.PrintList();




    return 0;
}