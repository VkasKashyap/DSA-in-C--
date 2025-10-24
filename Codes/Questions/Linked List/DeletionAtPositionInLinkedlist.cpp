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

    void insertAtEnd(int val){
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

    void printList(){
        Node* temp = head;
        if(temp == NULL){
            cout<<"List is Empty"<<endl;
            return;
        }
        while(temp != NULL){
            cout<<temp -> data<<" --> ";
            temp = temp -> next;
        }
        cout<<"NULL"<<endl;
    }

    void deletionAtPosition(int pos){
        // case 1. The list is empty
        if(head == NULL){
            cout<<"list is empty. cannot delete"<<endl;
            return;
        }
        Node* temp = head;
        //case 2. delete the head node
        if(pos == 0){
            head = temp -> next;
            delete temp;
            return;
        }
        //case 3. delete the node in the middle or end
        //traverse to find the node before the one to be deleted
        Node* prev = NULL;
        for(int i=0 ; i< pos && temp != NULL ; i++){
            prev = temp;
            temp = temp -> next;
        }
        //case 4. position is out of bound
        if(temp == NULL){
            cout<<"Error Position "<<pos<<" is out of bound"<<endl;
            return;
        }
        prev -> next = temp -> next;
        delete temp;
    }
};

int main(){
    LinkedList myList;
    myList.insertAtEnd(10);
    myList.insertAtEnd(20);
    myList.insertAtEnd(30);
    myList.insertAtEnd(40);
    cout<<"List before Deletion"<<endl;
    myList.printList();
    cout<<"list after deleting node 2"<<endl;
    myList.deletionAtPosition(2);
    myList.printList();
    return 0;
}