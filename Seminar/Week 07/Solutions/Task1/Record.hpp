#pragma once

#include <type_traits>
#include <ostream>
#include <sstream>

using std::ostream;
using std::stringstream;
using std::is_constructible;

class Record{

    public:
        Record() = delete;
        Record(char const * const, char const * const);
        Record(Record const &);
        ~Record();

        Record &operator =(Record const &);

        char const *getKey() const;
        char const *getValue() const;

        friend bool operator ==(Record const &, Record const &);
        friend bool operator !=(Record const &, Record const &);

        friend ostream &operator <<(ostream &, Record const &);

    private:
        void copyFrom(Record const &);
        void free();

        char *key, *value;

};

#ifdef TEST
#ifndef DOCTEST_LIBRARY_INCLUDED
#define DOCTEST_CONFIG_IMPLEMENT
#include "../../../utils/doctest.h"
#endif

TEST_SUITE("Testing constructors"){

    TEST_CASE("Default constructor"){

        CHECK(!is_constructible<Record>::value);

    }

    TEST_CASE("Parametric constructor"){

        Record r("Hello", "Zdravei");
        
        REQUIRE(r.getKey());
        REQUIRE(r.getValue());

        CHECK(!strcmp(r.getKey(), "Hello"));
        CHECK(!strcmp(r.getValue(), "Zdravei"));

    }

    TEST_CASE("Copy constructor"){

        Record r("Hello", "Zdravei");
        Record r1(r), r2 = r;

        REQUIRE(r.getKey());
        REQUIRE(r.getValue());
        REQUIRE(r1.getKey());
        REQUIRE(r1.getValue());
        REQUIRE(r2.getKey());
        REQUIRE(r2.getValue());
        
        CHECK(r1 == r);
        CHECK(r2 == r);

    }

}

TEST_CASE("Testing destructor"){

    Record r("Hello", "Zdravei");
    
    REQUIRE(r.getKey());
    REQUIRE(r.getValue());

    r.~Record();

    CHECK_EQ(r.getKey(), nullptr);
    CHECK_EQ(r.getValue(), nullptr);

}

TEST_SUITE("Testing operators"){

    TEST_CASE("Operator ="){

        Record r1("Table", "Masa");

        REQUIRE(r1.getKey());
        REQUIRE(r1.getValue());

        Record r2("Zdravei", "Hello");
        r2 = r1;

        REQUIRE(r2.getKey());
        REQUIRE(r2.getValue());

        CHECK(r1 == r2);

    }

    TEST_CASE("Operator =="){

        Record r("Hello", "Zdravei"), r1 = r;

        REQUIRE(r.getKey());
        REQUIRE(r.getValue());
        REQUIRE(r1.getKey());
        REQUIRE(r1.getValue());

        CHECK(r == r1);

    }

    TEST_CASE("Operator !="){

        Record r("Hello", "Zdravei"), r1("Privet", "Zdravei");

        REQUIRE(r.getKey());
        REQUIRE(r.getValue());
        REQUIRE(r1.getKey());
        REQUIRE(r1.getValue());

        CHECK(r != r1);

    }

    TEST_CASE("Operator <<"){

        Record r("Hello", "Zdravei");

        REQUIRE(r.getKey());
        REQUIRE(r.getValue());

        stringstream ss;

        ss << r;

        CHECK_EQ(ss.str(), "Hello - Zdravei");

    }

}

#endif