#include "Developer.h"
#include <fstream>
#include <cstring>

using std::ofstream;
using std::ifstream;

Developer::Developer(){

    this -> mld = nullptr;
    this -> mFirstName = nullptr;
    this -> mLastName = nullptr;
    this -> position = Position::NONE;

}

Developer::Developer(const char *mld, const char *mFirstName, const char *mLastName, const Position position){

    this -> mld = new char[1];
    this -> mFirstName = new char[1];
    this -> mLastName = new char[1];
    this -> position = position;

    strcpy(this -> mld, mld);
    strcpy(this -> mFirstName, mFirstName);
    strcpy(this -> mLastName, mLastName);

}

Developer::~Developer(){

    delete[] this -> mld;
    delete[] this -> mFirstName;
    delete[] this -> mLastName;

}

void Developer::saveToFile(){

    ofstream output("out.txt");

    output << this -> mld << '\n' << this -> mFirstName << '\n' << this -> mLastName << '\n';

    if(this -> position == Developer::DEV) output << "Developer\n";
    else if(this -> position == Developer::JUNIOR_DEV) output << "JuniorDeveloper\n";
    else if(this -> position == Developer::SENIOR_DEV) output << "SeniorDeveloper\n";
    else if(this -> position == Developer::QA) output << "QA\n";
    else if(this -> position == Developer::MANAGER) output << "Manager\n";

    output.close();  

}

void Developer::readFromFile(){

    ifstream input("in.txt");

    this -> mld = new char[1];
    input >> this -> mld;
    this -> mFirstName = new char[1];
    input >> this -> mFirstName;
    this -> mLastName = new char[1];
    input >> this -> mLastName;

    char pos[16];
    input >> pos;

    this -> position = Developer::translateToPos(pos);

    // if(!strcmp(pos, "Developer")) this -> position = Developer::Position::DEV;
    // else if(!strcmp(pos, "JuniorDeveloper")) this -> position = Developer::Position::JUNIOR_DEV;
    // else if(!strcmp(pos, "SeniorDeveloper")) this -> position = Developer::Position::SENIOR_DEV;
    // else if(!strcmp(pos, "QA")) this -> position = Developer::Position::QA;
    // else if(!strcmp(pos, "Manager")) this -> position = Developer::Position::MANAGER;

    input.close();

}

char *Developer::toString(){

    int mldLen = strlen(this -> mld), mFirstNameLen = strlen(this -> mFirstName), mLastNameLen = strlen(this -> mLastName);
    char *result = new char[mldLen + mFirstNameLen + mLastNameLen + 17];

    strcpy(result, this -> mld);
    result[mldLen] = ' ';
    result[mldLen + 1] = '\0';
    
    strcat(result, this -> mFirstName);
    result[mldLen + mFirstNameLen + 1] = ' ';
    result[mldLen + mFirstNameLen + 2] = '\0';

    strcat(result, this -> mLastName);
    result[mldLen + mFirstNameLen + mLastNameLen + 2] = ' ';
    result[mldLen + mFirstNameLen + mLastNameLen + 3] = '\0';

    strcat(result, Developer::translateToChar(this -> position));

    result[strlen(result)] = '\0';

    return result;

}

Developer::Position Developer::translateToPos(const char *pos){

    if(!strcmp(pos, "Developer")) return Developer::Position::DEV;
    if(!strcmp(pos, "JuniorDeveloper")) return Developer::Position::JUNIOR_DEV;
    if(!strcmp(pos, "SeniorDeveloper")) return Developer::Position::SENIOR_DEV;
    if(!strcmp(pos, "QA")) return Developer::Position::QA;
    if(!strcmp(pos, "Manager")) return Developer::Position::MANAGER;
    return Developer::Position::NONE;

    // Cannot compare directly to string
    // if(pos == "Developer") position = Developer::Position::DEV;
    // else if(pos == "JuniorDeveloper") position = Developer::Position::JUNIOR_DEV;
    // else if(pos == "SeniorDeveloper") position = Developer::Position::SENIOR_DEV;
    // else if(pos == "QA") position = Developer::Position::QA;
    // else if(pos == "Manager") position = Developer::Position::MANAGER;

}

const char *Developer::translateToChar(const Position pos){

    if(pos == Developer::Position::DEV) return "Developer";
    if(pos == Developer::Position::JUNIOR_DEV) return "JuniorDeveloper";
    if(pos == Developer::Position::SENIOR_DEV) return "SeniorDeveloper";
    if(pos == Developer::Position::QA) return "QA";
    if(pos == Developer::Position::MANAGER) return "Manager";
    return "None";

}