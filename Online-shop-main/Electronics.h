#ifndef ELECTRONICS_H_INCLUDED
#define ELECTRONICS_H_INCLUDED

#include <string>
#include "Product.h"
using namespace std;

class Electronics : public Product{
private:
    string brand;
    string category;
public:
    Electronics();
    Electronics(string name, int ID, double price, int numbersAvailable, bool inStock, string brand);

    void printProduct() const;
    string getCategory() const;
};


#endif // ELECTRONICS_H_INCLUDED
