// #include "Product.h"
// #include "ProductBSTNode.h"
#include "ProductBST.h"
#include <iostream>

using namespace std;
int main()
{
    ProductBST bst;

    // Example: Manually adding products to the BST
    Product milk(1, "Milk", "Food", "Available", 10, 20.0, 0.0);
    Product bread(2, "Bread", "Food", "Sold out", 5, 15.0, 0.0);
    Product eggs(3, "Eggs", "Food", "Available", 30, 5.0, 0.0);

    bst.insert(&milk);
    bst.insert(&bread);
    bst.insert(&eggs);

    // Display products
    cout << "All Products:" << endl;
    bst.display();

    // Count products
    cout << "\nTotal number of products: " << bst.countProduct() << endl;

    // Search for a product
    cout << "\nSearching for product ID 1:" << endl;
    bst.search(1);

    // Display available products
    cout << "\nAvailable Products:" << endl;
    bst.displayAvailable();

    // Delete sold out products and display updated list
    bst.deleteSoldOut();
    cout << "\nProducts after deleting sold out items:" << endl;
    bst.display();

    return 0;
}