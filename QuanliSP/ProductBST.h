#include "ProductBSTNode.h"

class ProductBST
{
private:
    ProductBSTNode *root;

public:
    ProductBST();
    ~ProductBST();

    void setRoot(ProductBSTNode *root);
    ProductBSTNode *getRoot();

    ProductBSTNode *insert(ProductBSTNode *node, Product *product);

    void inorderDisplay(ProductBSTNode *node); // LNR

    int countProduct(ProductBSTNode *node);

    ProductBSTNode *search(ProductBSTNode *node, int id);

    void displayAvailable(ProductBSTNode *node);

    ProductBSTNode *minValueNode(ProductBSTNode *node);

    ProductBSTNode *deleteNode(ProductBSTNode *root, int product_id);

    ProductBSTNode *deleteSoldOut(ProductBSTNode *node);

    int countLeaf(ProductBSTNode *node); // Node has no child

    void remove(ProductBSTNode *node); // Remove all nodes

    void insert(Product *product);
    void display();
    int countProduct();
    void search(int id);
    void displayAvailable();
    void deleteSoldOut();
};