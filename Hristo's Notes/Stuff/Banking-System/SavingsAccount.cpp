#include "SavingsAccount.hpp"

SavingsAccount::SavingsAccount(): Account(), interestRate(0){}
SavingsAccount::SavingsAccount(const double amount, const Date &dateOfCreation, const char *username, const char *password, const char *iban, const u_short id, const double interestRate): Account(amount, dateOfCreation, username, password, iban, id), interestRate(interestRate){}
SavingsAccount::SavingsAccount(const SavingsAccount &other): Account(other), interestRate(other.interestRate){}
SavingsAccount &SavingsAccount::operator =(const SavingsAccount &other){

    if(this != &other){

        this -> interestRate = other.interestRate;
        Account::operator=(other);

    }
    
    return *this;

}

double SavingsAccount::getInterestRate() const{ return this -> interestRate; }

bool SavingsAccount::withdraw(const double){ return false; }
void SavingsAccount::display() const{

    cout << "Account owner id: " << this -> getUserId()
        << "\nOwned by: " << this -> getUsername()
        << "\nIBAN: " << this -> getIBAN()
        << "\nCreated on: " << this -> getDateOfCreation().toString()
        << "\nAmount in account: " << StringConverter::doubleToString(this -> getBalance())
        << "\nInterest rate is: " << this -> getInterestRate()
        << "\n\n";

}

SavingsAccount *SavingsAccount::clone() const{

    SavingsAccount *clone = new SavingsAccount(*this);
    return clone;

}