#pragma once

#include "User.hpp"

class Context{

    public:
        static void getUsersFromDB(Vector<User> &);
        static void save(const Vector<User> &);

};