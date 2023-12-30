#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList()
{
    head = nullptr;
    tail = nullptr;
}

DoublyLinkedList::~DoublyLinkedList()
{
    Node *p = head;
    while (p != nullptr)
    {
        head = head->getNext();
        delete p;
        p = head;
    }
}

bool DoublyLinkedList::isEmpty()
{
    return head == nullptr;
}

void DoublyLinkedList::insertHead(int x)
{
    Node *newNode = new Node(x);
    if (isEmpty())
    {
        head = newNode;
        tail = newNode;
        return; // exit the function
    }
    else
    {
        newNode->setNext(head);
        head->setPrev(newNode);
        head = newNode;
    }
}

void DoublyLinkedList::insertTail(int x)
{
    Node *newNode = new Node(x);
    if (isEmpty())
    {
        head = newNode;
        tail = newNode;
        return; // exit the function
    }
    else
    {
        tail->setNext(newNode);
        newNode->setPrev(tail);
        tail = newNode;
    }
}

void DoublyLinkedList::insertAfter(int value, int place)
{
    Node *newNode = new Node(value);
    Node *current = head; // start from the head
    // find the position to insert
    while (current != nullptr && current->getData() != place)
    {
        current = current->getNext();
    }
    // if the position is not found
    if (current == nullptr)
    {
        cout << "Cannot find the position to insert!" << endl;
        return;
    }
    // if the position is found
    else
    {
        // if the position is the tail
        if (current == tail)
        {
            insertTail(value);
        }
        // if the position is not the tail
        else
        {
            newNode->setNext(current->getNext());
            newNode->setPrev(current);
            current->getNext()->setPrev(newNode);
            current->setNext(newNode);
        }
    }
}

void DoublyLinkedList::insertBefore(int x, int k)
{
    Node *newNode = new Node(x);
    Node *current = head;
    while (current != nullptr && current->getData() != k)
    {
        current = current->getNext();
    }
    if (current == nullptr)
    {
        cout << "Cannot find the position to insert!" << endl;
        return;
    }
    else
    {
        if (current == head)
        {
            insertHead(x);
        }
        else
        {
            newNode->setNext(current);
            newNode->setPrev(current->getPrev());
            current->getPrev()->setNext(newNode);
            current->setPrev(newNode);
        }
    }
}