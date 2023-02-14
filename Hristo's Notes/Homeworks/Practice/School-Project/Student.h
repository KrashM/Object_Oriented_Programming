#pragma once

#include "Class.h"
#include "Grade.h"
#include "Date.h"
#include "../../../../includes/Vector.h"

class Student{

    private:
        Vector<Grade> grades;
        Date birthDate;
        Class _class;
        char *firstName, *lastName, *email, *phone;

    public:
        Student();
        Student(const char *, const char *, const char *, const Date &, const Class &, const Vector<Grade>);
        Student(const Student &);
        ~Student();

        Student &operator =(const Student &);
        const char *toString() const;

};