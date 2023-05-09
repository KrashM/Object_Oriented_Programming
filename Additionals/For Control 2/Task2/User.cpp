#include "User.hpp"
#include <cstring>

User::User(char const * const name, char const * const email, char const * const password):
    _capacity(4), _size(0), _products(new Product *[_capacity]){
    
    if(name){

        _name = new char[strlen(name) + 1];
        strcpy(_name, name);

    }
    
    if(email){

        _email = new char[strlen(email) + 1];
        strcpy(_email, email);

    }
    
    if(password){

        _password = new char[strlen(password) + 1];
        strcpy(_password, password);

    }

}

User::User(User const &other){
    copy(other);
}

User::User(User &&other){

    _products = std::move(other._products);
    _name = std::move(other._name);
    _email = std::move(other._email);
    _password = std::move(other._password);
    _capacity = other._capacity;
    _size = other._size;

}

User::~User(){
    free();
}

User &User::operator =(User const &other){

    if(this == &other) return *this;

    free();
    copy(other);

    return *this;

}

User &User::operator =(User &&other){

    if(this == &other) return *this;

    free();
    _products = std::move(other._products);
    _name = std::move(other._name);
    _email = std::move(other._email);
    _password = std::move(other._password);
    _capacity = other._capacity;
    _size = other._size;

    return *this;

}

void User::add_product(Product const &p){

    if(_size == _capacity) resize(2 * _capacity);
    _products[_size++] = new Product(p);

}

char const * const User::get_name() const{
    return _name;
}

char const * const User::get_password() const{
    return _password;
}

void User::print() const{

    std::cout << "Person: " << _name << '\n'
        << _email << '\n'
        << "Products:\n";

    for(std::size_t i = 0; i < _size; ++i)
        _products[i] -> print(); 

}

void User::resize(std::size_t const new_capacity){

    Product **temp = new Product *[new_capacity];
    for(std::size_t i = 0; i < _size; ++i)
        temp[i] = _products[i];

    delete[] _products;

    _products = temp;
    _capacity = new_capacity;

}

void User::copy(User const &other){
    
    _products = new Product *[other._capacity];
    for(std::size_t i = 0; i < other._capacity; ++i)
        _products[i] = new Product(*other._products[i]);

    _name = new char[strlen(other._name) + 1];
    strcpy(_name, other._name);

    _email = new char[strlen(other._email) + 1];
    strcpy(_email, other._email);

    _password = new char[strlen(other._password) + 1];
    strcpy(_password, other._password);

    _capacity = other._capacity;
    _size = other._size;

}

void User::free(){

    for(std::size_t i = 0; i < _capacity; ++i)
        delete _products[i];

    delete[] _products;
    _products = nullptr;

}