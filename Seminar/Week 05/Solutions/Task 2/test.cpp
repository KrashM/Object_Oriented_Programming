#include "Todo.hpp"

int main(){

    Todo test("Complete homework 5", 1, false);
    test.print();

    test.complete();
    test.print();

}