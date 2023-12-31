#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <sstream>
#include <math.h>

using namespace std;

class Product
{
private:
    int id;
    string name;
    string status;
    int quantity;
    double price;
    double total;    // total price of product (price * quantity)
    double discount; // % discount of product
    string category; // category of product

public:
    Product();
    Product(int id, string name, string category, string status, int quantity, double price, double discount);
    ~Product();

    void setId(int id);
    int getId();

    void setName(string name);
    string getName();

    void setCategory(string category);
    string getCategory();

    void setStatus(string status);
    string getStatus();

    void setQuantity(int quantity);
    int getQuantity();

    void setPrice(double price);
    double getPrice();

    void setDiscount(double discount);
    double getDiscount();

    void setTotal(double total);
    double getTotal();

    void input();
    void output();
    void outputToFile(ofstream &file);
    void inputFromFile(ifstream &file);
};