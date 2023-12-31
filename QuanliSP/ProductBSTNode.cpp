#include "ProductBSTNode.h"

ProductBSTNode::ProductBSTNode()
{
    this->product = Product();
    this->left = NULL;
    this->right = NULL;
}

ProductBSTNode::ProductBSTNode(Product product)
{
    this->product = product;
    this->left = NULL;
    this->right = NULL;
}

ProductBSTNode::~ProductBSTNode()
{
}

void ProductBSTNode::setProduct(Product product)
{
    this->product = product;
}

Product ProductBSTNode::getProduct()
{
    return this->product;
}

void ProductBSTNode::setLeft(ProductBSTNode *left)
{
    this->left = left;
}

ProductBSTNode *&ProductBSTNode::getLeft()
{
    return this->left;
}

void ProductBSTNode::setRight(ProductBSTNode *right)
{
    this->right = right;
}

ProductBSTNode *&ProductBSTNode::getRight()
{
    return this->right;
}

void ProductBSTNode::input()
{
    this->product.input();
}

void ProductBSTNode::output()
{
    this->product.output();
}
