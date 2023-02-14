#include "User.hpp"

void User::erase(){

    delete[] this -> username;
    delete[] this -> password;
    delete[] this -> email;
    delete[] this -> personalDBPath;

}

void User::copy(const User &other){

    this -> username = new char[strlen(other.username) + 1];
    strcpy(this -> username, other.username);
    this -> password = new char[strlen(other.password) + 1];
    strcpy(this -> password, other.password);
    this -> email = new char[strlen(other.email) + 1];
    strcpy(this -> email, other.email);
    this -> personalDBPath = new char[strlen(other.personalDBPath + 1)];
    strcpy(this -> personalDBPath, other.personalDBPath);
    this -> travels = other.travels;

}

void User::setPersonalDBPath(){

    this -> personalDBPath = new char[strlen(this -> username) + 13];
    strcpy(this -> personalDBPath, "Database/");
    strcat(this -> personalDBPath, this -> username);
    strcat(this -> personalDBPath, ".db");

}

void User::createUserDB() const{ ofstream { this -> personalDBPath }; }

User::User(): username(nullptr), password(nullptr), email(nullptr), personalDBPath(nullptr){}
User::User(const char *username, const char *password, const char *email){

    try{

        User::validateUsername(username);
        User::validatePassword(password);
        User::validateEmail(email);
    
    }
    catch(const InvalidFormatException &e){ throw e; }

    this -> username = new char[strlen(username) + 1];
    strcpy(this -> username, username);
    this -> password = new char[strlen(password) + 1];
    strcpy(this -> password, password);
    this -> email = new char[strlen(email) + 1];
    strcpy(this -> email, email);


    this -> setPersonalDBPath();
    this -> createUserDB();

}
User::User(const User &other){ this -> copy(other); }
User::~User(){ this -> erase(); }

User &User::operator =(const User &other){

    if(this != &other){

        this -> erase();
        this -> copy(other);

    }

    return *this;

}

ostream &operator <<(ostream &os, const User &obj){

    os << obj.getUsername() << ' ' << obj.getEmail();
    return os;

}

void User::write(ofstream &ofs) const{

    size_t usernameLenght = strlen(this -> username);
    ofs.write((const char *)&usernameLenght, sizeof(size_t));
    ofs.write(this -> username, usernameLenght);

    size_t passwordLenght = strlen(this -> password);
    ofs.write((const char *)&passwordLenght, sizeof(size_t));
    ofs.write(this -> password, passwordLenght);

    size_t emailLenght = strlen(this -> email);
    ofs.write((const char *)&emailLenght, sizeof(size_t));
    ofs.write(this -> email, emailLenght);

    ofstream personalDB(this -> personalDBPath, ios::binary | ios::trunc);
    this -> travels.write(personalDB);
    personalDB.close();

}

void User::read(ifstream &ifs){

    size_t usernameLenght;
    ifs.read((char *)&usernameLenght, sizeof(size_t));
    this -> username = new char[usernameLenght + 1];
    ifs.read(this -> username, usernameLenght);
    this -> username[usernameLenght] = '\0';
    
    size_t passwordLenght;
    ifs.read((char *)&passwordLenght, sizeof(size_t));
    this -> password = new char[passwordLenght + 1];
    ifs.read(this -> password, passwordLenght);
    this -> password[passwordLenght] = '\0';
    
    size_t emailLenght;
    ifs.read((char *)&emailLenght, sizeof(size_t));
    this -> email = new char[emailLenght + 1];
    ifs.read(this -> email, emailLenght);
    this -> email[emailLenght] = '\0';

    this -> setPersonalDBPath();
    
    ifstream personalDB(this -> personalDBPath, ios::binary);
    this -> travels.read(personalDB);
    personalDB.close();

}

void User::setUsername(const char *username){ this -> username = new char[strlen(username) + 1]; strcpy(this -> username, username); }
void User::setPassword(const char *password){ this -> password = new char[strlen(password) + 1]; strcpy(this -> password, password); }
void User::setEmail(const char *email){ this -> email = new char[strlen(email) + 1]; strcpy(this -> email, email); }
void User::addTravel(const Travel &travel){ this -> travels.pushBack(travel); }

char *User::getUsername() const{ return this -> username; }
char *User::getPassword() const{ return this -> password; }
char *User::getEmail() const{ return this -> email; }
Vector<Travel> &User::getTravels(){ return this -> travels; }

void User::validateUsername(const char *username){

    try{ StringChecker::isUsername(username); }
    catch(const InvalidFormatException &e){ throw e; }

    char tempPath[strlen(username) + 13];
    strcpy(tempPath, "Database/");
    strcat(tempPath, username);
    strcat(tempPath, ".db");
    
    ifstream temp(tempPath);
    bool exists = temp.good();
    temp.close();
    if(exists) throw InvalidFormatException("Username exists");

}

void User::validatePassword(const char *password){ try{ StringChecker::isPassword(password); } catch(const InvalidFormatException &e){ throw e; } }
void User::validateEmail(const char *email){ try{ StringChecker::isEmail(email); } catch(const InvalidFormatException &e){ throw e; } }

const char *User::toString() const{

    char *result = new char[strlen(this -> username) + strlen(this -> password) + strlen(this -> email) + 3];
    strcpy(result, this -> username);
    strcat(result, " ");
    strcat(result, this -> password);
    strcat(result, " ");
    strcat(result, this -> email);
    strcat(result, "\0");

    return result;

}