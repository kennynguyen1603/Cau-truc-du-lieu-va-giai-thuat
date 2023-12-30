#include "LinkedList.h"

LinkedList::LinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
}

// void LinkedList::creatLinkedlist(LinkedList &l)
// {
//     l.head = nullptr;
//     l.tail = nullptr;
// }

void LinkedList::creatLinkedlist()
{
    this->head = nullptr;
    this->tail = nullptr;
}

// void LinkedList::insertHead(LinkedList &l, Node *node)
// {
//     if (l.head == nullptr)
//     {
//         l.head = node;
//         l.tail = node;
//     }
//     else
//     {
//         node->setNext(l.head);
//         l.head = node;
//     }
// }

void LinkedList::insertHead(Node *node)
{
    if (this->head == nullptr)
    {
        this->head = node;
        this->tail = node;
    }
    else
    {
        node->setNext(this->head);
        this->head = node;
    }
}

void LinkedList::insertTail(Node *node)
{
    Node *p = this->head;
    if (this->head == nullptr)
    {
        this->head = node;
        this->tail = node;
    }
    else
    {
        this->tail->setNext(node);
        this->tail = node;
    }
}

void LinkedList::insertAfter(int place, int value)
{
    // sau place là vị trí cần chèn, value là giá trị chèn
    int k = countElList();
    // cout << k << endl;
    if (place < 1 || place >= k + 1)
        return; // kết thúc chương trình
    else if (place == 1)
    {
        insertHead(new Node(value));
        return; // kết thúc chương trình
    }
    else if (place == k)
    {
        insertTail(new Node(value));
        return; // kết thúc chương trình
    }
    else
    {
        Node *temp = this->head;
        for (int i = 1; i <= place - 1; i++)
        {
            temp = temp->getNext();
        }
        // temp ở vị trị trước vị trí muốn THÊM (tứ là k - 1)
        Node *newNode = new Node(value);
        newNode->setNext(temp->getNext());
        temp->setNext(newNode);
    }
}

void LinkedList::deleteHead()
{
    if (this->head == nullptr)
        return;
    else
    {
        Node *p = this->head;
        this->head = this->head->getNext();
        delete p;
        return;
    }
}

void LinkedList::deleteTail()
{
    // danh sách rỗng
    if (this->head == nullptr)
        return;
    // danh sách có 1 phần tử
    if (this->head == this->tail)
    {
        Node *newNode = new Node;
        newNode = head;
        this->head = nullptr;
        delete newNode;
        tail = head;
        // cout << "Xoa thanh cong. Danh sach rong." << endl;
        return;
    }
    // danh sách có nhiều phần tử
    else
    {
        Node *current = this->head;
        while (current->getNext() != tail)
        {
            current = current->getNext();
        }
        delete this->tail;
        this->tail = current;
        this->tail->setNext(nullptr);
    }
}

void LinkedList::deleteAfter(int place)
{
    // sau place là vị trí cần xóa
    int k = countElList();
    // cout << k << endl; // test
    if (place < 1 || place >= k + 1)
        return; // kết thúc chương trình
    else if (place == 1)
    {
        deleteHead();
        return; // kết thúc chương trình
    }
    else if (place == k)
    {
        deleteTail();
        return; // kết thúc chương trình
    }
    else
    {
        Node *temp = this->head;
        for (int i = 1; i < place - 1; i++)
        {
            temp = temp->getNext();
        }
        // temp ở vị trí trước vị trí muốn XÓA (tứ là k - 1)
        Node *p = temp->getNext();
        temp->setNext(p->getNext());
        delete p;
    }
}

void LinkedList::deleteList()
{
    Node *p = this->head;
    while (p != nullptr)
    {
        this->head = this->head->getNext();
        delete p;
        p = this->head;
    }
}

void LinkedList::deleteNodeX(int value)
{
    if (head == nullptr)
    {
        cout << "Danh sach rong. Khong the xoa." << endl;
        return;
    }

    if (head->getData() == value)
    {
        deleteHead();
    }

    Node *current = head; // current là node cần xóa
    Node *prev = nullptr; // prev là node trước node cần xóa

    while (current != nullptr && current->getData() != value)
    {
        prev = current;
        current = current->getNext();
    }

    if (current == nullptr)
    {
        cout << "Khong tim thay gia tri trong danh sach." << endl;
        return;
    }

    prev->setNext(current->getNext());
    delete current;

    cout << "Xoa thanh cong." << endl;
}

void LinkedList::traval()
{
    Node *p = this->head;
    while (p != nullptr)
    {
        cout << p->getData() << "   ";
        p = p->getNext();
    }
    cout << endl;
}

int LinkedList::countElList()
{
    Node *p = this->head;
    int count = 0;
    while (p != nullptr)
    {
        count++;
        p = p->getNext();
    }
    return count;
}

void LinkedList::printCountElList()
{
    Node *p = this->head;
    int count = 0;
    while (p != nullptr)
    {
        count++;
        p = p->getNext();
    }
    cout << "The total number of nodes in the list is: " << count << endl;
}

LinkedList::~LinkedList()
{
    Node *p = this->head;
    while (p != nullptr)
    {
        this->head = this->head->getNext();
        delete p;
        p = this->head;
    }
}