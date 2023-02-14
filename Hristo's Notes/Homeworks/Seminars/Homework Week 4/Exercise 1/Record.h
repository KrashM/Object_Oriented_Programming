#ifndef RECORD
#define RECORD

class Record{

    private:
        char *word, *meaning;

    public:
        Record(const char *word, const char *meaning);
        Record(const Record &rec);
        Record();
        ~Record();

        Record &operator = (const Record &rec);

        void setWord(const char *word);
        void setMeaning(const char *meaning);
        static void swap(Record &rec1, Record &rec2);
        const char *getWord();
        const char *getMeaning();
        char *toString();
        bool equal(const char *word);
        static bool compare(Record &rec1, Record &rec2);

};

#endif