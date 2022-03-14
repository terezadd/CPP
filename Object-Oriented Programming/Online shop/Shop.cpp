#include <iostream>
#include "Shop.h"

using namespace std;

Shop::Shop(){
    allProducts = vector<Product *>();
    number_products = 0;
    allUsers = vector<User>();
}

bool Shop::login() const
{
    string inputName, inputPass;
    cout<<"Username: ";
    cin>>inputName;

    cout<<"Password: ";
    cin>>inputPass;


    for(int i=0; i<allUsers.size(); i++)
    {
        if(inputName==allUsers[i].getUsername() && inputPass==allUsers[i].getPassword())
        {
            return true;
        }
    }

    return false;
}

void Shop::fillAllUsers(User user)
{
    allUsers.push_back(user);
}

void Shop::fillAllProducts(Product& product)
{
    allProducts.push_back(&product);
    ++number_products;
}


void Shop::printAllUsers() const
{
    for(int i=0; i<allUsers.size(); i++)
    {
        allUsers[i].print();
        cout<<endl<<endl;
    }
}

void Shop::printAllProducts() const
{
    for(int i=0; i<allProducts.size(); i++)
    {
        allProducts[i]->printProduct();
        cout<<endl<<endl;
    }
}

int Shop::chooseWhatToShow() const
{
    int whatToShow;
    cout<<"What products do you want to see?"<<endl<<"   1.All products"<<endl<<"   2.Books"<<endl<<"   3.Clothes"<<endl<<"   4.Electronics"<<endl;
    cout<<"Write your answer: ";
    cin>>whatToShow;
    if(!cin)
    {
        return -1;
    }
    else
    {
        return whatToShow;
    }
}

int Shop::chooseHowToShow() const
{
    int howToShow;
    cout<<"Show in: "<<endl<<"    1.Ascending order by price"<<endl<<"    2.Descending order by price"<<endl<<"    3.Randomly"<<endl;
    cout<<"Write your answer: ";
    cin>>howToShow;
    if(!cin)
    {
        return -1;
    }
    else
    {
        return howToShow;
    }
}

void Shop::showAll(string input) const
{
    if(input == "all")
    {
        this->printAllProducts();
    }
    else
    {
        cout<<"IT IS NOT WORKING FOR THE CATEGORIES, ONLY FOR ALL PRODUCTS!! The problem is with getCategory()."<<endl;

        for(int i=0; i<allProducts.size(); i++)
        {
            if(allProducts[i]->getCategory() == input)
            {
                allProducts[i]->printProduct();
                cout<<endl;
            }
        }
        cout<<"Ended here!!"<<endl;
    }

}

void Shop::showAscendingOrderPrice(string category)
{
    for(int i=0; i<allProducts.size(); i++){
        for(int j=0; j<allProducts.size()-i-1; j++){
            if(allProducts[j]->getPrice()>allProducts[j+1]->getPrice()){
                swap(allProducts[j], allProducts[j+1]);
            }
        }
    }
    if(category == "all")
    {
        this->printAllProducts();
    }
    else
    {
        cout<<"IT IS NOT WORKING FOR THE CATEGORIES, ONLY FOR ALL PRODUCTS!! The problem is with getCategory()."<<endl;
        for(int i=0; i<allProducts.size(); i++)
        {
            if(allProducts[i]->getCategory()==category)
            {
                allProducts[i]->printProduct();
                cout<<endl;
            }

        }
    }
}

void Shop::showDescendingOrderPrice(string category)
{
    for(int i=0; i<allProducts.size(); i++){
        for(int j=0; j<allProducts.size()-i-1; j++){
            if(allProducts[j]->getPrice()<allProducts[j+1]->getPrice()){
                swap(allProducts[j], allProducts[j+1]);
            }
        }
    }
    if(category == "all")
    {
        this->printAllProducts();
    }
    else
    {
        cout<<"IT IS NOT WORKING FOR THE CATEGORIES, ONLY FOR ALL PRODUCTS!! The problem is with getCategory()."<<endl;
        for(int i=0; i<allProducts.size(); i++)
        {
            if(allProducts[i]->getCategory() == category)
            {
                allProducts[i]->printProduct();
                cout<<endl;
            }

        }
    }
}

Product& Shop::stringToProduct(string searchedItem) const{
    bool isMatched = false;
    for(int i=0; i<allProducts.size(); i++)
    {
        if(searchedItem == allProducts[i]->getName()){
            isMatched = true;
            return *allProducts[i];
        }
    }
    if(isMatched == false){
        cerr<<"There is no such product!"<<endl;
    }
}

int Shop::getNumberOfProducts() const{
    return number_products;
}
