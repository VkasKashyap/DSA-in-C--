#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class List{
    Node* Head;
    Node* Tail;
public:
    List(){
        Head = Tail = NULL;
    }

};