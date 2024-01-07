#include "Node.h"

class LinkedList
{
private:
    Node *head;
    Node *tail;

public:
    LinkedList();           // constructor
    virtual ~LinkedList();  // destructor
    void creatLinkedlist(); // tạo danh sách liên kết

    // các hàm insert
    // void insertHead(Node *);    // thêm vào đầu danh sách
    void insertTail(Node *); // thêm vào cuối danh sách
    // void insertAfter(int, int); // thêm vào sau 1 node

    void appendList(int val);

    void deleteNodeX(int); // xóa các node có giá trị x

    void deleteList(); // xóa danh sách

    int length(); // độ dài danh sách

    void displayList(); // hiển thị danh sách

    void removeDuplicates(); // xóa các node trùng nhau

    // void swapEvenOdd(LinkedList &A, LinkedList &B); // đổi chỗ các node chẵn với các node lẻ
    void swapEvenOdd(LinkedList &other);
};