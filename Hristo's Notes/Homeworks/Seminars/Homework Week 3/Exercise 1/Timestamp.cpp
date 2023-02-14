#include "Timestamp.h"

Timestamp::Timestamp(unsigned seconds){

    this->hours = seconds / 3600;
    seconds = seconds % 3600;

    this->minutes = seconds / 60;
    seconds = seconds % 60;

    this->seconds = seconds;

}

char* Timestamp::toString(){

    char *result = new char[9];
    result[0] = '0' + hours / 10;
    result[1] = '0' + hours % 10;
    result[2] = ':';
    result[3] = '0' + minutes / 10;
    result[4] = '0' + minutes % 10;
    result[5] = ':';
    result[6] = '0' + seconds / 10;
    result[7] = '0' + seconds % 10;
    result[8] = '\0';

    return result;

}

unsigned Timestamp::toSeconds(){

    return this->seconds + this->minutes * 60 + this->hours * 3600;

}

Timestamp Timestamp::add(Timestamp time1, Timestamp time2){

    unsigned resultSeconds = time1.toSeconds() + time2.toSeconds();
    Timestamp result(resultSeconds);
    return result;

}