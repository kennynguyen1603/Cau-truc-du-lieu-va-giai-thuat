#include "Node.h"

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    bool isEmpty(); // check if the list is empty

    void insertHead(int x);          // insert x to the beginning of the list
    void insertTail(int x);          // insert x to the end of the list
    void insertAfter(int x, int k);  // insert x at position k
    void insertBefore(int x, int k); // insert x before position k

    void removeHead();         // remove the first node
    void removeTail();         // remove the last node
    void removeAfter(int k);   // remove the node after the kth node
    void removeBefore(int k);  // remove the node before the kth node
    void removeByValue(int x); // remove the node with value x

    void printList(); // print the list
    void printListReverse();
    int count();
    int getHead();
    int getTail();
    int getAt(int k);
    int search(int x);
    void reverse();
    void sort();
    void sortDesc();
};