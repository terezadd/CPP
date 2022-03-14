#include <iostream>
#include <vector>
#include <algorithm>
#include "ShoppingCart.h"
using namespace std;

//constructor
ShoppingCart::ShoppingCart()
{
    addedProducts = vector<Product *>();
    numberOfAddedProducts = vector<int>();
    number_addedProducts = 0;
}

void ShoppingCart::addToCart(Product& product)
{
    if(product.getNumbersAvailable()<=0)
    {
        cerr<<"There is no enough quantity of this product!"<<endl;
    }
    else
    {
        int position = -1;
        for(int i=0; i<addedProducts.size(); i++)
        {
            if(addedProducts[i]==&product)
            {
                position = i;
            }
        }
        if(position != -1)
        {
            ++number_addedProducts;
            ++numberOfAddedProducts[position];
            addedProducts[position]->setNumbersAvailable(addedProducts[position]->getNumbersAvailable() - 1);
        }
        else
        {
            addedProducts.push_back(&product);
            ++number_addedProducts;
            numberOfAddedProducts.push_back(1);
            addedProducts.back()->setNumbersAvailable(addedProducts.back()->getNumbersAvailable() - 1);
        }
    }

}

void ShoppingCart::removeProduct(Product product)
{
    int position = -1;
    for(int i=0; i<addedProducts.size(); i++)
    {
        if(*addedProducts[i]==product)
        {
            position = i;
        }
    }
    if(position != -1)
    {
        if(numberOfAddedProducts[position]==1)
        {
            addedProducts.erase(addedProducts.begin() + position);
            --number_addedProducts;
            numberOfAddedProducts.erase(numberOfAddedProducts.begin() + position);
            addedProducts[position]->setNumbersAvailable(addedProducts[position]->getNumbersAvailable() + 1);
        }
        else
        {
            --number_addedProducts;
            --numberOfAddedProducts[position];
            addedProducts[position]->setNumbersAvailable(addedProducts[position]->getNumbersAvailable() + 1);
        }
    }
}

double ShoppingCart::showFinalPrice() const
{
    if(addedProducts.empty())
    {
        return 0;
    }
    else
    {
        double finalPrice;

        for(int i=0; i<addedProducts.size(); i++)
        {
            finalPrice += addedProducts[i]->getPrice() * numberOfAddedProducts[i];
        }

        return finalPrice;
    }

}

void ShoppingCart::finishOrder()
{
    cout<<"Your order is finished!"<<endl;

    /*for(int i=0; i<addedProducts.size(); i++)
    {
        addedProducts[i]->setNumbersAvailable(addedProducts[i]->getNumbersAvailable() - numberOfAddedProducts[i]);
        if(addedProducts[i]->getNumbersAvailable()<0)
        {
            addedProducts[i]->setNumbersAvailable(0);
        }
        addedProducts[i]->checkInStock();
    }*/

    addedProducts.clear();
    numberOfAddedProducts.clear();
    number_addedProducts = 0;
}

void ShoppingCart::showProductsToBuy() const
{
    if(addedProducts.empty()==true)
    {
        cout<<endl<<"The shopping cart is empty!"<<endl;
    }
    else
    {
        for(int i=0; i<addedProducts.size(); i++)
        {
            cout<<endl;
            addedProducts[i]->printProduct();
            cout<<"Numbers added of the product: "<<numberOfAddedProducts[i]<<endl<<endl;
        }
    }

}

//getters and setters
int ShoppingCart::getNumber_addedProduct() const
{
    return number_addedProducts;
}

