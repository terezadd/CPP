#ifndef SHOP_H_INCLUDED
#define SHOP_H_INCLUDED

#include <vector>
#include "Product.h"
#include "User.h"
using namespace std;

class Shop{
private:
    vector<Product *> allProducts;
    int number_products;
    vector<User> allUsers;


public:
    Shop();

    bool login() const;

    void fillAllUsers(User user);
    void fillAllProducts(Product& product);
    void printAllUsers() const;
    void printAllProducts() const;

    int chooseHowToShow() const;
    int chooseWhatToShow() const;
    void showAll(string input) const;
    void showAscendingOrderPrice(string category);
    void showDescendingOrderPrice(string category);

    Product& stringToProduct(string searchedItem) const;
    int getNumberOfProducts() const;
};

#endif // SHOP_H_INCLUDED
