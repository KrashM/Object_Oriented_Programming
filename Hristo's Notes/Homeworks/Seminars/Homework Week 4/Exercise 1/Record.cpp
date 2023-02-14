#include "Record.h"
#include <cstring>

Record::Record(const char *word, const char *meaning){

    int wordLen = strlen(word), meaningLen = strlen(meaning);
    this -> word = new char[wordLen + 1];
    this -> meaning = new char[meaningLen + 1];
    for(int i = 0; i < strlen(word); i++) this -> word[i] = word[i];
    this -> word[wordLen] = '\0';
    for(int i = 0; i < strlen(meaning); i++) this -> meaning[i] = meaning[i];
    this -> meaning[meaningLen] = '\0';

}

Record::Record(const Record &rec){

    int wordLen = strlen(rec.word), meaningLen = strlen(rec.meaning);
    this -> word = new char[wordLen + 1];
    this -> meaning = new char[meaningLen + 1];
    for(int i = 0; i < wordLen; i++) this -> word[i] = rec.word[i];
    this -> word[wordLen] = '\0';
    for(int i = 0; i < meaningLen; i++) this -> meaning[i] = rec.meaning[i];
    this -> meaning[meaningLen] = '\0';

}

Record::Record(){

    this -> word = new char[1];
    this -> meaning = new char[1];

}

Record::~Record(){

    delete[] this -> word;
    delete[] this -> meaning;

}

Record &Record::operator =(const Record &rec){

    if(this != &rec){

        int wordLen = strlen(rec.word), meaningLen = strlen(rec.meaning);
        for(int i = 0; i < wordLen; i++) this -> word[i] = rec.word[i];
        this -> word[wordLen] = '\0';
        for(int i = 0; i < meaningLen; i++) this -> meaning[i] = rec.meaning[i];
        this -> meaning[meaningLen] = '\0';

    }

    return *this;

}

void Record::setWord(const char *word){ for(int i = 0; i < strlen(word); i++) this -> word[i] = word[i]; }
void Record::setMeaning(const char *meaning){ for(int i = 0; i < strlen(meaning); i++) this -> meaning[i] = meaning[i]; }
const char *Record::getWord(){ return this -> word; }
const char *Record::getMeaning(){ return this -> meaning; }

void Record::swap(Record &rec1, Record &rec2){

    Record temp = Record(rec1);
    rec1 = rec2;
    rec2 = temp;

}

char* Record::toString(){

    char *result = new char[1];
    int wordLen = strlen(this -> word), meaningLen = strlen(this -> meaning);

    for(int i = 0; i < wordLen; i++)
        result[i] = this -> word[i];
    
    result[wordLen] = '-';
    
    for(int i = 0; i < meaningLen; i++)
        result[wordLen + i + 1] = this -> meaning[i];

    result[wordLen + meaningLen + 1] = '\0';

    return result;

}

bool Record::equal(const char *word){

    int firstLen = strlen(this -> word), secondLen = strlen(word);
    if(firstLen != secondLen) return false;
    for(int i = 0; i < firstLen; i++)
        if(this -> word[i] != word[i]) return false;
    return true;

}

int min(int a, int b){ return (a < b) ? a : b; }

bool Record::compare(Record &rec1, Record &rec2){

    int firstWordLen = strlen(rec1.word), secondWordLen = strlen(rec2.word);
    for(int i = 0; i < min(firstWordLen, secondWordLen); i++)
        if(rec1.word[i] != rec2.word[i])
            if(rec1.word[i] > rec2.word[i]) return true;
            else return false;
    if(firstWordLen > secondWordLen) return true;
    else if(firstWordLen < secondWordLen) return false;

    int firstMeaningLen = strlen(rec1.meaning), secondMeaningLen = strlen(rec2.meaning);
    for(int i = 0; i < min(firstMeaningLen, secondMeaningLen); i++)
        if(rec1.meaning[i] != rec2.meaning[i])
            if(rec1.meaning[i] > rec2.meaning[i]) return true;
            else return false;
    if(firstMeaningLen > secondMeaningLen) return true;
    return false;

}