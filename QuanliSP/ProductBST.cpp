#include "ProductBST.h"

ProductBST::ProductBST()
{
    this->root = nullptr;
}

ProductBST::~ProductBST()
{
}

void ProductBST::setRoot(ProductBSTNode *root)
{
    this->root = root;
}

ProductBSTNode *ProductBST::getRoot()
{
    return this->root;
}

ProductBSTNode *ProductBST::insert(ProductBSTNode *node, Product *product)
{
    if (node == nullptr)
        return new ProductBSTNode(*product);
    else
    {
        // if (product->getId() < node->getProduct().getId())
        //     insert(node->getLeft(), product);
        // else if (product->getId() > node->getProduct().getId())
        //     insert(node->getRight(), product);
        if (product->getId() < node->getProduct().getId())
            node->setLeft(insert(node->getLeft(), product));
        else if (product->getId() > node->getProduct().getId())
            node->setRight(insert(node->getRight(), product));
    }
    return node;
}

void ProductBST::inorderDisplay(ProductBSTNode *node)
{
    if (node != nullptr)
    {
        inorderDisplay(node->getLeft());
        node->output();
        inorderDisplay(node->getRight());
    }
}

int ProductBST::countProduct(ProductBSTNode *node)
{
    if (node == nullptr)
        return 0;
    else
        return 1 + countProduct(node->getLeft()) + countProduct(node->getRight());
}

ProductBSTNode *ProductBST::search(ProductBSTNode *node, int id)
{
    if (node == nullptr || node->getProduct().getId() == id)
        return node;

    if (id < node->getProduct().getId())
        return search(node->getLeft(), id);
    else
        return search(node->getRight(), id);
}

int ProductBST::countLeaf(ProductBSTNode *node)
{
    if (node == nullptr)
        return 0;
    else
    {
        if (node->getLeft() == nullptr && node->getRight() == nullptr)
            return 1;
        else
            return countLeaf(node->getLeft()) + countLeaf(node->getRight());
    }
}

void ProductBST::remove(ProductBSTNode *node)
{
    if (node != nullptr)
    {
        remove(node->getLeft());
        remove(node->getRight());
        delete node;
    }
}

void ProductBST::displayAvailable(ProductBSTNode *node)
{
    if (node != nullptr)
    {
        if (node->getProduct().getStatus() == "Available" || node->getProduct().getStatus() == "Con hang")
            node->output();
        displayAvailable(node->getLeft());
        displayAvailable(node->getRight());
    }
    else
        // cout << "No product available!" << endl;
        return;
}

ProductBSTNode *ProductBST::minValueNode(ProductBSTNode *node)
{
    ProductBSTNode *current = node;
    while (current->getLeft() != nullptr)
        current = current->getLeft();
    return current;
}

ProductBSTNode *ProductBST::deleteNode(ProductBSTNode *root, int product_id)
{
    if (root == nullptr)
        return root;

    if (product_id < root->getProduct().getId())
    {
        root->getLeft() = deleteNode(root->getLeft(), product_id);
    }
    else if (product_id > root->getProduct().getId())
    {
        root->getRight() = deleteNode(root->getRight(), product_id);
    }
    else
    {
        if (root->getLeft() == nullptr)
        {
            ProductBSTNode *temp = root->getRight();
            delete root;
            return temp;
        }
        else if (root->getRight() == nullptr)
        {
            ProductBSTNode *temp = root->getLeft();
            delete root;
            return temp;
        }

        ProductBSTNode *temp = minValueNode(root->getRight());
        root->getProduct() = temp->getProduct();
        root->getRight() = deleteNode(root->getRight(), temp->getProduct().getId());
    }

    return root;
}

ProductBSTNode *ProductBST::deleteSoldOut(ProductBSTNode *node)
{
    if (node == nullptr)
        return nullptr;
    node->setLeft(deleteSoldOut(node->getLeft()));
    node->setRight(deleteSoldOut(node->getRight()));

    if (node->getProduct().getStatus() == "Sold out" || node->getProduct().getStatus() == "Het hang")
    {
        ProductBSTNode *temp;
        if (node->getLeft() == nullptr || node->getRight() == nullptr)
        {
            temp = (node->getLeft() != nullptr) ? node->getLeft() : node->getRight();
            if (temp == nullptr)
            {
                temp = node;
                node = nullptr;
            }
            else
            {
                *node = *temp;
            }
            delete temp;
        }
        else
        {
            ProductBSTNode *temp = minValueNode(node->getRight());
            node->getProduct() = temp->getProduct();
            node->getRight() = deleteNode(node->getRight(), temp->getProduct().getId());
        }
    }
    return node;
}

void ProductBST::insert(Product *product)
{
    this->root = insert(this->root, product);
}

void ProductBST::display()
{
    inorderDisplay(this->root);
}

int ProductBST::countProduct()
{
    return countProduct(this->root);
}

void ProductBST::search(int id)
{
    ProductBSTNode *node = search(this->root, id);
    if (node != nullptr)
        node->output();
    else
        cout << "Product not found!" << endl;
}

void ProductBST::displayAvailable()
{
    displayAvailable(this->root);
}

void ProductBST::deleteSoldOut()
{
    this->root = deleteSoldOut(this->root);
}
