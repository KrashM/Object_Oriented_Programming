#include "Customer.hpp"

Customer::Customer(): id(0), name(nullptr), address(nullptr){}
Customer::Customer(const u_short id, const char *name, const char *address): id(id), name(new char[strlen(name) + 1]), address(new char[strlen(address) + 1]){

    strcpy(this -> name, name);
    strcpy(this -> address, address);

}
Customer::Customer(const Customer &other){ this -> copy(other); }
Customer::~Customer(){ this -> del(); }
Customer &Customer::operator =(const Customer &other){

    if(this != &other){

        this -> del();
        this -> copy(other);

    }

    return *this;

}
Customer *Customer::clone() const{

    Customer *clone = new Customer(*this);
    return clone;
    
}

const u_short Customer::getId() const{ return this -> id; }
const char *Customer::getName() const{ return this -> name; }
const char *Customer::getAddress() const{ return this -> address; }

void Customer::setId(const u_short id){ this -> id = id; }
void Customer::setName(const char *name){
    
    delete[] this -> name;
    this -> name = new char[strlen(name) + 1];
    strcpy(this -> name, name);
    
}
void Customer::setAddress(const char *address){

    delete[] this -> address;
    this -> address = new char[strlen(address) + 1];
    strcpy(this -> address, address);

}

void Customer::del(){

    delete[] this -> name;
    delete[] this -> address;

}

void Customer::copy(const Customer &other){

    this -> id = other.id;
    this -> name = new char[strlen(other.name) + 1];
    strcpy(this -> name, other.name);
    this -> address = new char[strlen(other.address) + 1];
    strcpy(this -> address, other.address);

}

void Customer::display() const{

    cout << "Customer id: " << this -> id
        << "\nCustomer name: " << this -> name
        << "\nCustomer address: " << this -> address << "\n\n";

}