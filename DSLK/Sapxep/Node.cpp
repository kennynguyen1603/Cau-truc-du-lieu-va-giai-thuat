#include "Node.h"

Node::Node()
{
    data = 0;
    pNext = nullptr;
}

Node::Node(int x)
{
    data = x;
    pNext = nullptr;
}

Node::Node(int x, Node *p)
{
    data = x;
    pNext = p;
}

Node::~Node()
{
}

void Node::setData(int x)
{
    data = x;
}

void Node::setNext(Node *p)
{
    pNext = p;
}

int Node::getData()
{
    return data;
}

Node *Node::getNext()
{
    return pNext;
}
