#pragma once

#include "Travel.hpp"

class User{

    private:
        char *username, *password, *email, *personalDBPath;
        Vector<Travel> travels;
        
        void erase();
        void copy(const User &);
        void setPersonalDBPath();
        void createUserDB() const;

    public:
        User();
        User(const char *, const char *, const char *);
        User(const User &);
        ~User();

        User &operator =(const User &);
        friend ostream &operator <<(ostream &, const User &);

        void write(ofstream &) const;
        void read(ifstream &);

        void setUsername(const char *);
        void setPassword(const char *);
        void setEmail(const char *);
        void addTravel(const Travel &);

        char *getUsername() const;
        char *getPassword() const;
        char *getEmail() const;
        Vector<Travel> &getTravels();

        static void validateUsername(const char *);
        static void validatePassword(const char *);
        static void validateEmail(const char *);

        const char *toString() const;

};