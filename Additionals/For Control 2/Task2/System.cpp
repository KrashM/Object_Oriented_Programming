#include "System.hpp"
#include <cstring>

System::System(): _capacity(4), _size(0), _users(new User *[_capacity]){}

System::System(System const &other){
    copy(other);
}

System::System(System &&other){

    _users = std::move(other._users);
    _capacity = other._capacity;
    _size = other._size;

}

System::~System(){
    free();
}

System &System::operator =(System const &other){

    if(this == &other) return *this;

    free();
    copy(other);

    return *this;

}

System &System::operator =(System &&other){

    if(this == &other) return *this;

    free();

    _users = std::move(other._users);
    _capacity = other._capacity;
    _size = other._size;

    return *this;

}

void System::register_user(char const * const name, char const * const email, char const * const password){

    if(_size == _capacity) resize(2 * _capacity);
    _users[_size++] = new User(name, email, password);

}

User *System::log_in_user(char const * const name, char const * const password){

    if(!name || !password) return nullptr;

    for(std::size_t i = 0; i < _size; ++i)
        if(!strcmp(_users[i] -> get_name(), name) && !strcmp(_users[i] -> get_password(), password))
            return _users[i];
    
    return nullptr;

}

void System::resize(std::size_t const new_capacity){

    User **temp = new User *[new_capacity];
    for(std::size_t i = 0; i < _size; ++i)
        temp[i] = _users[i];

    delete[] _users;

    _users = temp;
    _capacity = new_capacity;

}

void System::copy(System const &other){
    
    _users = new User *[other._capacity];
    for(std::size_t i = 0; i < other._capacity; ++i)
        _users[i] = new User(*other._users[i]);

    _capacity = other._capacity;
    _size = other._size;

}

void System::free(){

    for(std::size_t i = 0; i < _capacity; ++i)
        delete _users[i];

    delete[] _users;
    _users = nullptr;

}