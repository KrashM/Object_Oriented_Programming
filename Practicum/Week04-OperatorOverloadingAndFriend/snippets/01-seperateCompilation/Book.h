#pragma once

/*
#ifndef BOOK_H
#define BOOK_H
*/

#include <cstddef>

const std::size_t MAX_BOOK_NAME_SIZE{ 100 };

class Book {
public:
    Book();
    Book(const char* name, unsigned yearOfPublication);

    const char* getName() const;

    void print() const;

private:
    char m_name[MAX_BOOK_NAME_SIZE]{};
    unsigned m_yearOfPublication{ 0 };
};

// #endif -> Only if you're using #ifndef
