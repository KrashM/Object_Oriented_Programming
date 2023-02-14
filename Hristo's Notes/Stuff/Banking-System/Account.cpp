#include "Account.hpp"

Account::Account(): amount(0), dateOfCreation(0), username(nullptr), password(nullptr), iban(nullptr), id(0){}
Account::Account(const double amount, const Date &dateOfCreation, const char *username, const char *password, const char *iban, const u_short id):  amount(amount), dateOfCreation(dateOfCreation), username(new char[strlen(username) + 1]), password(new char[strlen(password) + 1]), iban(new char[strlen(iban) + 1]), id(id){

    strcpy(this -> username, username);
    strcpy(this -> password, password);
    strcpy(this -> iban, iban);

}
Account::Account(const Account &other){ this -> copy(other); }
Account::~Account(){ this -> del(); }

Account &Account::operator =(const Account &other){

    if(this != &other){

        this -> del();
        this -> copy(other);

    }

    return *this;

}

void Account::deposit(const double amount){ this -> amount += amount; }

double Account::getBalance() const{ return this -> amount; }
Date Account::getDateOfCreation() const{ return this -> dateOfCreation; }
u_short Account::getUserId() const{ return this -> id; }
char *Account::getUsername() const{ return this -> username; }
char *Account::getPassword() const{ return this -> password; }
char *Account::getIBAN() const{ return this -> iban; }

void Account::del(){

    delete[] this -> username;
    delete[] this -> password;
    delete[] this -> iban;

}

void Account::copy(const Account &other){

    this -> amount = other.amount;
    this -> dateOfCreation = other.dateOfCreation;
    this -> username = new char[strlen(other.username) + 1];
    strcpy(this -> username, other.username);
    this -> password = new char[strlen(other.password) + 1];
    strcpy(this -> password, other.password);
    this -> iban = new char[strlen(other.iban) + 1];
    strcpy(this -> iban, other.iban);
    this -> id = other.id;

}