#include "Node.h"

Node::Node()
{
    this->data = 0;
    this->pNext = nullptr;
}

Node::Node(int x)
{
    this->data = x;
    this->pNext = nullptr;
}

Node::~Node() {}

int Node::getData()
{
    return this->data;
}

void Node::setData(int x)
{
    this->data = x;
}
Node *Node::getNext()
{
    return this->pNext;
}
void Node::setNext(Node *p)
{
    this->pNext = p;
}

Node *Node::creatNode(int x)
{
    Node *newNode = new Node;
    newNode->data = x;
    newNode->pNext = nullptr;
    return newNode;
}
