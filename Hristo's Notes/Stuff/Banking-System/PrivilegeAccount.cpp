#include "PrivilegeAccount.hpp"

PrivilegeAccount::PrivilegeAccount(): Account(0, Date(), nullptr, nullptr, nullptr, 0), overdraft(0){}
PrivilegeAccount::PrivilegeAccount(const double amount, const Date &dateOfCreation, const char *username, const char *password, const char *iban, const u_short id, const double overdraft): Account(amount, dateOfCreation, username, password, iban, id), overdraft(overdraft){}
PrivilegeAccount::PrivilegeAccount(const PrivilegeAccount &other): Account(other), overdraft(other.overdraft){}
PrivilegeAccount &PrivilegeAccount::operator =(const PrivilegeAccount &other){

    if(this != &other){

        this -> overdraft = other.overdraft;
        Account::operator =(other);

    }
    
    return *this;

}

double PrivilegeAccount::getOverdraft() const{ return this -> overdraft; }

bool PrivilegeAccount::withdraw(const double amount){

    if(this -> amount + this -> overdraft < amount) return false;
    this -> amount -= amount;
    return true;

}

void PrivilegeAccount::display() const{

    cout << "Account owner id: " << this -> getUserId()
        << "\nOwned by: " << this -> getUsername()
        << "\nIBAN: " << this -> getIBAN()
        << "\nCreated on: " << this -> getDateOfCreation().toString()
        << "\nAmount in account: " << StringConverter::doubleToString(this -> getBalance())
        << "\nOverdraft is: " << this -> getOverdraft()
        << "\n\n";

}

PrivilegeAccount *PrivilegeAccount::clone() const{

    PrivilegeAccount *clone = new PrivilegeAccount(*this);
    return clone;

}