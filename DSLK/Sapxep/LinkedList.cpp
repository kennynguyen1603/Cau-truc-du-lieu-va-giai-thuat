#include "LinkedList.h"
#include <unordered_map>

LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}

LinkedList::~LinkedList()
{
}

void LinkedList::creatLinkedlist()
{
    this->head = nullptr;
    this->tail = nullptr;
}

// void LinkedList::insertHead(Node *node)
// {
//     if (this->head == nullptr)
//     {
//         this->head = node;
//         this->tail = node;
//     }
//     else
//     {
//         node->setNext(this->head);
//         this->head = node;
//     }
// }

// void LinkedList::insertAfter(int x, int y)
// {
//     Node *p = this->head;
//     while (p != nullptr)
//     {
//         if (p->getData() == x)
//         {
//             Node *node = new Node(y);
//             node->setNext(p->getNext());
//             p->setNext(node);
//             if (p == this->tail)
//             {
//                 this->tail = node;
//             }
//             return;
//         }
//         p = p->getNext();
//     }
// }

void LinkedList::insertTail(Node *node)
{
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

void LinkedList::appendList(int val)
{
    Node *node = new Node(val);
    this->insertTail(node);
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
        Node *temp = head;
        head = head->getNext();
        delete temp;
        // cout << "Xoa thanh cong." << endl;
        return;
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
        // cout << "Khong tim thay gia tri trong danh sach." << endl;
        return;
    }

    prev->setNext(current->getNext());
    delete current;
    // cout << "Xoa thanh cong." << endl;
}

void LinkedList::deleteList()
{
    Node *current = head;
    while (current != nullptr)
    {
        Node *temp = current;
        current = current->getNext();
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
}

int LinkedList::length()
{
    int count = 0;
    Node *p = this->head;
    while (p != nullptr)
    {
        count++;
        p = p->getNext();
    }
    return count;
}

void LinkedList::displayList()
{
    Node *p = this->head;
    while (p != nullptr)
    {
        cout << p->getData() << " ";
        p = p->getNext();
    }
    cout << endl;
}

void LinkedList::removeDuplicates()
{
    if (head == nullptr || head->getNext() == nullptr)
    {
        return; // Không có gì để xóa nếu danh sách rỗng hoặc chỉ có một phần tử.
    }

    std::unordered_map<int, bool> seen;
    Node *current = head;
    Node *prev = nullptr;
    while (current != nullptr)
    {
        if (seen[current->getData()])
        {
            // Giá trị đã được thấy trước đó, xóa node hiện tại.
            prev->setNext(current->getNext());
            delete current;            // Giải phóng bộ nhớ của node hiện tại.
            current = prev->getNext(); // Tiếp tục với node tiếp theo.
        }
        else
        {
            // Đánh dấu giá trị như đã thấy và di chuyển prev và current.
            seen[current->getData()] = true;
            prev = current;
            current = current->getNext();
        }
    }
}

void LinkedList::swapEvenOdd(LinkedList &other)
{
    Node *p = this->head;
    Node *q = other.head;
    LinkedList tempA;
    LinkedList tempB;
    while (p != nullptr && q != nullptr)
    {
        if (p->getData() % 2 == 0)
            tempA.appendList(p->getData());
        else
            tempB.appendList(p->getData());

        if (q->getData() % 2 == 0)
            tempA.appendList(q->getData());
        else
            tempB.appendList(q->getData());

        p = p->getNext();
        q = q->getNext();
    }

    // xóa các node trùng nhau
    tempA.removeDuplicates();
    tempB.removeDuplicates();

    // xóa danh sách cũ
    this->deleteList();
    other.deleteList();

    // gán danh sách mới
    while (tempA.head != nullptr)
    {
        this->insertTail(tempA.head);
        tempA.head = tempA.head->getNext();
    }

    while (tempB.head != nullptr)
    {
        other.insertTail(tempB.head);
        tempB.head = tempB.head->getNext();
    }

    // xóa danh sách tạm
    tempA.deleteList();
    tempB.deleteList();
}