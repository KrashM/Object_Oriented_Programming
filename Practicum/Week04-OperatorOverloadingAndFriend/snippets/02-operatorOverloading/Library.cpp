#include "Library.h"

#include <iostream>
#include <cstring>
#include <cassert>

Library::Library() {
    allocateData(BOOKS_INITIAL_CAPACITY);
}

Library::Library(const Library& other) {
    copyDataFrom(other);
}

Library::~Library() {
    deleteData();
}

void Library::addBook(const Book& book) {
    if (nBooksSize >= nBooksCapacity) {
        allocateData(nBooksCapacity * BOOKS_CAPACITY_MULTIPLIER);
    }

    m_books[nBooksSize++] = book;
}

bool Library::removeBook(const char* name) {
    for (std::size_t index{ 0 }; index < nBooksSize; ++index) {
        if (strcmp(name, m_books[index].getName()) == 0) {
            m_books[index] = m_books[nBooksSize - 1];
            
            --nBooksSize;

            return true;
        }
    }

    return false;
}

void Library::printInfo() const {
    std::cout << "Size: " << nBooksSize << std::endl;
    std::cout << "Capacity: " << nBooksCapacity << std::endl;
    
    for (std::size_t index{ 0 }; index < nBooksSize; ++index) {
        m_books[index].print();
    }
}

Library Library::operator+(const Book& book) {
    Library library(*this);

    library.addBook(book);

    return library;
}

Library& Library::operator+=(const Book& book) {
    addBook(book);

    return (*this);
}

Library Library::operator-(const char* name) {
    Library library(*this);

    library.removeBook(name);

    return library;
}

Library& Library::operator-=(const char* name) {
    removeBook(name);

    return *this;
}

const Book& Library::operator[](std::size_t index) const {
    assert(index < 0 || index >= nBooksSize);
    
    return m_books[index];
}

Book& Library::operator[](std::size_t index) {
    assert(index < 0 || index >= nBooksSize);

    return m_books[index];
}

bool Library::operator==(const Library& other) const {
    if (nBooksSize != other.nBooksSize ||
        nBooksCapacity != other.nBooksCapacity) {
        return false;
    }

    for (std::size_t index{ 0 }; index < nBooksSize; ++index) {
        if (m_books[index] != other[index]) {
            return false;
        }
    }

    return true;
}

bool Library::operator!=(const Library& other) const {
    return !(*this != other);
}

Library& Library::operator=(const Library& other) {
    if (this != &other) {
        deleteData();
        copyDataFrom(other);
    }

    return *this;
}

void Library::deleteData() {
    delete[] m_books;
    m_books = nullptr;
}

void Library::copyDataFrom(const Library& other) {
    m_books = new Book[other.nBooksCapacity];

    for (std::size_t index{ 0 }; index < other.nBooksSize; ++index) {
        m_books[index] = other.m_books[index];
    }

    nBooksCapacity = other.nBooksCapacity;
    nBooksSize = other.nBooksSize;
}

void Library::allocateData(std::size_t newCapacity) {
    if (newCapacity <= nBooksSize) {
        newCapacity = nBooksCapacity * BOOKS_CAPACITY_MULTIPLIER;
    }

    Book* blockOfMem{ new Book[newCapacity] };

    for (std::size_t index{ 0 }; index < nBooksSize; ++index) {
        blockOfMem[index] = m_books[index];
    }

    delete[] m_books;
    m_books = blockOfMem;

    nBooksCapacity = newCapacity;
}
