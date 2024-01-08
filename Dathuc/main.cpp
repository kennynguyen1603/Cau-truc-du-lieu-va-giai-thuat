#include "Node.h"
#include "Polynomial.h"
#include <iostream>
using namespace std;
int main()
{
    // Polynomial polynomial;
    // polynomial.append(1, 2);
    // polynomial.append(2, 1);
    // polynomial.append(3, 0);
    // polynomial.display();

    Polynomial polynomial2;
    polynomial2.append(1, 2);
    polynomial2.append(2, 1);
    polynomial2.append(3, 0);
    polynomial2.display();

    // Polynomial result = polynomial.add(polynomial2);
    // result.display();
    // // result.solve();

    // Polynomial result2;
    // result2 = polynomial + polynomial2; // 2x^2 + 4x^1 + 6
    // result2.derivative();               // đạo hàm (4x^1 + 4)
    // result2.display();

    // Polynomial result3;
    // result3 = polynomial - polynomial2; // 0
    // result3.display();

    polynomial2.deleteNode(2, 2);
    polynomial2.display();

    polynomial2.deleteNode(2, 1);
    cout << "Da thuc sau khi xoa node la: ";
    polynomial2.display();

    return 0;
}