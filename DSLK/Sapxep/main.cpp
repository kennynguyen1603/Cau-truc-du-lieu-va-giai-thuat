#include "Node.h"
#include "LinkedList.h"
// #include "Node.cpp"
// #include "LinkedList.cpp"
#include <iostream>
using namespace std;

int main()
{
    LinkedList A;
    A.creatLinkedlist();

    LinkedList B;
    B.creatLinkedlist();

    cout << "Enter values for list A (-1 to end): " << endl;
    int valueA;
    while (true)
    {
        cin >> valueA;
        if (valueA == -1)
            break;
        A.appendList(valueA);
    }

    cout << "List A: ";
    A.displayList();

    cout << "Enter values for list B (-1 to end): " << endl;
    int valueB;
    while (true)
    {
        cin >> valueB;
        if (valueB == -1)
            break;
        B.appendList(valueB);
    }

    cout << "List B: ";
    B.displayList();

    // A.swapEvenOdd(A, B);
    A.swapEvenOdd(B);

    cout << "List A after swapping: ";
    A.displayList();
    cout << "List B after swapping: ";
    B.displayList();
    return 0;
}