#include "Bank.hpp"

Bank::Bank(): name(nullptr), address(nullptr){}
Bank::Bank(const char *name, const char *address): name(new char[strlen(name) + 1]), address(new char[strlen(address) + 1]){

    strcpy(this -> name, name);
    strcpy(this -> address, address);

}
Bank::Bank(const Bank &other){ this -> copy(other); }
Bank::~Bank(){ this -> free(); }
Bank &Bank::operator =(const Bank &other){

    if(this != &other){

        this -> free();
        this -> copy(other);

    }

    return *this;

}

void Bank::free(){

    delete[] this -> name;
    delete[] this -> address;
    for(size_t i = 0; i < this -> customers.size(); i++)
        delete this -> customers[i];
    for(size_t i = 0; i < this -> accounts.size(); i++)
        delete this -> accounts[i];

}
void Bank::copy(const Bank &other){

    this -> name = new char[strlen(other.name) + 1];
    strcpy(this -> name, other.name);
    this -> address = new char[strlen(other.address) + 1];
    strcpy(this -> address, other.address);

    this -> logs = other.logs;
    this -> customers = other.customers;
    this -> accounts = other.accounts;

}

// TODO: Check if customer id exists
void Bank::addCustomer(const Customer &customer){ this -> customers.pushBack(customer.clone()); }
void Bank::addAccount(const Account &account){ this -> accounts.pushBack(account.clone()); }

bool Bank::deleteCustomer(const u_short customerId){

    for(size_t i = 0; i < this -> customers.size(); i++)
        if(this -> customers[i] -> getId() == customerId){

            delete this -> customers[i];
            this -> customers.removeAt(i);
            return true;

        }

    return false;

}
bool Bank::deleteAccount(const u_short customerId, const char *iban){

    for(size_t i = 0; i < this -> accounts.size(); i++)
        if(this -> accounts[i] -> getUserId() == customerId && !strcmp(this -> accounts[i] -> getIBAN(), iban)){

            delete this -> accounts[i];
            this -> accounts.removeAt(i);
            return true;

        }

        return false;

}

void Bank::listCustomers() const{ for(size_t i = 0; i < this -> customers.size(); i++) this -> customers[i] -> display(); }
void Bank::listAccounts() const{ for(size_t i = 0; i < this -> accounts.size(); i++) this -> accounts[i] -> display(); }
void Bank::listCustomerAccounts(const u_short userId) const{

    for(size_t i = 0; i < this -> accounts.size(); i++)
        if(this -> accounts[i] -> getUserId() == userId)
            this -> accounts[i] -> display();

}

const char *convertIndex(const size_t index){

    char *result = new char[4];

    result[0] = '0' + index / 100;
    result[1] = '0' + (index / 10) % 10;
    result[2] = '0' + index % 10;
    result[3] = '\0';

    return result;

}

bool fileExists(const char *path){

    bool flag;
    ifstream file(path);

    if(file.good()) flag = true;
    else flag = false;

    file.close();

    return flag;

}

void Bank::exportLog() const{

    char *path = new char[100];
    strcpy(path, "Logs/");

    const Date currDate = Date(time(0));
    strcat(path, currDate.logFormatToString());

    struct stat info;
    if(stat(path, &info) || !(info.st_mode & S_IFDIR)) mkdir(path);

    strcat(path, "/logfile_");
    strcat(path, currDate.logFormatToString());
    strcat(path, "_000.txt");

    size_t pathLenght = strlen(path);
    for(size_t i = 0; i < 1000; i++){

        if(!fileExists(path)) break;
        path[pathLenght - 5] = '0' + i % 10;
        path[pathLenght - 6] = '0' + (i / 10) % 10;
        path[pathLenght - 7] = '0' + i / 100;

    }
    ofstream logFile(path);
    if(!logFile.is_open()) return;

    for(size_t i = 0; i < this -> logs.size(); i++)
        logFile << this -> logs[i] << '\n';

    if(logFile.good()) logFile.close();
    else throw MessageException("File unable to close\n");

}

void Bank::createLog(const String &log){ this -> logs.pushBack(log); }

void Bank::withdrawFromAcc(const double amount, const char *iban){

    bool success;

    for(size_t i = 0; i < this -> accounts.size(); i++)
        if(!strcmp(this -> accounts[i] -> getIBAN(), iban))
            if(this -> accounts[i] -> withdraw(amount)) break;
            else return;

    
    char buffer[100];
    char format[] = "Withdrawn %s from %s";
    sprintf(buffer, format, StringConverter::doubleToString(amount), iban);

    String str(buffer);

    this -> createLog(str);

}

void Bank::depositToAcc(const double amount, const char *iban){

    for(size_t i = 0; i < this -> accounts.size(); i++)
        if(!strcmp(this -> accounts[i] -> getIBAN(), iban)){

            this -> accounts[i] -> deposit(amount);
            break;

        }

    
    char buffer[100];
    char format[] = "Deposited %s to %s";
    sprintf(buffer, format, StringConverter::doubleToString(amount), iban);

    String str(buffer);

    this -> createLog(str);

}

void Bank::transfer(const double amount, const char *fromIBAN, const char *toIBAN){

    Account *toAcc = nullptr;

    for(size_t i = 0; i < this -> accounts.size(); i++){

        if(!strcmp(this -> accounts[i] -> getIBAN(), toIBAN)) toAcc = this -> accounts[i];
        if(!strcmp(this -> accounts[i] -> getIBAN(), fromIBAN)){

            if(this -> accounts[i] -> withdraw(amount)){

                if(toAcc == nullptr)
                    for(size_t j = i + 1; j < this -> accounts.size(); j++)
                        if(!strcmp(this -> accounts[j] -> getIBAN(), toIBAN))
                            toAcc = this -> accounts[j];

                toAcc -> deposit(amount);

            }
            else return;


            char buffer[100];
            char format[] = "Transfer made from %s to %s for amount: %s";
            sprintf(buffer, format, fromIBAN, toIBAN, StringConverter::doubleToString(amount));

            String str(buffer);

            this -> createLog(str);

            return;

        }

    }

}

void Bank::display() const{

    cout << "Bank name is: " << this -> name
        << "\nAddress is: " << this -> address << "\n\n";

    for(size_t i = 0; i < this -> customers.size(); i++)
        this -> customers[i] -> display();

    for(size_t i = 0; i < this -> accounts.size(); i++)
        this -> accounts[i] -> display();

}