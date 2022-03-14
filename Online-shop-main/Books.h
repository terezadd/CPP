#ifndef BOOKS_H_INCLUDED
#define BOOKS_H_INCLUDED


#include <string>
#include "Product.h"
using namespace std;

class Books : public Product{
private:
    string review;
    string category;
public:
    Books();
    Books(string name, int ID, double price, int numbersAvailable, bool inStock, string review);

    void printProduct() const;
    string getCategory() const;
};

#endif // BOOKS_H_INCLUDED
