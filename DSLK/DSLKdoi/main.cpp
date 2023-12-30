#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;

int main()
{
    DoublyLinkedList list;
    for (int i = 0; i < 10; i++)
    {
        list.insertTail(i);
    }
    list.traval();

    list.insertAfter(100, 5);
    list.traval();
    list.insertBefore(200, 5);
    list.traval();

    list.removeHead();
    list.removeTail();
    list.traval();

    list.removeAt(5);     // 200
    list.removeAfter(5);  // 100
    list.removeBefore(5); // 3
    list.removeByValue(5);
    list.traval();

    cout << "The number of node: " << list.count() << endl;
    cout << "Sum: " << list.sum() << endl;
    list.printSearch(3);
    list.update(1000, 3);
    list.traval();
    list.printSearch(10);

    list.max();

    DoublyLinkedList List;
    for (int i = 0; i < 10; i++)
    {
        List.insertHead(i);
    }
    List.traval();
    List.reverse();
    List.traval();
    return 0;
}