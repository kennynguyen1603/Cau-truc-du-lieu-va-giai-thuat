#include "BST.h"
#include <iostream>
using namespace std;

int main()
{
    BST *bst = new BST();
    bst->insert(10);
    bst->insert(5);
    bst->insert(15);
    bst->insert(3);
    bst->insert(bst->getRoot(), 7);
    // bst->RNL(bst->getRoot());
    // cout << endl;
    // bst->remove(5);
    bst->LNR(bst->getRoot());
    cout << endl;
    cout << "So luong node cua cay la: " << bst->countNodes(bst->getRoot());
    return 0;
}