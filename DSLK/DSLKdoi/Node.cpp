#include "Node.h"

Node::Node()
{
    data = 0;
    prev = NULL;
    next = NULL;
}

Node::Node(int x)
{
    data = x;
    prev = NULL;
    next = NULL;
}

Node::Node(int x, Node *p, Node *n)
{
    data = x;
    prev = p;
    next = n;
}

int Node::getData()
{
    return this->data;
}

Node *Node::getPrev()
{
    return this->prev;
}

Node *Node::getNext()
{
    return this->next;
}

void Node::setData(int x)
{
    data = x;
}

void Node::setPrev(Node *p)
{
    prev = p;
}

void Node::setNext(Node *n)
{
    next = n;
}

Node::~Node()
{
    // cout << "Node " << data << " is destroyed!" << endl;
}