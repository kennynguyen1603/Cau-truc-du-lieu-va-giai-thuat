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
    void insertHead(Node *);    // thêm vào đầu danh sách
    void insertTail(Node *);    // thêm vào cuối danh sách
    void insertAfter(int, int); // thêm vào sau 1 node

    // các hàm delete
    void deleteHead();           // xóa đầu danh sách
    void deleteTail();           // xóa cuối danh sách
    void deleteAfter(int place); // xóa node tại vị trí place
    void deleteList();           // xóa toàn bộ danh sách
    void deleteNodeX(int);       // xóa các node có giá trị x

    void traval();           // duyệt danh sách
    int countElList();       // đếm số phần tử trong danh sách
    void printCountElList(); // in ra số phần tử trong danh sách
};