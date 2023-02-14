#include "NormalAccount.hpp"

NormalAccount::NormalAccount(): Account(){}
NormalAccount::NormalAccount(const double amount, const Date &dateOfCreation, const char *username, const char *password, const char *iban, const u_short id): Account(amount, dateOfCreation, username, password, iban, id){}
NormalAccount::NormalAccount(const NormalAccount &other): Account(other){}
NormalAccount &NormalAccount::operator =(const NormalAccount &other){

    if(this != &other) Account::operator=(other);
    return *this;

}

bool NormalAccount::withdraw(const double amount){

    if(this -> getBalance() < amount) return false;
    this -> amount -= amount;
    return true;

}

void NormalAccount::display() const{
    
    cout << "Account owner id: " << this -> getUserId()
        << "\nOwned by: " << this -> getUsername()
        << "\nIBAN: " << this -> getIBAN()
        << "\nCreated on: " << this -> getDateOfCreation().toString()
        << "\nAmount in account: " << StringConverter::doubleToString(this -> getBalance())
        << "\n\n";
    
}

NormalAccount *NormalAccount::clone() const{

    NormalAccount *clone = new NormalAccount(*this);
    return clone;

}