#include "SimpleDefn.h"
#include <iostream>

using std::cout;

class CalcDefn: public SimpleDefn{

    public:
        CalcDefn(const char *, const char *);

        void printValue() const;

    private:
        bool nameIsValid(const char *) override;
        bool valueIsValid(const char *) override;

};