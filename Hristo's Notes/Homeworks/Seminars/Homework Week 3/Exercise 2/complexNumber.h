#ifndef CNUMBER
#define CNUMBER

class complexNumber{

    private:
        int a, b;

    public:
        complexNumber(int a, int b);
        char* toString();
        complexNumber operator +(complexNumber n);
        complexNumber operator *(complexNumber n);

};

#endif