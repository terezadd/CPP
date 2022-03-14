#include "Books.h"
#include <iostream>
#include <string>
using namespace std;

Books::Books() : Product(){
    review = "";
    category = "books";
}

Books::Books(string name, int ID, double price, int numbersAvailable, bool inStock, string review) : Product(name, ID, price, numbersAvailable, inStock){
    this->review = review;
    this->category = "books";
}

void Books::printProduct() const{
    cout<<"Category: "<<category<<endl;
    Product::printProduct();
    cout<<"Review: "<<review<<endl<<endl;
}

string Books::getCategory() const{
    return category;
}

