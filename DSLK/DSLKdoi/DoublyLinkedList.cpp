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
    int count = 1; // start from 1
    while (current != nullptr && count != place)
    {
        current = current->getNext();
        count++;
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
            current->getNext()->setPrev(newNode); // set the previous of the next node
            current->setNext(newNode);
        }
    }
}

void DoublyLinkedList::insertBefore(int value, int place)
{
    Node *newNode = new Node(value);
    Node *current = head;
    int count = 1;
    while (current != nullptr && count != place)
    {
        current = current->getNext();
        count++;
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
            insertHead(value);
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

void DoublyLinkedList::traval()
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->getData() << " ";
        current = current->getNext();
    }
    cout << endl;
}

void DoublyLinkedList::removeHead()
{
    if (isEmpty())
    {
        cout << "The list is empty!" << endl;
        return;
    }
    else
    {
        Node *temp = head;
        head = head->getNext();
        head->setPrev(nullptr);
        delete temp;
    }
}

void DoublyLinkedList::removeTail()
{
    if (isEmpty())
    {
        cout << "The list is empty!" << endl;
        return;
    }
    else
    {
        Node *temp = tail;
        tail = tail->getPrev();
        tail->setNext(nullptr);
        delete temp;
    }
}

void DoublyLinkedList::removeAt(int place)
{
    Node *current = head;
    int count = 1;
    while (current != nullptr && count != place)
    {
        current = current->getNext();
        count++;
    }
    if (current == nullptr)
    {
        cout << "Cannot find the position to remove!" << endl;
        return;
    }
    else
    {
        if (current == head)
        {
            removeHead();
        }
        else if (current == tail)
        {
            removeTail();
        }
        else
        {
            current->getPrev()->setNext(current->getNext());
            current->getNext()->setPrev(current->getPrev());
            delete current;
        }
    }
}

void DoublyLinkedList::removeAfter(int place)
{
    Node *current = head;
    int count = 1;
    while (current != nullptr && count != place)
    {
        current = current->getNext();
        count++;
    }
    if (current == nullptr)
    {
        cout << "Cannot find the position to remove!" << endl;
        return;
    }
    else
    {
        if (current == tail)
        {
            cout << "Cannot remove the node after the tail!" << endl;
            return;
        }
        else
        {
            Node *temp = current->getNext();
            current->setNext(temp->getNext());
            temp->getNext()->setPrev(current);
            delete temp;
        }
    }
}

void DoublyLinkedList::removeBefore(int place)
{
    Node *current = head;
    int count = 1;
    while (current != nullptr && count != place)
    {
        current = current->getNext();
        count++;
    }
    if (current == nullptr)
    {
        cout << "Cannot find the position to remove!" << endl;
        return;
    }
    else
    {
        if (current == head)
        {
            cout << "Cannot remove the node before the head!" << endl;
            return;
        }
        else
        {
            Node *temp = current->getPrev();
            current->setPrev(temp->getPrev());
            temp->getPrev()->setNext(current);
            delete temp;
        }
    }
}

void DoublyLinkedList::removeByValue(int value)
{
    Node *current = head;
    while (current != nullptr && current->getData() != value)
    {
        current = current->getNext();
    }
    if (current == nullptr)
    {
        cout << "Cannot find the value to remove!" << endl;
        return;
    }
    else
    {
        if (current == head)
        {
            removeHead();
        }
        else if (current == tail)
        {
            removeTail();
        }
        else
        {
            current->getPrev()->setNext(current->getNext());
            current->getNext()->setPrev(current->getPrev());
            delete current;
        }
    }
}

int DoublyLinkedList::count()
{
    Node *current = head;
    int count = 0;
    while (current != nullptr)
    {
        count++;
        current = current->getNext();
    }
    return count;
}

int DoublyLinkedList::sum()
{
    Node *current = head;
    int sum = 0;
    while (current != nullptr)
    {
        sum += current->getData();
        current = current->getNext();
    }
    return sum;
}

int DoublyLinkedList::search(int value)
{
    Node *current = head;
    int count = 1;
    while (current != nullptr && current->getData() != value)
    {
        current = current->getNext();
        count++;
    }
    if (current == nullptr)
    {
        return -1;
    }
    else
    {
        return count;
    }
}

void DoublyLinkedList::printSearch(int value)
{
    int place = search(value);
    if (place == -1)
    {
        cout << "Cannot find the value!" << endl;
    }
    else
    {
        cout << "The value " << value << " is at position " << place << endl;
    }
}

void DoublyLinkedList::update(int value, int place)
{
    Node *current = head;
    int count = 1;
    while (current != nullptr && count != place)
    {
        current = current->getNext();
        count++;
    }
    if (current == nullptr)
    {
        cout << "Cannot find the position to update!" << endl;
        return;
    }
    else
    {
        current->setData(value);
    }
}

void DoublyLinkedList::reverse()
{
    Node *current = head;
    Node *temp = nullptr;
    while (current != nullptr)
    {
        temp = current->getPrev(); // swap the previous and the next
        current->setPrev(current->getNext());
        current->setNext(temp);
        current = current->getPrev();
    }
    if (temp != nullptr)
    {
        head = temp->getPrev();
    }
}

void DoublyLinkedList::sort()
{
    Node *current = head;
    Node *index = nullptr;
    int temp;
    if (head == nullptr)
    {
        return;
    }
    else
    {
        while (current != nullptr)
        {
            index = current->getNext();
            while (index != nullptr)
            {
                if (current->getData() > index->getData())
                {
                    temp = current->getData();
                    current->setData(index->getData());
                    index->setData(temp);
                }
                index = index->getNext();
            }
            current = current->getNext();
        }
    }
}

void DoublyLinkedList::max()
{
    Node *current = head;
    int max = current->getData();
    while (current != nullptr)
    {
        if (current->getData() > max)
        {
            max = current->getData();
        }
        current = current->getNext();
    }
    cout << "The maximum value is " << max << endl;
}

void DoublyLinkedList::removeDuplicates()
{
    Node *current = head;
    Node *index = nullptr; // the node after current
    Node *temp = nullptr;  // the node to be deleted
    while (current != nullptr && current->getNext() != nullptr)
    {
        index = current;
        while (index->getNext() != nullptr)
        {
            if (current->getData() == index->getNext()->getData())
            {
                temp = index->getNext();
                index->setNext(temp->getNext());
                if (temp->getNext() != nullptr)
                {
                    temp->getNext()->setPrev(index);
                }
                delete temp;
            }
            else
            {
                index = index->getNext();
            }
        }
        current = current->getNext();
    }
}