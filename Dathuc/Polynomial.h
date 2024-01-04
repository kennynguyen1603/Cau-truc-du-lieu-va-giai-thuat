#include "Node.h"

class Polynomial
{
private:
    Node *root;

public:
    Polynomial();
    ~Polynomial();
    void setRoot(Node *root);
    Node *getRoot();
    void append(int heso, int somu);
    void display();
    void solve();
    Polynomial add(Polynomial &other);
    //
    void derivative(); // đạo hàm
    // void integral(); // tích phân (chưa làm)
    // void printMenu();
    // void run();
    Polynomial operator+(Polynomial &other); // cộng 2 đa thức
    Polynomial operator-(Polynomial &other); // trừ 2 đa thức
};