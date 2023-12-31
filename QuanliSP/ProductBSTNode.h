#include "Product.h"

class ProductBSTNode
{
private:
    Product product;
    ProductBSTNode *left;
    ProductBSTNode *right;

public:
    ProductBSTNode();
    ProductBSTNode(Product product);
    ~ProductBSTNode();

    void setProduct(Product product);
    Product getProduct();

    void setLeft(ProductBSTNode *left);
    ProductBSTNode *&getLeft();

    void setRight(ProductBSTNode *right);
    ProductBSTNode *&getRight();

    void input();
    void output();
};