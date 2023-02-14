#include "CalcDefn.h"

CalcDefn::CalcDefn(const char *varName, const char *varValue){

    if(!nameIsValid(varName)) throw invalid_argument("Variable name is incorrect");
    if(!valueIsValid(varValue)) throw invalid_argument("Variable value is incorrect");

    this -> varName = new char[strlen(varName) + 1];
    this -> varValue = new char[strlen(varValue) + 1];

    strcpy(this -> varName, varName);
    strcpy(this -> varValue, varValue);

}

size_t pow(const size_t n, const size_t power){

    if(power == 0) return 1;
    if(power == 1) return n;
    return pow(n, power - 1);

}

void CalcDefn::printValue() const{

    size_t size = strlen(this -> varValue);
    for(size_t i = 0; i < size; i++){

        if(this -> varValue[i] == '{'){
            
            i++;

            size_t lenght = 0;
            for(; this -> varValue[i + lenght] >= '0' && this -> varValue[i + lenght] <= '9'; lenght++);

            size_t n1 = 0, n2 = 0, powTen = pow(10, lenght - 1);
            char operation;

            for(; i < size; i++){

                if(this -> varValue[i] >= '0' && this -> varValue[i] <= '9'){

                    n1 += (this -> varValue[i] - '0') * powTen;
                    powTen /= 10;

                }
                else break;

            }

            for(; i < size; i++)
                if(this -> varValue[i] == '+' || this -> varValue[i] == '-' || this -> varValue[i] == '*'){

                    operation = this -> varValue[i++];
                    break;

                }
            
            for(; !(this -> varValue[i] >= '0' && this -> varValue[i] <= '9'); i++);

            lenght = 0;
            for(; this -> varValue[i + lenght] >= '0' && this -> varValue[i + lenght] <= '9'; lenght++);

            powTen = pow(10, lenght - 1);
            
            for(; i < size; i++){

                if(this -> varValue[i] >= '0' && this -> varValue[i] <= '9'){

                    n2 += (this -> varValue[i] - '0') * powTen;
                    powTen /= 10;

                }
                else break;

            }

            cout << ((operation == '+') ? n1 + n2 : (operation == '-') ? n1 - n2 : n1 * n2);

        }
        else cout << this -> varValue[i];

    }

}

bool CalcDefn::nameIsValid(const char *name){

    const char *ending = "_calc";
    size_t size = strlen(name), sizeEnding = strlen(ending);
    for(size_t i = 0; i < strlen(ending); i++)
        if(name[size - i - 1] != ending[sizeEnding - i - 1]) return false;
    return true;

}

bool CalcDefn::valueIsValid(const char *name){

    if(name[0] != '`' || name[strlen(name) - 1] != '`') return false;
    return true;

}