#ifndef SHOPPINGCART_H_INCLUDED
#define SHOPPINGCART_H_INCLUDED

#include <vector>
#include "Product.h"

class ShoppingCart {
private:
    vector<Product *> addedProducts;
    vector<int> numberOfAddedProducts;
    int number_addedProducts;

public:
    ShoppingCart();

    void addToCart(Product& product);
    void removeProduct(Product product);
    double showFinalPrice() const;
    void finishOrder(); //finishing the order and emptying the cart
    void showProductsToBuy() const;

    int getNumber_addedProduct() const;

};


#endif // SHOPPINGCART_H_INCLUDED

