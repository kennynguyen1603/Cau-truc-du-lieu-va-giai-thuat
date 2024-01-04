#include "Node.h"

Node::Node()
{
    heso = 0;
    somu = 0;
    next = nullptr;
}

Node::Node(int heso, int somu)
{
    this->heso = heso;
    this->somu = somu;
    next = nullptr;
}

// Node::Node(int heso, int somu, Node *next)
// {
//     this->heso = heso;
//     this->somu = somu;
//     this->next = next;
// }

Node::~Node()
{
    heso = 0;
    somu = 0;
    next = nullptr;
}

void Node::setHeso(int heso)
{
    this->heso = heso;
}

void Node::setSomu(int somu)
{
    this->somu = somu;
}

void Node::setNext(Node *next)
{
    this->next = next;
}

int Node::getHeso()
{
    return heso;
}

int Node::getSomu()
{
    return somu;
}

Node *Node::getNext()
{
    return next;
}
