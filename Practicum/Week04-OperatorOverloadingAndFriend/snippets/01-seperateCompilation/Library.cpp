#include "Library.h"

#include <iostream>
#include <cstring>

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
