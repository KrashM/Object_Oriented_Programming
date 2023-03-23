#include "Book.h"

#include <iostream>
#include <cstring>

Book::Book() : Book("", 0) {}

Book::Book(const char* name, unsigned yearOfPublication)
    : m_yearOfPublication(yearOfPublication) {
    strcpy(m_name, name);
}

const char* Book::getName() const {
    return m_name;
}

void Book::print() const {
    std::cout << m_name << " was published in " << m_yearOfPublication << std::endl;
}
