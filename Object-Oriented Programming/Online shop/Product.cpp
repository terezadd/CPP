#include <iostream>
#include <string>
#include "Product.h"

using namespace std;


//constructors and destructor
Product::Product()
{
    name = "";
    ID = 0;
    price = 0.0;
    numbersAvailable = 0;
    inStock = false;

}

Product::Product(string name, int ID, double price, int numbersAvailable, bool inStock)
{
    this->name = name;
    this->ID = ID;
    this->price = price;
    this->numbersAvailable = numbersAvailable;
    this->inStock = inStock;
}

void Product::checkInStock()
{
    if(getNumbersAvailable()>0)
    {
        setInStock(true);
    }
    else
    {
        setInStock(false);
    }
}

void Product::printProduct() const
{
    cout<<"Product name: "<<name<<endl;
    cout<<"ID: "<<ID<<endl;
    cout<<"Price: "<<price<<endl;
    cout<<"Numbers available: "<<numbersAvailable<<endl;
    cout<<"In stock: ";
    if(getInStock()==true){
        cout<<"Yes."<<endl;
    }
    else cout<<"No."<<endl;
}

//getters and setters
void Product::setName(string name)
{
    this->name = name;
}

string Product::getName() const
{
    return name;
}

void Product::setPrice(double price)
{
    this->price = price;
}

double Product::getPrice() const
{
    return price;
}

void Product::setNumbersAvailable(int numbersAvailable)
{
    this->numbersAvailable = numbersAvailable;
}

int Product::getNumbersAvailable() const
{
    return numbersAvailable;
}

void Product::setInStock(bool inStock)
{
    this->inStock = inStock;
}

bool Product::getInStock() const
{
    return inStock;
}

int Product::getID() const{
    return ID;
}

bool Product::operator==(const Product& other) const{
    if(name==other.name && ID==other.ID && price==other.price && numbersAvailable == other.numbersAvailable && inStock==other.inStock){
        return true;
    }
    return false;
}
