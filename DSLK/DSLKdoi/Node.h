#pragma once
#include <iostream>
using namespace std;
class Node
{
private:
    int data;   // data stored in the node
    Node *prev; // pointer to the previous node
    Node *next; // pointer to the next node

    // friend class LinkedList;

public:
    Node();
    Node(int x);
    Node(int x, Node *p, Node *n);

    int getData();
    Node *getPrev();
    Node *getNext();

    void setData(int x);
    void setPrev(Node *p);
    void setNext(Node *n);

    ~Node();
};