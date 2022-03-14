#ifndef CLOTHES_H_INCLUDED
#define CLOTHES_H_INCLUDED

#include <string>
#include "Product.h"
using namespace std;

class Clothes : public Product{
private:
    char sizeClothes;
    string category;
public:
    Clothes();
    Clothes(string name, int ID, double price, int numbersAvailable, bool inStock, char sizeClothes);

    void printProduct() const;
    string getCategory() const;
};


#endif // CLOTHES_H_INCLUDED
