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
    void removeAt(int k);      // remove the kth node
    void removeAfter(int k);   // remove the node after the kth node
    void removeBefore(int k);  // remove the node before the kth node
    void removeByValue(int x); // remove the node with value x

    int count(); // count the number of nodes
    int sum();   // sum of all values stored in the list
    int search(int x);
    void printSearch(int x); // print the position of the node with value x

    void update(int x, int k); // update the value of the kth node to x
    void reverse();
    void sort();
    void max();
    void removeDuplicates(); // remove all duplicates

    void traval();
};