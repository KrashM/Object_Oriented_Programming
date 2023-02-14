#pragma once

#include "Context.hpp"

class IO{

    public:
        static void registerUser(User &currenUser);
        static User &loginUser(Vector<User> &users);
        static Vector<Travel> getAllTravelToDestination(Vector<User> &users);
        static void addTravel(User &user);
        static void platform(User &currentUser, Vector<User> &users);
        static void authentication();

};