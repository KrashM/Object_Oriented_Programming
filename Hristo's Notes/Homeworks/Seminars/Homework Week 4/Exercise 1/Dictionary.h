#ifndef DICTIONARY
#define DICTIONARY
#define MAX_CAPACITY 500
#include "Record.h"

class Dictionary{

    private:
        Record records[MAX_CAPACITY];
        int size;

    public:
        Dictionary(Record records[], int size);
        Dictionary();

        bool add(const Record &newRecord);
        bool remove(const char *word);
        const char* findMeaning(const char *word);
        const char* getByIndex(int index);
        char* toString();
        int getSize();
        void sort();

};

#endif