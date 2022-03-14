#include "Electronics.h"
#include <iostream>
#include <string>
using namespace std;

Electronics::Electronics() : Product(){
    brand = "";
    category = "electronics";
}

Electronics::Electronics(string name, int ID, double price, int numbersAvailable, bool inStock, string brand) : Product(name, ID, price, numbersAvailable, inStock){
    this->brand = brand;
    this->category = "electronics";
}

void Electronics::printProduct() const{
    cout<<"Category: "<<category<<endl;
    Product::printProduct();
    cout<<"Brand: "<<brand<<endl<<endl;
}

string Electronics::getCategory() const{
    return category;
}


