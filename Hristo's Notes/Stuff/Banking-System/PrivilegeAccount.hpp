#pragma once

#include "Account.hpp"

class PrivilegeAccount: public Account{

    public:
        PrivilegeAccount();
        PrivilegeAccount(const double, const Date &, const char *, const char *, const char *, const u_short, const double);
        PrivilegeAccount(const PrivilegeAccount &);
        PrivilegeAccount &operator =(const PrivilegeAccount &);

        double getOverdraft() const;

        bool withdraw(const double) override;
        void display() const override;
        PrivilegeAccount *clone() const override;

    private:
        double overdraft;

};