#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

#include "User.h"
#include "Shop.h"
#include "Books.h"
#include "Clothes.h"
#include "Electronics.h"
#include "ShoppingCart.h"
#include "SearchBar.h"

using namespace std;
int main()
{
    Shop Fantastic;
    ShoppingCart cart;
    SearchBar searchBar;
    User Pesho, Gosho("Gosho@abv.bg","Gosho","123456","Sofia");
    Fantastic.fillAllUsers(Gosho);

    cout<<"Welcome to store Fantastic!"<<endl<<endl;
    cout<<"You should log in to your account first!"<<endl<<endl;
    cout<<"Do you have a profile? ";
    string input;
    cin>>input;

    while(input!="no" && input!="No" && input != "Yes" && input != "yes")
    {
        cerr<<"You should enter \"yes\" or \"no\"!"<<endl;
        cin>>input;
    }

    if(input=="no" || input=="No")
    {
        cout<<"You should make a registration."<<endl<<endl;
        Pesho.registration();
        Fantastic.fillAllUsers(Pesho);
        cout<<endl<<endl;

    }
    else if(input == "yes" || input=="Yes")
    {
        cout<<"Enter your username and password."<<endl<<endl;
        while(Fantastic.login()==false)
        {
            cout<<"Wrong username or password!"<<endl;
        }
        Pesho = Gosho;
        cout<<endl<<endl;
    }


    //products

    Books GameOfThrones("GameOfThrones", 111, 25.90, 15, 1, "Everyone dies!"), PaperTowns("PaperTowns", 125, 12.90, 7, 1, "It's John Green!");
    Fantastic.fillAllProducts(GameOfThrones);
    Fantastic.fillAllProducts(PaperTowns);

    Clothes dress("Dress", 632, 19.99, 7, 1, 'S'), shirt("T-shirt", 628, 10.90, 5, 1, 'M');
    Fantastic.fillAllProducts(dress);
    Fantastic.fillAllProducts(shirt);

    Electronics smartphone("Smartphone", 561, 259, 1, 1, "Samsung"), laptop("Laptop", 589, 629.99, 2, 1, "Acer");
    Fantastic.fillAllProducts(smartphone);
    Fantastic.fillAllProducts(laptop);


LOOP:
    cout<<endl<<"What action do you want to take?"<<endl;
    cout<<"    1.Take a look at the products."<<endl<<"    2.Search for a product."<<endl<<"    3.Check the shopping cart."<<endl;
    cout<<"If you want to close the program, enter \"exit\"."<<endl;
    cin>>input;

    if(input=="exit")
    {
        return 0;
    }

    if(input == "1")
    {
        cout<<endl;
        int whatToShow = Fantastic.chooseWhatToShow();
        while(whatToShow == -1)
        {
            cout<<"Try again!"<<endl;
            whatToShow = Fantastic.chooseWhatToShow();
        }
        cout<<endl;
        int howToShow = Fantastic.chooseHowToShow();
        while(howToShow == -1)
        {
            cout<<"Try again!"<<endl;
            howToShow = Fantastic.chooseHowToShow();
        }
        cout<<endl;

        if(whatToShow == 1 && howToShow == 1)
        {
            //all, AO
            Fantastic.showAscendingOrderPrice("all");

        }
        if(whatToShow == 1 && howToShow == 2)
        {
            //all, DO
            Fantastic.showDescendingOrderPrice("all");
        }
        if(whatToShow == 1 && howToShow == 3)
        {
            //all, random
            Fantastic.showAll("all");
        }
        if(whatToShow == 2 && howToShow == 1)
        {
            //books, AO
            Fantastic.showAscendingOrderPrice("books");

        }
        if(whatToShow == 2 && howToShow == 2)
        {
            //books, DO
            Fantastic.showDescendingOrderPrice("books");
        }
        if(whatToShow == 2 && howToShow == 3)
        {
            //books, random
            Fantastic.showAll("books");
        }
        if(whatToShow == 3 && howToShow == 1)
        {
            //clothes, AO
            Fantastic.showAscendingOrderPrice("clothes");

        }
        if(whatToShow == 3 && howToShow == 2)
        {
            //clothes, DO
            Fantastic.showDescendingOrderPrice("clothes");
        }
        if(whatToShow == 3 && howToShow == 3)
        {
            //clothes, random
            Fantastic.showAll("clothes");
        }
        if(whatToShow == 4 && howToShow == 1)
        {
            //electronics, AO
            Fantastic.showAscendingOrderPrice("electronics");

        }
        if(whatToShow == 4 && howToShow == 2)
        {
            //electronics, DO
            Fantastic.showDescendingOrderPrice("electronics");
        }
        if(whatToShow == 4 && howToShow == 3)
        {
            //electronics, random
            Fantastic.showAll("electronics");
        }

        cout<<"Do you want to buy something? ";
        cin>>input;
        while(input!="no" && input!="No" && input != "Yes" && input != "yes")
        {
            cerr<<"You should enter \"yes\" or \"no\"!"<<endl;
            cin>>input;
        }
        if(input == "No" || input == "no")
        {
            goto LOOP;
        }
        if(input == "Yes" || input == "yes")
        {
            cout<<endl;
LOOP_toBuy:
            cout<<"Enter the name of the product to buy: ";
            cin>>input;
            cart.addToCart(Fantastic.stringToProduct(input));

            cout<<"Do you want to buy anything else? ";
            cin>>input;
            while(input!="no" && input!="No" && input != "Yes" && input != "yes")
            {
                cerr<<"You should enter \"yes\" or \"no\"!"<<endl;
                cin>>input;
            }
            if(input == "No" || input == "no")
            {
                goto LOOP;
            }
            if(input == "Yes" || input == "yes")
            {
                goto LOOP_toBuy;
            }
        }
    }

    else if(input == "2")
    {
        cout<<endl;
        searchBar.readProduct();
        cout<<endl<<"The product is: "<<endl;
        searchBar.showProduct(Fantastic.stringToProduct(searchBar.getSearchedItem()));
        cout<<"Do you want to buy this product? ";
        cin>>input;
        while(input!="no" && input!="No" && input != "Yes" && input != "yes")
        {
            cerr<<"You should enter \"yes\" or \"no\"!"<<endl;
            cin>>input;
        }
        if(input == "No" || input == "no")
        {
            goto LOOP;
        }
        if(input == "Yes" || input == "yes")
        {
            cart.addToCart(Fantastic.stringToProduct(searchBar.getSearchedItem()));
            goto LOOP;
        }
    }

    else if(input == "3")
    {
        cout<<endl<<"The products in the shopping cart are: "<<endl<<endl;
        cart.showProductsToBuy();
        cout<<endl<<"The total price is "<<cart.showFinalPrice()<<"."<<endl;

LOOP_cart:
        cout<<endl<<"Now you can: "<<endl<<"    1.Buy the products"<<endl<<"    2.Remove a product"<<endl<<"    3.Go back to the main menu"<<endl;
        cout<<"Write your answer: ";
        cin>>input;

        if(input == "1"){
            int payment = Pesho.chooseHowToPay();
            if(payment == 1){
                cout<<"Please insert card information: ";
                cin>>input;
            }
            else if(payment == 2){
                int paypal;
                paypal = rand() % 99999 + 10000;
                cout<<"The paypal code is "<<paypal<<" and you have 24 hours to pay the full amount at a counter."<<endl;
            }

            cout<<endl<<"The packet will be sent at "<<Pesho.getAddress()<<" between 2 and 5 working days."<<endl;
            if(payment == 3){
                cout<<"You will pay the full amount when delivery. "<<endl;
            }
            cout<<endl;
            cart.finishOrder();
            cout<<endl;
            goto LOOP;

        }
        else if(input == "2"){
            cout<<endl<<"What product do you want to remove from your shopping cart? Please enter its name. ";
            cin>>input;
            cart.removeProduct(Fantastic.stringToProduct(input));
            cout<<"It is removed. Now the products in your shopping cart are: "<<endl;
            cart.showProductsToBuy();
            goto LOOP_cart;

        }
        else if(input == "3"){
            goto LOOP;
        }
        else{
            cout<<"Try again! You should enter a number between 1, 2 or 3."<<endl;
            goto LOOP_cart;
        }
    }
    else
    {
        cerr<<"Try again! Enter a number between 1, 2, 3 or type \"exit\"."<<endl<<endl;
        goto LOOP;
    }


    return 0;
}
