#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"
#include "Dictionary.h"

// Dictionary.cpp Record.cpp

TEST_SUITE("test the constructors of the dictionary class") {
  TEST_CASE("test default constructor") {
    Dictionary dict;
    CHECK_EQ(dict.getSize(), 0);
  }
  TEST_CASE("test param constructor") {
    Record rec1 = Record("asd", "M-asd");
    Record rec2 = Record("asdf", "M-asdf");

    Record *records = new Record[2];
    records[0] = rec1;
    records[1] = rec2;
    Dictionary dict = Dictionary(records, 2);

    CHECK_EQ(dict.getSize(), 2);
    // CHECK_EQ(dict.getByIndex(0), "M-asd");
    // CHECK_EQ(dict.getByIndex(1), "M-asdf");
  }
}