#pragma once

#include "Record.hpp"
#include <cstddef>

#define MAX_CAPACITY 500

using std::size_t;

class Dictionary{

    public:
        Dictionary() = default;
        Dictionary(Record const * const * const, size_t const);
        Dictionary(Dictionary const &);
        ~Dictionary();

        Dictionary &operator =(Dictionary const &);

        void add(Record const &);
        void remove(char const * const);

        char const * const operator [](char const * const) const;
        char const * const operator [](size_t const) const;
    
        void sort();

        size_t getSize() const;

        friend bool operator ==(Dictionary const &, Dictionary const &);
        friend bool operator !=(Dictionary const &, Dictionary const &);

        friend ostream &operator <<(ostream &, Dictionary const &);

    private:
        void copyFrom(Dictionary const &);
        void free();

        Record *records[MAX_CAPACITY];
        size_t size = 0;

};

#ifdef TEST

TEST_SUITE("Testing Dictionary"){

    TEST_CASE("Testing lifetime implementations"){
        
        Record *records[3];

        records[0] = new Record("Table", "Masa");
        records[1] = new Record("Hello", "There");
        records[2] = new Record("Maze", "Labirinth");

        SUBCASE("Testing default"){

            Dictionary d;
            CHECK_FALSE(d.getSize());

        }

        SUBCASE("Testing parametric"){

            Dictionary d(records, 3);
            CHECK(!strcmp(d[(size_t)0], "Masa"));
            CHECK(!strcmp(d[1], "There"));
            CHECK(!strcmp(d[2], "Labirinth"));

        }

        SUBCASE("Testing copy"){

            Dictionary d(records, 3), d1 = d;
            CHECK(d == d1);

        }

        SUBCASE("Testing destructor"){

            Dictionary d(records, 3);

            d.~Dictionary();

            CHECK(!strcmp(d[(size_t)0], ""));
            CHECK(!strcmp(d[1], ""));
            CHECK(!strcmp(d[2], ""));

        }

        delete records[0];
        delete records[1];
        delete records[2];
    
    }

    TEST_CASE("Testing operators"){

        Record *records[3];

        records[0] = new Record("Table", "Masa");
        records[1] = new Record("Hello", "There");
        records[2] = new Record("Maze", "Labirinth");

        Dictionary dict(records, 3);

        REQUIRE_EQ(dict.getSize(), 3);

        SUBCASE("Testing operator ="){

            Dictionary second;
            second = dict;

            CHECK(dict == second);

        }

        SUBCASE("Testing []"){

            SUBCASE("With index"){

                CHECK(!strcmp(dict[(size_t)0], "Masa"));
                CHECK(!strcmp(dict[1], "There"));
                CHECK(!strcmp(dict[2], "Labirinth"));

            }

            SUBCASE("With string"){

                CHECK(!strcmp(dict["Table"], "Masa"));
                CHECK(!strcmp(dict["Hello"], "There"));
                CHECK(!strcmp(dict["Maze"], "Labirinth"));

            }

        }

        SUBCASE("Operator =="){

            Dictionary d(records, 3), d1 = d;
            CHECK(d == d1);

        }

        SUBCASE("Operator !="){

            Dictionary d(records, 3), d1;
            d1.add(Record("Az sum", "I am"));
            CHECK(d != d1);

        }

        SUBCASE("Testing <<"){

            Dictionary d(records, 3);
            stringstream ss;
            ss << d;
            CHECK(ss.str() == "Table - Masa\nHello - There\nMaze - Labirinth");

        }

        delete records[0];
        delete records[1];
        delete records[2];

    }

    TEST_CASE("Testing add"){

        Dictionary d;

        d.add(Record("Hello", "Zdravei"));

        CHECK(!strcmp(d["Hello"], "Zdravei"));

    }

    TEST_CASE("Testing remove"){

        Dictionary d;

        d.add(Record("Hello", "Zdravei"));
        d.remove("Hello");

        CHECK(!strcmp(d["Hello"], ""));

    }
    TEST_CASE("Testing sort"){

        Dictionary d;

        d.add(Record("Zdravei", "Hello"));
        d.add(Record("Hello", "There"));
        d.add(Record("Alternative", "Alternativa"));

        d.sort();

        stringstream ss;
        ss << d;

        CHECK(ss.str() == "Alternative - Alternativa\nHello - There\nZdravei - Hello");

    }

}

#endif