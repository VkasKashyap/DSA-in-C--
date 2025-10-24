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

    void deleteByValue(int val){
        // case 1 . the list is empty
        if(head ==  NULL){
            cout<<"list is empty . cannot delete"<<endl;
            return;
        }
        // case 2. handle deletion at the head(potentially multiple consecutive deletion at head)
        Node* temp = head;
        while(head != NULL && head -> data == val){
            temp = head;
            head = head -> next;
            delete temp;
        }
        // if the list became empty after deletion then we are done
        if(head == NULL){
            return;
        }
        // case 3. handle deltion int the middle or end
        //at this point head is guranteed to not have value to be deleted
        Node* prev = head;
        Node* curr = head -> next;
        while(curr != NULL){
            if(curr -> data == val){
                prev -> next = curr -> next;
                temp = curr;
                curr = curr -> next;
                delete temp;
            }
            else{
                prev = curr;
                curr = curr -> next;
            }
        }
    }

    void printList(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" --> ";
            temp = temp -> next;
        }
        cout<<"NULL"<<endl;
    }
};

int main(){
    LinkedList mylist;
    mylist.InsertAtEnd(10);
    mylist.InsertAtEnd(10);
    mylist.InsertAtEnd(20);
    mylist.InsertAtEnd(10);
    mylist.InsertAtEnd(30);
    mylist.InsertAtEnd(40);
    cout<<"List before deletion operation"<<endl;
    mylist.PrintList();
    cout<<"List after deleting 10 value "<<endl;
    mylist.deleteByValue(10);
    mylist.printList();

    return 0;
}
