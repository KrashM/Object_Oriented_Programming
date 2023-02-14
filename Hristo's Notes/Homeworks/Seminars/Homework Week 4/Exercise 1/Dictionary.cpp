#include "Dictionary.h"
#include <cstring>

Dictionary::Dictionary(){ this -> size = 0; }

Dictionary::Dictionary(Record records[], int size){

    this -> size = size;
    for(int i = 0; i < this -> size; i++)
        this -> records[i] = records[i];

}

bool Dictionary::add(const Record &newRecord){

    if(this -> size == MAX_CAPACITY) return false;
    this -> records[this -> size++] = newRecord;
    return true;

}

bool Dictionary::remove(const char *word){

    for(int i = 0; i < this -> size; i++)
        if(!strcmp(this -> records[i].getWord(), word)){

            for(int j = i; j < this -> size - 1; j++) this -> records[j] = this -> records[j + 1];
            this -> records[this -> size - 1].~Record();
            this -> size--;
            return true;

        }

    return false;

}

const char* Dictionary::findMeaning(const char *word){

    for(int i = 0; i < this -> size; i++)
        if(this -> records[i].equal(word))
            return this -> records[i].getMeaning();

    return nullptr;

}

const char* Dictionary::getByIndex(int index){ return this -> records[index].getMeaning(); }

char* Dictionary::toString(){

    char *result = new char[1000];
    int index = 0;
    for(int i = 0; i < this -> size; i++){

        char *rec = this -> records[i].toString();
        int len = strlen(rec);
        for(int j = 0; j < len; j++) result[index + j] = rec[j];
        result[index + len] = '\n';
        index += len + 1;

    }

    result[index] = '\0';
    
    return result;

}

int Dictionary::getSize(){ return this -> size; }

void Dictionary::sort(){

    for(int i = 0; i < this -> size - 1; i++)
        for(int j = i + 1; j < this -> size; j++)
            if(Record::compare(this -> records[i], this -> records[j]))
                Record::swap(this -> records[i], this -> records[j]);

}