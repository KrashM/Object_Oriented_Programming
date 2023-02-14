#ifndef TIMESTAMP
#define TIMESTAMP

class Timestamp{

    private:
        unsigned hours, minutes, seconds;

    public:
        Timestamp(unsigned seconds);
        char* toString();
        static Timestamp add(Timestamp time1, Timestamp time2);
        unsigned toSeconds();

};

#endif