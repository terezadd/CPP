#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    string name;
    int ID;
    double price;
    int numbersAvailable;
    bool inStock;

public:
    Product();
    Product(string name, int ID, double price, int numbersAvailable, bool inStock);

    void checkInStock();
    virtual void printProduct() const;

    void setName(string name);
    string getName() const;
    void setPrice(double price);
    double getPrice() const;
    void setNumbersAvailable(int numbersAvailable);
    int getNumbersAvailable() const;
    void setInStock(bool inStock);
    bool getInStock() const;
    int getID() const;

    string getCategory(){}

    bool operator==(const Product& other) const;


};

#endif // PRODUCT_H_INCLUDED
