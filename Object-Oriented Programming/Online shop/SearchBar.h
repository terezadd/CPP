#ifndef SEARCHBAR_H_INCLUDED
#define SEARCHBAR_H_INCLUDED

#include <iostream>
#include <string>
#include "Product.h"
using namespace std;

class SearchBar
{
private:
    string searchedItem;

public:
    SearchBar();

    void readProduct();
    void showProduct(Product matchedProduct) const;

    string getSearchedItem() const;
    void setSearchedItem(string searchedItem);

};

#endif // SEARCHBAR_H_INCLUDED
