#define CATCH_CONFIG_MAIN
#include <cstring>
#include "catch2/catch2.hpp"
#include "../Headers/myString.h"

TEST_CASE ("constructors, operators = and ==")
{
    SECTION ("default constructor")
    {
        MyString string;

        REQUIRE (string.getSize() == 0);
        REQUIRE (string.c_str() == nullptr);
        REQUIRE (string == string);
    }

    SECTION ("constructor with parameter")
    {
        SECTION ("non-empty string string")
        {
            MyString pesho("Pesho");

            REQUIRE (pesho.getSize() == 5);
            REQUIRE (strcmp(pesho.c_str(), "Pesho") == 0);
            REQUIRE (pesho == pesho);
        }

        SECTION ("null string")
        {
            MyString nullString(nullptr);

            REQUIRE (nullString.getSize() == 0);
            REQUIRE (nullString.c_str() == nullptr);
            REQUIRE (nullString == nullString);
        }

        SECTION ("empty string")
        {
            MyString emptyString("");

            REQUIRE (emptyString.getSize() == 0);
            REQUIRE (strcmp(emptyString.c_str(), "") == 0);
            REQUIRE (emptyString == emptyString);
        }

    }

    SECTION ("copy constructor")
    {
        MyString pesho("Pesho");
        MyString copyPesho(pesho);

        REQUIRE (pesho.getSize() == copyPesho.getSize());
        REQUIRE (strcmp(pesho.c_str(), copyPesho.c_str()) == 0);
        REQUIRE (pesho == copyPesho);
    }

    SECTION ("operator =")
    {
        MyString pesho("Pesho");
        MyString pesho2;
        pesho2 = pesho;

        REQUIRE (pesho.getSize() == pesho2.getSize());
        REQUIRE (strcmp(pesho.c_str(), pesho2.c_str()) == 0);
        REQUIRE (pesho == pesho2);
    }
}

TEST_CASE ("function `at` and operator[]")
{
    MyString pesho = "Pesho";
    
    SECTION ("non-empty string")
    {
        SECTION ("function `at`")
        {
            REQUIRE (pesho.getSize() == 5);

            REQUIRE (pesho.at(0) == 'P');
            REQUIRE (pesho.at(1) == 'e');
            REQUIRE (pesho.at(2) == 's');
            REQUIRE (pesho.at(3) == 'h');
            REQUIRE (pesho.at(4) == 'o');
            REQUIRE_THROWS (pesho.at(5), "Ivalid index");
            REQUIRE_THROWS (pesho.at(-1), "Ivalid index");
        }

        SECTION ("operator[]")
        {
            REQUIRE (pesho[0] == 'P');
            REQUIRE (pesho[1] == 'e');
            REQUIRE (pesho[2] == 's');
            REQUIRE (pesho[3] == 'h');
            REQUIRE (pesho[4] == 'o');
        }
    }

    SECTION ("null string")
    {
        MyString nullString;
        REQUIRE_THROWS (nullString.at(0), "Ivalid index");
    }

    SECTION ("empty string")
    {
        MyString emptyString("");
        REQUIRE_THROWS (emptyString.at(0), "Ivalid index");
    }
}

TEST_CASE("functions `front` and `back`")
{
    SECTION ("non-empty string")
    {
        MyString pesho = "Pesho";
        REQUIRE (pesho.front() == 'P');
        REQUIRE (pesho.back() == 'o');
    }

    SECTION ("1-letter string")
    {
        MyString letter = "a";
        REQUIRE (letter.front() == 'a');
        REQUIRE (letter.back() == 'a');
        REQUIRE (letter.front() == letter.back());
    }
}

TEST_CASE ("function `empty`")
{
    SECTION ("null string")
    {
        MyString nullString;
        REQUIRE (nullString.empty());
    }

    SECTION ("empty string")
    {
        MyString emptyString("");
        REQUIRE (emptyString.empty());
    }

    SECTION ("non-empty string")
    {
        MyString pesho("Pesho");
        REQUIRE_FALSE (pesho.empty());
    }
}

TEST_CASE ("function `push_back`")
{
    SECTION ("non-empty string")
    {
        MyString pesho = "Pesh";

        pesho.push_back('o');
        REQUIRE (pesho.getSize() == 5);
        REQUIRE (strcmp(pesho.c_str(), "Pesho") == 0);
    }

    SECTION ("null string")
    {
        MyString nullString;

        nullString.push_back('o');
        REQUIRE (nullString.getSize() == 1);
        REQUIRE (strcmp(nullString.c_str(), "o") == 0);
    }

    SECTION ("empty string")
    {
        MyString emptyString;

        emptyString.push_back('o');
        REQUIRE (emptyString.getSize() == 1);
        REQUIRE (strcmp(emptyString.c_str(), "o") == 0);
    }
}

TEST_CASE ("pop_back")
{
    SECTION ("string with more than 1 letter")
    {
        MyString pesho = "Peshoo";
        pesho.pop_back();

        REQUIRE (pesho.getSize() == 5);
        REQUIRE (strcmp(pesho.c_str(), "Pesho") == 0);
    }

    SECTION ("1-letter string")
    {
        MyString letter = "a";
        letter.pop_back();

        REQUIRE (letter.getSize() == 0);
        REQUIRE (letter.c_str() == nullptr);
    }
}

// operator += with char uses push_back()

TEST_CASE ("operator += with string")
{
    SECTION ("non-empty string with non-empty string")
    {
        MyString pesho = "Pesho", space = " ", kolev = "Kolev";
        pesho += space;
        pesho += kolev;

        REQUIRE (pesho.getSize() == 11);
        REQUIRE (strcmp(pesho.c_str(), "Pesho Kolev") == 0);
    }

    SECTION ("non-empty string with empty string")
    {
        MyString pesho = "Pesho", emptyString = "";
        pesho += emptyString;

        REQUIRE (pesho.getSize() == 5);
        REQUIRE (strcmp(pesho.c_str(), "Pesho") == 0);
    }

    SECTION ("non-empty string with null string")
    {
        MyString pesho = "Pesho", nullString;
        pesho += nullString;

        REQUIRE (pesho.getSize() == 5);
        REQUIRE (strcmp(pesho.c_str(), "Pesho") == 0);
    }

    SECTION ("empty string with non-empty string")
    {
        MyString pesho = "Pesho", emptyString = "";
        emptyString += pesho;

        REQUIRE (emptyString.getSize() == 5);
        REQUIRE (strcmp(emptyString.c_str(), "Pesho") == 0);
    }

    SECTION ("empty string with empty string")
    {
        MyString emptyString1 = "", emptyString2 = "";
        emptyString1 += emptyString2;

        REQUIRE (emptyString1.getSize() == 0);
        REQUIRE (strcmp(emptyString1.c_str(), "") == 0);
    }

    SECTION ("empty string with null string")
    {
        MyString emptyString = "", nullString;
        emptyString += nullString;

        REQUIRE (emptyString.getSize() == 0);
        REQUIRE (strcmp(emptyString.c_str(), "") == 0);
    }

    SECTION ("null string with non-empty string")
    {
        MyString pesho = "Pesho", nullString;
        nullString += pesho;

        REQUIRE (nullString.getSize() == 5);
        REQUIRE (strcmp(nullString.c_str(), "Pesho") == 0);       
    }

    SECTION ("null string with empty string")
    {
        MyString emptyString = "", nullString;
        nullString += emptyString;

        REQUIRE (nullString.getSize() == 0);
        REQUIRE (strcmp(nullString.c_str(), "") == 0);       
    }

    SECTION ("null string with null string")
    {
        MyString nullString1, nullString2;
        nullString1 += nullString2;

        REQUIRE (nullString1.getSize() == 0);
        REQUIRE (nullString1 == nullptr);       
    }
}

TEST_CASE ("operator <")
{
    SECTION ("non-empty strings")
    {
        MyString pesho = "Pesho", misho = "Misho";

        REQUIRE (misho < pesho);
        REQUIRE_FALSE (pesho < misho);
    }

    SECTION ("empty string")
    {
        MyString pesho = "Pesho", emptyString = "";

        REQUIRE (emptyString < pesho);
        REQUIRE_FALSE (pesho < emptyString);
    }

    SECTION ("null string")
    {
        MyString pesho = "Pesho", nullString;

        REQUIRE (nullString < pesho);
        REQUIRE_FALSE (pesho < nullString);
    }
}

// operator + uses +=