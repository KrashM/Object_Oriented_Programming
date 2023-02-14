#pragma once

#include "utils/Includes.hpp"

class Customer{

    public:
        Customer();
        Customer(const u_short, const char *, const char *);
        Customer(const Customer &);
        ~Customer();
        Customer &operator =(const Customer &);
        Customer *clone() const;

        const u_short getId() const;
        const char *getName() const;
        const char *getAddress() const;

        void setId(const u_short);
        void setName(const char *);
        void setAddress(const char *);

        void display() const;

    private:
        char *name, *address;
        u_short id;
        
        void del();
        void copy(const Customer &);

};