#include "Developer.hpp"
#include <stdlib.h>
#include <fstream>
#include <cstring>
#include <sstream>
#include <time.h>

using std::ios;
using std::ofstream;
using std::ifstream;
using std::stringstream;

Developer::Developer(): _firstName(nullptr), _lastName(nullptr), _manager(nullptr), _position(Position::JUNIOR_DEV), _id(0){}

Developer::Developer(char const * const firstName, char const * const lastName, Position const position){

    srand(time(nullptr));

    _firstName = new char[strlen(firstName) + 1];
    _lastName = new char[strlen(lastName) + 1];
    _position = position;
    _manager = nullptr;
    _id = rand() % 9000 + 1000;

    strcpy(_firstName, firstName);
    strcpy(_lastName, lastName);

}

Developer::Developer(Developer const &other){
    copyFrom(other);
}

Developer::~Developer(){
    free();
}

Developer &Developer::operator =(Developer const &other){

    if(this == &other) return *this;

    free();
    copyFrom(other);

    return *this;

}

ofstream &Developer::save(ofstream &output) const{

    output << _id << '\n'
        << strlen(_firstName) << ' ' << _firstName << '\n'
        << strlen(_lastName) << ' ' << _lastName << '\n'
        << (unsigned)_position << '\n';
    
    if(_manager)
        output << "Manager info:\n" << _manager << '\n';

    return output;

}

ifstream &Developer::load(ifstream &input){

    free();

    size_t firstNameLen, lastNameLen;

    input >> _id;

    input >> firstNameLen;
    _firstName = new char[firstNameLen];
    input >> _firstName;

    input >> lastNameLen;
    _lastName = new char[lastNameLen];
    input >> _lastName;

    input >> *(unsigned *)&_position;

    size_t position = input.tellg();

    char temp[15];
    input >> temp;

    if(!strcmp(temp, "Manager info:")){

        _manager = new Developer;
        _manager -> load(input);

    }
    else input.seekg(position);

    return input;

}

void Developer::addManager(Developer const &manager){
    _manager = manager._position == Position::MANAGER ? new Developer(manager) : _manager;
}

#ifdef DOCTEST_LIBRARY_INCLUDED
    uint16_t Developer::getId() const{
        return _id;
    }
#endif

ostream &operator <<(ostream &os, Developer const &dev){

    if(!dev._id) return os << "";


    os << dev._id << '\n'
        << dev._firstName << '\n'
        << dev._lastName << '\n';
    
    switch (dev._position){

        case Position::JUNIOR_DEV:
            os << "Junior developer";
            break;
        
        case Position::DEV:
            os << "Developer";
            break;
        
        case Position::SENIOR_DEV:
            os << "Senior developer";
            break;
        
        case Position::QA:
            os << "Quality assurance";
            break;
        
        case Position::MANAGER:
            os << "Manager";
            break;
        
        default:
            break;

    }

    if(dev._manager)
        os << "\nManager:\n" << *dev._manager;

    return os;

}

void Developer::copyFrom(Developer const &other){

    _id = other._id;
    _position = other._position;
    _manager = other._manager ? new Developer(*other._manager) : nullptr;
    _firstName = new char[strlen(other._firstName) + 1];
    _lastName = new char[strlen(other._lastName) + 1];

    strcpy(_firstName, other._firstName);
    strcpy(_lastName, other._lastName);

}

void Developer::free(){

    delete[] _firstName;
    delete[] _lastName;
    delete _manager;

    _firstName = nullptr;
    _lastName = nullptr;
    _manager = nullptr;
    _id = 0;

}

#ifdef DOCTEST_LIBRARY_INCLUDED

TEST_SUITE("Testing constructors"){

    TEST_CASE("Default constructor"){

        Developer dev;
        stringstream ss;

        ss << dev;

        CHECK(ss.str() == "");

    }

    TEST_CASE("Parametric constructor"){

        Developer dev("Hristo", "Kanev", Position::DEV);
        
        stringstream ss, ss1;
        ss << dev;
        ss1 << dev.getId() << "\nHristo\nKanev\nDeveloper";


        CHECK(ss.str() == ss1.str());

    }

    TEST_CASE("Copy constructor"){

        Developer dev("Hristo", "Kanev", Position::DEV);
        Developer dev1 = dev;
        
        stringstream ss, ss1;

        ss << dev;
        ss1 << dev1;
        
        CHECK(ss.str() == ss1.str());

    }

}

TEST_CASE("Testing destructor"){

    Developer dev("Hristo", "Kanev", Position::DEV);
    dev.~Developer();

    stringstream ss;
    ss << dev;

    CHECK(ss.str() == "");

}

TEST_SUITE("Testing operators"){

    TEST_CASE("Operator ="){

        Developer dev("Hristo", "Kanev", Position::DEV);

        Developer dev1;
        dev1 = dev;

        stringstream ss, ss1;

        ss << dev;
        ss1 << dev1;

        CHECK(ss.str() == ss1.str());

    }

    TEST_CASE("Operator <<"){

        Developer dev("Hristo", "Kanev", Position::DEV);
        stringstream ss, ss1;

        ss << dev;
        ss1 << dev.getId() << "\nHristo\nKanev\nDeveloper";

        CHECK(ss.str() == ss1.str());

    }

}

TEST_CASE("Testing file managment"){

    Developer dev("Hristo", "Kanev", Position::DEV), dev1;

    ofstream ofs("out.txt");
    dev.save(ofs);
    ofs.close();

    ifstream ifs("out.txt");
    dev1.load(ifs);
    ifs.close();

    stringstream ss, ss1;

    ss << dev;
    ss1 << dev1;

    CHECK(ss.str() == ss1.str());

}

TEST_CASE("Adding manager"){

    Developer dev("Hristo", "Kanev", Position::DEV);

    SUBCASE("Wihtout position of manager"){

        Developer dev2("Stoyan", "Malinin", Position::QA);
        
        dev.addManager(dev2);

        stringstream ss, ss1;
        ss << dev;
        ss1 << dev.getId() << "\nHristo\nKanev\nDeveloper";

        CHECK(ss.str() == ss1.str());

    }

    SUBCASE("With postion of manager"){
        
        Developer dev1("Stefan", "Filipov", Position::MANAGER);
        
        dev.addManager(dev1);

        stringstream ss, ss1;
        ss << dev;
        ss1 << dev.getId() << "\nHristo\nKanev\nDeveloper\nManager:\n" << dev1.getId() << "\nStefan\nFilipov\nManager";

        CHECK(ss.str() == ss1.str());

    }

}

#endif