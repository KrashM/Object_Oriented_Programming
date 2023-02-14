#pragma once

#include "utils/Date.hpp"

class Account{

    public:
        Account();
        Account(const double, const Date &, const char *, const char *, const char *, const u_short);
        Account(const Account &);
        virtual ~Account();

        Account &operator =(const Account &);

        double getBalance() const;
        Date getDateOfCreation() const;
        u_short getUserId() const;
        char *getUsername() const;
        char *getPassword() const;
        char *getIBAN() const;
        void deposit(const double);

        virtual bool withdraw(const double) = 0;
        virtual void display() const = 0;
        virtual Account *clone() const = 0;

    protected:
        double amount;

    private:
        Date dateOfCreation;
        char *username, *password, *iban;
        u_short id;

        void del();
        void copy(const Account &);

};