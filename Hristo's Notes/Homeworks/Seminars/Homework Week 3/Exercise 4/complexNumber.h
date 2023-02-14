#ifndef CNUMBER
#define CNUMBER

class complexNumber{

    private:
        double a, b;

    public:
        complexNumber(double a, double b);
        complexNumber();
        void setValue(double a, double b);
        char* toString();
        complexNumber operator +(complexNumber n);
        complexNumber operator *(complexNumber n);

};

#endif