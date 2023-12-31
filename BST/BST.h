#include "Node.h"

class BST
{
private:
    Node *root;

public:
    BST();
    ~BST();
    Node *getRoot();
    void setRoot(Node *root);

    void createBST(Node *&root);

    void insert(int data);             // insert data into BST rooted at root
    void insert(Node *root, int data); // insert data into BST rooted at root

    void remove(int data);             // remove data from BST rooted at root
    void remove(Node *root, int data); // remove data from BST rooted at root

    void NLR(Node *);
    void NRL(Node *);
    // xuất các giá trị từ bé dến lớn
    void LNR(Node *);
    // xuất các giá trị từ lớn đến bé
    void RNL(Node *);
    void LRN(Node *);
    void RLN(Node *);

    // void print(); // print BST rooted at root

    // bool search(int data);            // search data in BST rooted at root
    // void printResultSearch(int data); // print result of searching data in BST rooted at root

    int countNodes(Node *root); // count number of nodes in BST rooted at root
    //     int height(); // compute height of BST rooted at root
    //     // int height(Node *root);           // compute height of BST rooted at root
    //     int min(); // find minimum value in BST rooted at root
    //     // int min(Node *root);              // find minimum value in BST rooted at root
    //     int max(); // find maximum value in BST rooted at root
    //     // int max(Node *root);              // find maximum value in BST rooted at root
    //     void DestroyTree(Node *&root); // clear BST rooted at root
};