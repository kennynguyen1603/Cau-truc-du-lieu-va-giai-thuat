#include "Product.h"

Product::Product()
{
    this->id = 0;
    this->name = "";
    this->status = "";
    this->category = "";
    this->quantity = 0;
    this->price = 0;
    this->discount = 0;
    this->total = price * quantity * (1 - discount / 100);
}

Product::Product(int id, string name, string category, string status, int quantity, double price, double discount)
{
    this->id = id;
    this->name = name;
    this->category = category;
    this->status = status;
    this->quantity = quantity;
    this->price = price;
    this->discount = discount;
    this->total = price * quantity * (1 - discount / 100);
}

Product::~Product()
{
}

void Product::setId(int id)
{
    this->id = id;
}

int Product::getId()
{
    return this->id;
}

void Product::setName(string name)
{
    this->name = name;
}

string Product::getName()
{
    return this->name;
}

void Product::setCategory(string category)
{
    this->category = category;
}

string Product::getCategory()
{
    return this->category;
}

void Product::setStatus(string status)
{
    this->status = status;
}

string Product::getStatus()
{
    return this->status;
}

void Product::setQuantity(int quantity)
{
    this->quantity = quantity;
}

int Product::getQuantity()
{
    return this->quantity;
}

void Product::setPrice(double price)
{
    this->price = price;
}

double Product::getPrice()
{
    return this->price;
}

void Product::setDiscount(double discount)
{
    this->discount = discount;
}

double Product::getDiscount()
{
    return this->discount;
}

void Product::setTotal(double total)
{
    this->total = total;
}

double Product::getTotal()
{
    return this->total;
}

void Product::input()
{
    cout << "Enter id: ";
    cin >> this->id;
    cin.ignore();

    cout << "Enter name: ";
    getline(cin, this->name);

    cout << "Enter category: ";
    getline(cin, this->category);

    cout << "Enter status: ";
    getline(cin, this->status);

    cout << "Enter quantity: ";
    cin >> this->quantity;

    cout << "Enter price: ";
    cin >> this->price;

    cout << "Enter discount: ";
    cin >> this->discount;

    this->total = this->quantity * this->price * (1 - this->discount / 100);
}

void Product::output()
{
    cout << setw(5) << this->id << setw(20) << this->name << setw(20) << this->category << setw(20) << this->status << setw(10) << this->quantity << setw(10) << this->price << setw(10) << this->discount << setw(10) << this->total << endl;
}

void Product::outputToFile(ofstream &file)
{
    file << this->id << endl;
    file << this->name << endl;
    file << this->status << endl;
    file << this->quantity << endl;
    file << this->price << endl;
    file << this->discount << endl;
    file << this->total << endl;
}

void Product::inputFromFile(ifstream &file)
{
    file >> this->id;
    file.ignore();

    getline(file, this->name);

    getline(file, this->status);

    file >> this->quantity;

    file >> this->price;

    file >> this->discount;

    file >> this->total;
}
