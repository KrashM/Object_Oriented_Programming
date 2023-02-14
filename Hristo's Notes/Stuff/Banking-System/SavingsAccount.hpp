#pragma once

#include "Account.hpp"

class SavingsAccount: public Account{

    public:
        SavingsAccount();
        SavingsAccount(const double, const Date &, const char *, const char *, const char *, const u_short, const double);
        SavingsAccount(const SavingsAccount &);
        SavingsAccount &operator =(const SavingsAccount &);

        double getInterestRate() const;

        bool withdraw(const double) override;
        void display() const override;
        SavingsAccount *clone() const override;

    private:
        double interestRate;

};