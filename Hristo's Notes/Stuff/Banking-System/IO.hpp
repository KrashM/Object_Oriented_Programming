#pragma once

#include "utils/Includes.hpp"
#include "NormalAccount.hpp"
#include "SavingsAccount.hpp"
#include "PrivilegeAccount.hpp"
#include "Bank.hpp"

class IO{

    public:
        // Main menu
        static void mainMenu();

            // Sub menus

            // Edit menu
            static void editMenu();
                // Edit customer
                static void editCustomerMenu();
                    // Add customer
                    static void addCustomer();
                    // Delete customer
                    static void deleteCustomer();

                // Edit account
                static void editAccountMenu();
                    static size_t selectType();
                    // Add customer
                    static void addAccount();
                    // Delete customer
                    static void deleteAccount();

            // List menu
            static void listMenu();
                // List customers
                static void listCustomers();
                // List accounts
                static void listAccounts();
                // List customer account
                static void listCustomerAccount();
                // List log
                static void listLog();

            // Action menu
            static void actionMenu();
                // Withdraw
                static void withdrawFromAccount();
                // Deposit
                static void depositToAccount();
                // Transfer
                static void transferBetweenAccounts();

            // Display menu
            static void displayBank();


    private:
        static Bank theBank;

};