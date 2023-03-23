#pragma once

#include "Book.h"

const std::size_t BOOKS_INITIAL_CAPACITY{ 2 };
const std::size_t BOOKS_CAPACITY_MULTIPLIER{ 2 };

class Library {
public:
    Library();
    Library(const Library& other);
    ~Library();

    void addBook(const Book& book);
    bool removeBook(const char* name);

    void printInfo() const;

    Library& operator=(const Library& other);

private:
    void deleteData();
    void copyDataFrom(const Library& other);
    void allocateData(std::size_t newCapacity);

private:
    Book* m_books{ nullptr };
    std::size_t nBooksSize{ 0 };
    std::size_t nBooksCapacity{ 0 };
};
