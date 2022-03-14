#include <iostream>
#include "SearchBar.h"


SearchBar::SearchBar()
{
    searchedItem = " ";
}


void SearchBar::readProduct(){
    cout<<"Search: ";
    cin>>searchedItem;
}

void SearchBar::showProduct(Product matchedProduct) const
{
    matchedProduct.printProduct();
}


//getters and setters
string SearchBar::getSearchedItem() const
{
    return searchedItem;
}

void SearchBar::setSearchedItem(string searchedItem)
{
    this->searchedItem = searchedItem;
}


