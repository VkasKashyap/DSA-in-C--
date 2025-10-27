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

Node* removeDuplicates(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node* curr = head;
    while(curr != NULL){
        if((curr -> next != NULL) && (curr -> data == curr -> next -> data)){
            Node* next_next = curr -> next -> next;
            delete(curr -> next);
            curr -> next = next_next;
        }
        else{
            curr = curr -> next;
        }
    }
    return head;
}



int main(){
    LinkedList mylist;
    mylist.InsertAtEnd(10);
    mylist.InsertAtEnd(20);
    mylist.InsertAtEnd(30);
    mylist.InsertAtEnd(30);
    mylist.InsertAtEnd(40);
    mylist.InsertAtEnd(40);
    mylist.InsertAtEnd(50);
    mylist.InsertAtEnd(60);

    cout << "Original list: " << endl;
    mylist.PrintList();
    mylist.head = removeDuplicates(mylist.head);
    cout<<"New List : "<<endl;
    mylist.PrintList();
    




    return 0;
}