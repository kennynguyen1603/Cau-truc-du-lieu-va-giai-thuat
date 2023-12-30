#include "Node.h"
// #include "Node.cpp"
#include "LinkedList.h"
// #include "LinkedList.cpp"
#include <iostream>
using namespace std;
int main()
{
    LinkedList l1, l2;
    l1.creatLinkedlist();
    l2.creatLinkedlist();

    // for (auto i = 0; i < 10; i++)
    // {
    //     Node *node = new Node(i);
    //     l1.insertHead(node);
    // }
    // l1.traval();
    // int count = l.countElList();
    // cout << count << endl;
    for (auto i = 0; i < 10; i++)
    {
        Node *node = new Node(i);
        l2.insertTail(node);
    }
    l2.traval();
    l2.insertAfter(5, 100);
    l2.traval();
    return 0;
}