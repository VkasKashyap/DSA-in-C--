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

Node* getIntersection(Node* headA , Node* headB){
    Node* ptrA = headA;
    while(ptrA != NULL){
        Node* ptrB = headB;
        while(ptrB != NULL){
            if(ptrA == ptrB){
                return ptrA;
            }
            ptrB = ptrB -> next;
        }
        ptrA = ptrA -> next;
    }
    return NULL;
}

int main(){
    LinkedList mylist;
    mylist.InsertAtEnd(10);
    mylist.InsertAtEnd(20);
    mylist.InsertAtEnd(30);
    mylist.InsertAtEnd(40);

    LinkedList newlist;
    newlist.InsertAtEnd(5);
    newlist.InsertAtEnd(15);
    newlist.head -> next -> next = mylist.head -> next ;


    cout << "Original list: " << endl;
    mylist.PrintList();
    cout << "Second list: " << endl;
    newlist.PrintList();

    Node* ans = getIntersection(mylist.head, newlist.head);
    if(ans != NULL){
        cout<<"Intersection of two Linked list is : "<<ans -> data<<endl;
    }
    else{
        cout<<"Intersection is not present"<<endl;
    }



    return 0;
}