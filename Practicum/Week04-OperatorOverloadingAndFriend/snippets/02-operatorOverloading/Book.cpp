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

bool Book::operator==(const Book& other) const {
    return strcmp(m_name, other.m_name) &&
           m_yearOfPublication == other.m_yearOfPublication;
}

bool Book::operator!=(const Book& other) const {
    return !(*this == other);
}
