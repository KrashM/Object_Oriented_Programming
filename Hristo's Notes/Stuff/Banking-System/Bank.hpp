#pragma once

#include "Account.hpp"
#include "Customer.hpp"
#include "utils/Vector.h"
#include "utils/String.h"

class Bank{

    public:
        Bank();
        Bank(const char *, const char *);
        Bank(const Bank &);
        ~Bank();
        Bank &operator =(const Bank &);

        void addCustomer(const Customer &);
        void addAccount(const Account &);

        bool deleteCustomer(const u_short);
        bool deleteAccount(const u_short, const char *);

        void listCustomers() const;
        void listAccounts() const;
        void listCustomerAccounts(const u_short) const;

        void exportLog() const;
        void createLog(const String &);

        void withdrawFromAcc(const double, const char *);
        void depositToAcc(const double, const char *);
        void transfer(const double, const char *, const char *);

        void display() const;

    private:
        Vector<Account *> accounts;
        Vector<Customer *> customers;
        Vector<String> logs;
        char *name, *address;

        void free();
        void copy(const Bank &);

};