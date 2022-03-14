#include "Clothes.h"
#include <iostream>
#include <string>
using namespace std;

Clothes::Clothes() : Product(){
    sizeClothes = ' ';
    category = "clothes";
}

Clothes::Clothes(string name, int ID, double price, int numbersAvailable, bool inStock, char sizeClothes) : Product(name, ID, price, numbersAvailable, inStock){
    this->sizeClothes = sizeClothes;
    this->category = "clothes";
}

void Clothes::printProduct() const{
    cout<<"Category: "<<category<<endl;
    Product::printProduct();
    cout<<"Size: "<<sizeClothes<<endl<<endl;
}

string Clothes::getCategory() const{
    return category;
}

