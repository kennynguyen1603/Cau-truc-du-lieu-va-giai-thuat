#include "BST.h"

BST::BST()
{
    this->root = nullptr;
}

BST::~BST()
{
    // cout << "BST is destroyed" << endl;
}

Node *BST::getRoot()
{
    return this->root;
}

void BST::setRoot(Node *root)
{
    this->root = root;
}

void BST::createBST(Node *&root)
{
    root = nullptr;
}

void BST::insert(int data)
{
    if (this->root == nullptr)
    {
        this->root = new Node(data);
    }
    else
    {
        if (data < this->root->getData()) // insert into left subtree
        {
            if (this->root->getLeft() == nullptr)
            {
                this->root->setLeft(new Node(data));
            }
            else
            {
                this->insert(this->root->getLeft(), data);
            }
        }
        else
        {
            if (this->root->getRight() == nullptr)
            {
                this->root->setRight(new Node(data));
            }
            else
            {
                this->insert(this->root->getRight(), data);
            }
        }
    }
}

void BST::insert(Node *root, int data)
{
    if (root == nullptr)
    {
        root = new Node(data);
    }
    else
    {
        if (data < root->getData())
        {
            if (root->getLeft() == nullptr)
            {
                root->setLeft(new Node(data));
            }
            else
            {
                this->insert(root->getLeft(), data);
            }
        }
        else
        {
            if (root->getRight() == nullptr)
            {
                root->setRight(new Node(data));
            }
            else
            {
                this->insert(root->getRight(), data);
            }
        }
    }
}

void BST::remove(int data)
{
    if (this->root == nullptr)
    {
        cout << "BST is empty" << endl;
    }
    else
    {
        if (data < this->root->getData())
        {
            this->remove(this->root->getLeft(), data);
        }
        else if (data > this->root->getData())
        {
            this->remove(this->root->getRight(), data);
        }
        else
        {
            Node *temp = this->root;
            if (this->root->getLeft() == nullptr)
            {
                this->root = this->root->getRight();
            }
            else if (this->root->getRight() == nullptr)
            {
                this->root = this->root->getLeft();
            }
            else
            {
                this->root = this->root->getRight();
                Node *parent = nullptr;
                while (this->root->getLeft() != nullptr)
                {
                    parent = this->root;
                    this->root = this->root->getLeft();
                }
                if (parent != nullptr)
                {
                    parent->setLeft(this->root->getRight());
                }
                this->root->setLeft(temp->getLeft());
                this->root->setRight(temp->getRight());
            }
            delete temp;
        }
    }
}

void BST::remove(Node *root, int data)
{
    if (root == nullptr)
    {
        cout << "BST is empty" << endl;
    }
    else
    {
        if (data < root->getData())
        {
            this->remove(root->getLeft(), data);
        }
        else if (data > root->getData())
        {
            this->remove(root->getRight(), data);
        }
        else
        {
            Node *temp = root;
            if (root->getLeft() == nullptr)
            {
                root = root->getRight();
            }
            else if (root->getRight() == nullptr)
            {
                root = root->getLeft();
            }
            else
            {
                root = root->getRight();
                Node *parent = nullptr;
                while (root->getLeft() != nullptr)
                {
                    parent = root;
                    root = root->getLeft();
                }
                if (parent != nullptr)
                {
                    parent->setLeft(root->getRight());
                }
                root->setLeft(temp->getLeft());
                root->setRight(temp->getRight());
            }
            delete temp;
        }
    }
}

void BST::NLR(Node *root)
{
    if (root != nullptr)
    {
        cout << root->getData() << " ";
        NLR(root->getLeft());
        NLR(root->getRight());
    }
}

void BST::NRL(Node *root)
{
    if (root != nullptr)
    {
        cout << root->getData() << " ";
        NRL(root->getRight());
        NRL(root->getLeft());
    }
}

void BST::LNR(Node *root)
{
    if (root != nullptr)
    {
        LNR(root->getLeft());
        cout << root->getData() << " ";
        LNR(root->getRight());
    }
}

void BST::RNL(Node *root)
{
    if (root != nullptr)
    {
        RNL(root->getRight());
        cout << root->getData() << " ";
        RNL(root->getLeft());
    }
}

void BST::LRN(Node *root)
{
    if (root != nullptr)
    {
        LRN(root->getLeft());
        LRN(root->getRight());
        cout << root->getData() << " ";
    }
}

void BST::RLN(Node *root)
{
    if (root != nullptr)
    {
        RLN(root->getRight());
        RLN(root->getLeft());
        cout << root->getData() << " ";
    }
}

int BST::countNodes(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return 1 + countNodes(root->getLeft()) + countNodes(root->getRight());
}
