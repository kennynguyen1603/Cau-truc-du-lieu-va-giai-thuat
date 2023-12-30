#pragma once
#include <iostream>
using namespace std;
class Node
{
private:
    int data;
    Node *pNext; // con trỏ pNext trỏ đến Node kế tiếp

public:
    Node();
    Node(int x);
    virtual ~Node();
    int getData();
    void setData(int x);
    Node *getNext();
    void setNext(Node *p);
    Node *creatNode(int x);
};
