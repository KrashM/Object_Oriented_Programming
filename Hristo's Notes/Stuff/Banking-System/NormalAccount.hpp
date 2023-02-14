#pragma once

#include "Account.hpp"

class NormalAccount: public Account{

    public:
        NormalAccount();
        NormalAccount(const double, const Date &, const char *, const char *, const char *, const u_short);
        NormalAccount(const NormalAccount &);
        NormalAccount &operator =(const NormalAccount &);
        
        bool withdraw(const double) override;
        void display() const override;
        NormalAccount *clone() const override;

};