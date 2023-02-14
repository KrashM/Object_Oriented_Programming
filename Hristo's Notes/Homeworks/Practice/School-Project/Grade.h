#pragma once

#include "Subject.h"

class Grade{

    private:
        Subject subject;
        short grade;

    public:
        Grade();
        Grade(const Subject, const short);
        Grade(const Grade &);

        Grade &operator =(const Grade &);

        const char *toString() const;

};