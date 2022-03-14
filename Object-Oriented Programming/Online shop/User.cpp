#include <iostream>
#include "User.h"
using namespace std;

//constructors and destructor
User::User()
{
    email = '\0';
    username = '\0';
    password = '\0';
    address = '\0';
}

User::User(string email, string username, string password, string address)
{
    this->email = email;
    this->username = username;
    this->password = password;
    this->address = address;
}


void User::registration()
{
    cout<<"Email: ";
    cin>>email;

    cout<<"Username: ";
    cin>>username;

    cout<<"Password: ";
    cin>>password;

    cout<<"Address: ";
    cin>>address;

}

int User::chooseHowToPay() const
{
    int payment = 0;

    cout<<endl<<"Choose how to pay: \n 1.Card\n 2.Paypal\n 3.Cash when delivery\n";
    cin>>payment;

    return payment;
}

void User::print() const{
    cout<<endl;
    cout<<"Email: "<<email<<endl;
    cout<<"Username: "<<username<<endl;
    cout<<"Password: "<<password<<endl;
    cout<<"Address: "<<address<<endl;
}

//getters and setters
void User::setEmail(string email)
{
    this->email = email;
}

string User::getEmail() const
{
    return email;
}

void User::setUsername(string username)
{
    this->username = username;
}

string User::getUsername() const
{
    return username;
}

void User::setPassword(string password)
{
    this->password = password;
}

string User::getPassword() const
{
    return password;
}

void User::setAddress(string address)
{
    this->address = address;
}

string User::getAddress() const
{
    return address;
}

