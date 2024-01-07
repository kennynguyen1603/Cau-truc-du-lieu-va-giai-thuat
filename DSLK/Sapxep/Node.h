#pragma once
#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    Node *pNext;

public:
    Node();
    Node(int x);
    Node(int x, Node *p);
    ~Node();

    void setData(int x);
    void setNext(Node *p);

    int getData();
    Node *getNext();
};