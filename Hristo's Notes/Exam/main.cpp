#include "ParamDefn.h"
#include "CalcDefn.h"

int main(){

    ParamDefn var("var_name", "My name is #1. - Hello #1, I'm #2!");
    var.print();

    CalcDefn var2("message_calc", "`I was born in {26 * 77} but I am still {10 + 9} years old.`");
    var2.printValue();

}