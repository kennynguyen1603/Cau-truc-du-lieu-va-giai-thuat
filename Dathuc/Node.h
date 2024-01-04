#pragma once
#include <iostream>
using namespace std;
class Node
{
private:
    int heso;
    int somu;
    Node *next;

public:
    Node();
    Node(int heso, int somu);
    // Node(int heso, int somu, Node *next);
    ~Node();
    void setHeso(int heso);
    void setSomu(int somu);
    void setNext(Node *next);
    int getHeso();
    int getSomu();
    Node *getNext();
};