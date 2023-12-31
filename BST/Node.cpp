#include "Node.h"

Node::Node(int data)
{
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}

Node::~Node()
{
    // cout << "Node with data " << this->data << " is destroyed" << endl;
}

int Node::getData()
{
    return this->data;
}

void Node::setData(int data)
{
    this->data = data;
}

Node *Node::getLeft()
{
    return this->left;
}

void Node::setLeft(Node *left)
{
    this->left = left;
}

Node *Node::getRight()
{
    return this->right;
}

void Node::setRight(Node *right)
{
    this->right = right;
}

Node *Node::createNode(int data)
{
    Node *node = new Node(data);
    return node;
}