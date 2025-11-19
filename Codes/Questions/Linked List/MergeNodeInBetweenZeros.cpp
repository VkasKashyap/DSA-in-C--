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

Node* mergeNodes(Node* head) {
    Node* newHead = head->next;
    Node* current = newHead;
    Node* sumNode = newHead;
    int currentSum = 0;

    while (current != nullptr) {
        if (current->data == 0) {
            sumNode->data = currentSum;
            sumNode->next = current->next;
            sumNode = sumNode->next;
            currentSum = 0;
        } else {
            currentSum += current->data;
        }
        current = current->next;
    }
    
    return newHead;
}



int main(){
    LinkedList mylist;
    mylist.InsertAtEnd(0);
    mylist.InsertAtEnd(3);
    mylist.InsertAtEnd(1);
    mylist.InsertAtEnd(0);
    mylist.InsertAtEnd(4);
    mylist.InsertAtEnd(5);
    mylist.InsertAtEnd(2);
    mylist.InsertAtEnd(0);


    cout << "Original list: " << endl;
    mylist.PrintList();

    mylist.head = mergeNodes(mylist.head);
    mylist.PrintList();



    return 0;
}