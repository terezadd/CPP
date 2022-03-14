#ifndef PROVERKA_H_INCLUDED
#define PROVERKA_H_INCLUDED

#include <cstring>

using namespace std;

class User{
private:
    string email;
    string username;
    string password;
    string address;

public:
    User();
    User(string email, string username, string password, string address);

    void registration();
    int chooseHowToPay() const;
    void print() const;

    void setEmail(string email);
    string getEmail() const;
    void setUsername(string username);
    string getUsername() const;
    void setPassword(string password);
    string getPassword() const;
    void setAddress(string address);
    string getAddress() const;

};


#endif // PROVERKA_H_INCLUDED
