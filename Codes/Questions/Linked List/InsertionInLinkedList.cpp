#include<iostream>
using namespace std;

struct Node{
    int data;           // data value stored in the node
    Node* next;         // A pointer to next node in the list

    // Constructor to easliy create a new node
    Node(int val){
        data = val;
        next = NULL;    // initialize next to null by default
    }
};

// this class encapsulate the list and its operations
// it holds a pointer to the head(first node)

class LinkedList{
    public:
    Node* head;         // pointer to the lead of the list
    //constructor
    LinkedList(){
        head = NULL;    // the list is initially empty
    }
    //destructor
    //this cleans up all the node to prevent memory leak when the list is destroyed
    ~LinkedList(){
        Node* current = head;
        Node* nextNode = NULL;
        while(current != NULL){
            nextNode = current -> next;     //store next node
            delete current;                 //delete current node
            current = nextNode;             //move to the next node
        }
        head = NULL;
    }

    // 1. Insert at Beginning
    void insertAtBeginning(int val){
        //create the new node
        Node* newNode= new Node(val);
        //point the new node's next to the current head
        newNode -> next = head;
        //update the list's head to be the new node
        head = newNode;
    }

    // 2. Insert at End
    void insertAtEnd(int val){
        //create a new node
        Node* newNode = new Node(val);
        //if the list is empty make the new node the head
        if(head == NULL){
            head = newNode;
            return;
        }
        //if the list is not empty traverse to the last node
        Node* temp = head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        //point the last node's next to the node
        temp -> next = newNode;
    }

    // 3. Insert at Poistion (position 0 is head)
    void insertAtPosition(int val, int pos){
        //case 1. insert at beginning(position 0)
        if(pos == 0){
            insertAtBeginning(val);
            return;
        }
        //create the new node
        Node* newNode = new Node(val);
        Node* temp = head;
        //traverse temp to the pos-1
        for(int i=0 ; i<pos-1 && temp != NULL ; i++){
            temp = temp -> next;
        }
        //case 2. position is out of bound
        if(temp == NULL){
            cout<<"Error: Position "<<pos<<" is out of bound"<<endl;
            delete newNode;
            return;
        }

        //case 3. Valid Position
        //link the new node's next to the head of the currently at positon
        newNode -> next = temp -> next;
        //link the previous node (temp) to the new node
        temp -> next = newNode;
    }
    // helper function to print the list
    void printList() {
        Node* temp = head;
        if (temp == NULL) {
            std::cout << "List is empty." << std::endl;
            return;
        }
        while (temp != NULL) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL" << std::endl;
    }
};

int main() {
    LinkedList myList;

    std::cout << "\n insertAtEnd" << std::endl;
    myList.insertAtEnd(10);
    myList.insertAtEnd(20);
    myList.printList(); // Expected: 10 -> 20 -> NULL

    std::cout << "\n Testing insertAtBeginning " << std::endl;
    myList.insertAtBeginning(5);
    myList.printList(); // Expected: 5 -> 10 -> 20 -> NULL

    std::cout << "\n Testing insertAtPosition " << std::endl;
    std::cout << "Inserting 15 at position 2:" << std::endl;
    myList.insertAtPosition(15, 2);
    myList.printList(); // Expected: 5 -> 10 -> 15 -> 20 -> NULL

    std::cout << "\n Inserting 3 at position 0:" << std::endl;
    myList.insertAtPosition(3, 0);
    myList.printList(); // Expected: 3 -> 5 -> 10 -> 15 -> 20 -> NULL

    std::cout << "\n Inserting 30 at position 5 (new end):" << std::endl;
    myList.insertAtPosition(30, 5);
    myList.printList(); // Expected: 3 -> 5 -> 10 -> 15 -> 20 -> 30 -> NULL

    std::cout << "\n Inserting 100 at position 10 (out of bounds):" << std::endl;
    myList.insertAtPosition(100, 10);
    myList.printList(); // Expected: Error message and list unchanged

    return 0;
}

