#include "IO.hpp"

Bank IO::theBank("Plamena's bank", "j.k. Studentski grad");

void IO::mainMenu(){

    struct stat info;
    if(stat("Logs", &info) || !(info.st_mode & S_IFDIR)) mkdir("Logs");
    
    bool running = true;

    while(running){

        system("cls");

        cout << "Welcome to the platform\n"
            << "Choose one of the following:\n"
            << "1. Edit\n"
            << "2. List\n"
            << "3. Action\n"
            << "4. Display info for the bank\n"
            << "5. Quit\n";

        char choice;
        cin >> choice;
        choice -= '0';

        switch(choice){

            case 1:
                IO::editMenu();
                break;

            case 2:
                IO::listMenu();
                break;

            case 3:
                IO::actionMenu();
                break;

            case 4:
                IO::displayBank();
                break;

            case 5:
                running = false;
                break;

            default:
                break;

        }

    }

}

void IO::editMenu(){
    
    bool choiceIsNotCorrect = true;
    
    while(choiceIsNotCorrect){

        system("cls");
        
        cout << "Select which one you want to edit:\n"
            << "1. Customer\n"
            << "2. Account\n";

        char choice;
        cin >> choice;
        choice -= '0';

        switch(choice){

            case 1:
                IO::editCustomerMenu();
                choiceIsNotCorrect = false;
                break;

            case 2:
                IO::editAccountMenu();
                choiceIsNotCorrect = false;
                break;

            default:
                break;
                

        }

    }

}

void IO::editCustomerMenu(){

    bool choiceIsNotCorrect = true;
    
    while(choiceIsNotCorrect){

        system("cls");
        
        cout << "Select one of the following:\n"
            << "1. Add new customer\n"
            << "2. Delete customer\n";

        char choice;
        cin >> choice;
        choice -= '0';

        switch(choice){

            case 1:
                IO::addCustomer();
                choiceIsNotCorrect = false;
                break;

            case 2:
                IO::deleteCustomer();
                choiceIsNotCorrect = false;
                break;

            default:
                break;
                

        }

    }

}

void IO::editAccountMenu(){

    bool choiceIsNotCorrect = true;
    
    while(choiceIsNotCorrect){

        system("cls");
        
        cout << "Select one of the following:\n"
            << "1. Add new account\n"
            << "2. Delete account\n";

        char choice;
        cin >> choice;
        choice -= '0';

        switch(choice){

            case 1:
                IO::addAccount();
                choiceIsNotCorrect = false;
                break;

            case 2:
                IO::deleteAccount();
                choiceIsNotCorrect = false;
                break;

            default:
                break;
                

        }

    }

}

void IO::addCustomer(){

    u_short id;
    cout << "Enter user id\n: ";
    cin >> id;

    char username[1024];
    cout << "Enter username\n: ";
    cin >> username;

    char address[1024];
    cout << "Enter user address\n: ";
    cin >> address;

    IO::theBank.addCustomer(Customer(id, username, address));

}

void IO::deleteCustomer(){

    u_short id;
    cout << "Enter customer id\n: ";
    cin >> id;

    IO::theBank.deleteCustomer(id);

}

size_t IO::selectType(){

    while(true){

        system("cls");

        size_t type;
        cout << "Choose what type of account you want:\n"
            << "1. Normal account\n"
            << "2. Savings account\n"
            << "3. Privilege account\n";
        cin >> type;

        if(type > 0 && type < 4) return type;

    }

}

void IO::addAccount(){

    const size_t type = IO::selectType();

    system("cls");

    double amount;
    cout << "Enter amount of money in the account\n: ";
    cin >> amount;

    char username[1024];
    cout << "Enter username\n: ";
    cin >> username;

    char password[1024];
    cout << "Enter password\n: ";
    cin >> password;

    char iban[1024];
    cout << "Enter iban\n: ";
    cin >> iban;

    u_short userId;
    cout << "Enter user id\n: ";
    cin >> userId;

    switch(type){

        case 1:
            IO::theBank.addAccount(NormalAccount(amount, Date(time(0)), username, password, iban, userId));
            break;
            
        case 2:
            double interestRate;
            cout << "Enter interest rate\n: ";
            cin >> interestRate;
            IO::theBank.addAccount(SavingsAccount(amount, Date(time(0)), username, password, iban, userId, interestRate));
            break;

        case 3:
            double overdraft;
            cout << "Enter overdraft amount\n: ";
            cin >> overdraft;
            IO::theBank.addAccount(PrivilegeAccount(amount, Date(time(0)), username, password, iban, userId, overdraft));
            break;
        
        default:
            break;
    
    }

}

void IO::deleteAccount(){

    system("cls");

    u_short userId;
    cout << "Enter user id\n: ";
    cin >> userId;

    char iban[1024];
    cout << "Enter iban\n: ";
    cin >> iban;

    IO::theBank.deleteAccount(userId, iban);

}

void IO::listMenu(){

    bool running = true;

    while(running){

        system("cls");

        cout << "Choose one of the following:\n"
            << "1. List all customers\n"
            << "2. List all accounts\n"
            << "3. List customer account\n"
            << "4. Export logs\n: ";

        char choice;
        cin >> choice;
        cin.ignore();
        choice -= '0';

        switch (choice){

            case 1:
                IO::theBank.listCustomers();
                running = false;
                break;

            case 2:
                IO::theBank.listAccounts();
                running = false;
                break;

            case 3:
                u_short id;
                cout << "Enter customer id\n: ";
                cin >> id;
                cin.ignore();
                IO::theBank.listCustomerAccounts(id);
                running = false;
                break;

            case 4:
                IO::theBank.exportLog();
                running = false;
                break;
            
            default:
                break;

        }

    }

    cin.get();

}

void IO::actionMenu(){

    bool choiceIsNotCorrect = true;
    
    while(choiceIsNotCorrect){

        system("cls");
        
        cout << "Select one of the following:\n"
            << "1. Withdraw from account\n"
            << "2. Deposit to account\n"
            << "3. Transfer\n";

        char choice;
        cin >> choice;
        choice -= '0';

        switch(choice){

            case 1:
                IO::withdrawFromAccount();
                choiceIsNotCorrect = false;
                break;

            case 2:
                IO::depositToAccount();
                choiceIsNotCorrect = false;
                break;

            case 3:
                IO::transferBetweenAccounts();
                choiceIsNotCorrect = false;
                break;

            default:
                break;
                

        }

    }

}
void IO::withdrawFromAccount(){

    double amount;
    cout << "Enter amount you want to withdraw\n: ";
    cin >> amount;

    char iban[1024];
    cout << "Enter the account iban\n: ";
    cin >> iban;

    IO::theBank.withdrawFromAcc(amount, iban);

}

void IO::depositToAccount(){

    double amount;
    cout << "Enter amount you want to deposit\n: ";
    cin >> amount;

    char iban[1024];
    cout << "Enter the account iban\n: ";
    cin >> iban;

    IO::theBank.depositToAcc(amount, iban);

}

void IO::transferBetweenAccounts(){

    double amount;
    cout << "Enter amount you want to transfer\n: ";
    cin >> amount;

    char fromIBAN[1024];
    cout << "Enter the account iban from which to take the money\n: ";
    cin >> fromIBAN;

    char toIBAN[1024];
    cout << "Enter the account iban that will recieve the money\n: ";
    cin >> toIBAN;

    try{ IO::theBank.transfer(amount, fromIBAN, toIBAN); }
    catch(const MessageException &e){ cerr << e.what() << '\n'; }

}

void IO::displayBank(){ cin.ignore(); IO::theBank.display(); cin.get(); }

/*

1
1
1
1
Plamena
Haskovo
1
2
1
1
1000
Plamena
01072002
helloworld
1
1
2
1
3
500
Plamena
01072002
fakenews
1
250
3
3
20.5
helloworld
fakenews

*/