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

    void traval(); // duyệt và in danh sách

    int countElList();       // đếm số phần tử trong danh sách
    void printCountElList(); // in ra số phần tử trong danh sách

    int sumElList();       // tính tổng các phần tử trong danh sách
    void printSumElList(); // in ra tổng các phần tử trong danh sách

    int maxElList();       // tìm giá trị lớn nhất trong danh sách
    void printMaxElList(); // in ra giá trị lớn nhất trong danh sách

    int minElList();       // tìm giá trị nhỏ nhất trong danh sách
    void printMinElList(); // in ra giá trị nhỏ nhất trong danh sách

    void sortElList(); // sắp xếp danh sách tăng dần
    void reverse();    // đảo ngược danh sách

    void printElList(int); // in ra phần tử tại vị trí place

    // các hàm tìm kiếm
    int searchX(int); // tìm kiếm phần tử x trong danh sách
    void printSearchX(int);

    // các hàm khác
    void swapNode(Node *, Node *); // đổi chỗ 2 node
    void swapData(Node *, Node *); // đổi chỗ 2 data
};