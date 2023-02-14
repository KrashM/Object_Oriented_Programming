#ifndef DEVELOPER
#define DEVELOPER

class Developer{

    public:
        enum Position {NONE = 0, JUNIOR_DEV, DEV, SENIOR_DEV, QA, MANAGER};
        Developer();
        Developer(const char *mld, const char *mFirstName, const char *mLastName, const Position position);
        ~Developer();

        void saveToFile();
        void readFromFile();
        char *toString();
        static Position translateToPos(const char *pos);
        static const char *translateToChar(const Position pos);

    private:
        char *mld, *mFirstName, *mLastName;
        Position position;

};

#endif