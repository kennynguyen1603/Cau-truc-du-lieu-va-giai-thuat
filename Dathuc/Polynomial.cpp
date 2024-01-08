#include "Polynomial.h"
#include <math.h>

Polynomial::Polynomial()
{
    root = nullptr;
}

Polynomial::~Polynomial()
{
    root = nullptr;
}

void Polynomial::setRoot(Node *root)
{
    this->root = root;
}

Node *Polynomial::getRoot()
{
    return root;
}

void Polynomial::append(int heso, int somu)
{
    Node *node = new Node(heso, somu);
    if (root == nullptr)
    {
        root = node;
    }
    else
    {
        Node *temp = root;
        while (temp->getNext() != nullptr)
        {
            temp = temp->getNext();
        }
        temp->setNext(node);
    }
}

void Polynomial::display()
{
    Node *temp = root;
    bool isFirstTerm = true;
    while (temp != nullptr)
    {
        int heso = temp->getHeso();
        int somu = temp->getSomu();

        // Skip if coefficient is 0
        if (heso == 0)
        {
            temp = temp->getNext();
            continue;
        }

        // Handling the plus sign for non-first terms
        if (!isFirstTerm)
        {
            cout << " + ";
        }
        isFirstTerm = false;

        // Display the term
        if (somu == 0)
        {
            // If exponent is 0, only display the coefficient
            cout << heso;
        }
        else
        {
            // Display the full term
            cout << heso << "x^" << somu;
        }

        temp = temp->getNext();
    }
    if (isFirstTerm)
    {
        // If no term was displayed (all coefficients were 0), display 0
        cout << "0";
    }
    cout << endl;
}

void Polynomial::solve()
{
    int x;
    cout << "Nhap x: ";
    cin >> x;
    Node *temp = root;
    int result = 0;
    while (temp != nullptr)
    {
        result += temp->getHeso() * pow(x, temp->getSomu());
        temp = temp->getNext();
    }
    cout << "Ket qua: " << result << endl;
}

Polynomial Polynomial::add(Polynomial &other)
{
    Polynomial result;
    Node *temp = root;
    Node *tempOther = other.getRoot();
    while (temp != nullptr && tempOther != nullptr)
    {
        if (temp->getSomu() == tempOther->getSomu())
        {
            result.append(temp->getHeso() + tempOther->getHeso(), temp->getSomu());
            temp = temp->getNext();
            tempOther = tempOther->getNext();
        }
        else if (temp->getSomu() > tempOther->getSomu())
        {
            result.append(temp->getHeso(), temp->getSomu());
            temp = temp->getNext();
        }
        else
        {
            result.append(tempOther->getHeso(), tempOther->getSomu());
            tempOther = tempOther->getNext();
        }
    }
    while (temp != nullptr)
    {
        result.append(temp->getHeso(), temp->getSomu());
        temp = temp->getNext();
    }

    while (tempOther != nullptr)
    {
        result.append(tempOther->getHeso(), tempOther->getSomu());
        tempOther = tempOther->getNext();
    }
    return result;
}

// void Polynomial::run()
// {
//     int choice;
//     do
//     {
//         printMenu();
//         cout << "Nhap lua chon: ";
//         cin >> choice;
//         switch (choice)
//         {
//         case 1:
//             int heso, somu;
//             cout << "Nhap he so: ";
//             cin >> heso;
//             cout << "Nhap so mu: ";
//             cin >> somu;
//             append(heso, somu);
//             break;
//         case 2:
//             display();
//             break;
//         case 3:
//             solve();
//             break;
//         case 4:
//             derivative();
//             break;
//         case 5:
//             integral();
//             break;
//         case 6:
//             evaluate();
//             break;
//         case 7:
//             cout << "Thoat chuong trinh" << endl;
//             break;
//         default:
//             cout << "Lua chon khong hop le" << endl;
//             break;
//         }
//     } while (choice != 7);
// }

Polynomial Polynomial::operator+(Polynomial &other)
{
    Polynomial result;
    Node *temp = root;
    Node *tempOther = other.getRoot();
    while (temp != nullptr && tempOther != nullptr)
    {
        if (temp->getSomu() == tempOther->getSomu())
        {
            result.append(temp->getHeso() + tempOther->getHeso(), temp->getSomu());
            temp = temp->getNext();
            tempOther = tempOther->getNext();
        }
        else if (temp->getSomu() > tempOther->getSomu())
        {
            result.append(temp->getHeso(), temp->getSomu());
            temp = temp->getNext();
        }
        else
        {
            result.append(tempOther->getHeso(), tempOther->getSomu());
            tempOther = tempOther->getNext();
        }
    }
    while (temp != nullptr)
    {
        result.append(temp->getHeso(), temp->getSomu());
        temp = temp->getNext();
    }

    while (tempOther != nullptr)
    {
        result.append(tempOther->getHeso(), tempOther->getSomu());
        tempOther = tempOther->getNext();
    }
    return result;
}

Polynomial Polynomial::operator-(Polynomial &other)
{
    Polynomial result;
    Node *temp = this->root;
    Node *tempOther = other.getRoot();
    while (temp != nullptr && tempOther != nullptr)
    {
        if (temp->getSomu() == tempOther->getSomu())
        {
            result.append(temp->getHeso() - tempOther->getHeso(), temp->getSomu());
            temp = temp->getNext();
            tempOther = tempOther->getNext();
        }
        else if (temp->getSomu() > tempOther->getSomu())
        {
            result.append(temp->getHeso(), temp->getSomu());
            temp = temp->getNext();
        }
        else
        {
            result.append(tempOther->getHeso(), tempOther->getSomu());
            tempOther = tempOther->getNext();
        }
    }
    while (temp != nullptr)
    {
        result.append(temp->getHeso(), temp->getSomu());
        temp = temp->getNext();
    }

    while (tempOther != nullptr)
    {
        result.append(tempOther->getHeso(), tempOther->getSomu());
        tempOther = tempOther->getNext();
    }
    return result;
}

void Polynomial::derivative()
{
    Node *temp = root;
    while (temp != nullptr)
    {
        temp->setHeso(temp->getHeso() * temp->getSomu());
        temp->setSomu(temp->getSomu() - 1);
        temp = temp->getNext();
    }
}

void Polynomial::deleteNode(int heso, int somu)
{
    // Neu danh sach rong
    if (root == nullptr)
    {
        cout << "Danh sach rong" << endl;
        return;
    }
    // Neu node can xoa la node dau tien
    if (root->getSomu() == somu && root->getHeso() == heso)
    {
        Node *temp = this->root;
        root = root->getNext();
        delete temp;
        cout << "Xoa thanh cong" << endl;
        return;
    }

    // Neu node can xoa khong phai la node dau tien
    Node *temp = root;    // Node can xoa
    Node *prev = nullptr; // Node truoc node can xoa
    while (temp != nullptr && (temp->getSomu() != somu || temp->getHeso() != heso))
    {
        prev = temp;
        temp = temp->getNext();
    }

    if (temp == nullptr)
    {
        cout << "Khong tim thay phan tu can xoa" << endl;
        return;
    }

    // tim thay node can xoa
    prev->setNext(temp->getNext());
    delete temp;
    cout << "Xoa thanh cong" << endl;
}