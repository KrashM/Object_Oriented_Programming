#include "Student.h"
#include <cstring>

Student::Student(){

    this -> firstName = new char[1];
    this -> firstName[0] = '\0';
    this -> lastName = new char[1];
    this -> lastName[0] = '\0';
    this -> phone = new char[1];
    this -> phone[0] = '\0';
    this -> email = new char[1];
    this -> email[0] = '\0';

}

Student::Student(const char *firstName, const char *lastName, const char *phone, const Date &birthDate, const Class &_class, const Vector<Grade> grades){

    this -> firstName = new char[strlen(firstName) + 1];
    strcpy(this -> firstName, firstName);
    this -> lastName = new char[strlen(lastName) + 1];
    strcpy(this -> lastName, lastName);
    this -> email = new char[strlen(firstName) + strlen(lastName) + 11];
    strcpy(this -> email, firstName);
    strcat(this -> email, ".");
    strcat(this -> email, lastName);
    strcat(this -> email, "@email.bg");
    this -> phone = new char[strlen(phone) + 5];
    strcpy(this -> phone, "+359");
    strcat(this -> phone, phone);
    this -> birthDate = birthDate;
    this -> _class = _class;
    this -> grades = grades;

}

Student::Student(const Student &other){

    this -> firstName = new char[strlen(other.firstName) + 1];
    strcpy(this -> firstName, other.firstName);
    this -> lastName = new char[strlen(other.lastName) + 1];
    strcpy(this -> lastName, other.lastName);
    this -> email = new char[strlen(other.firstName) + strlen(other.lastName) + 11];
    strcpy(this -> email, other.firstName);
    strcat(this -> email, ".");
    strcat(this -> email, other.lastName);
    strcat(this -> email, "@email.bg");
    this -> phone = new char[strlen(other.phone) + 1];
    strcpy(this -> phone, other.phone);
    this -> birthDate = other.birthDate;
    this -> _class = other._class;
    this -> grades = other.grades;

}

Student::~Student(){

    delete[] this -> firstName;
    delete[] this -> lastName;
    delete[] this -> phone;
    delete[] this -> email;

}

Student &Student::operator =(const Student &other){

    if(this != &other){

        this -> firstName = new char[strlen(other.firstName) + 1];
        strcpy(this -> firstName, other.firstName);
        this -> lastName = new char[strlen(other.lastName) + 1];
        strcpy(this -> lastName, other.lastName);
        this -> email = new char[strlen(other.firstName) + strlen(other.lastName) + 11];
        strcpy(this -> email, other.firstName);
        strcat(this -> email, ".");
        strcat(this -> email, other.lastName);
        strcat(this -> email, "@email.bg");
        this -> phone = new char[strlen(other.phone) + 1];
        strcpy(this -> phone, other.phone);
        this -> birthDate = other.birthDate;
        this -> _class = other._class;
        this -> grades = other.grades;

    }

    return *this;

}

const char *Student::toString() const{

    char *result = new char[1024];
    result[0] = '\0';

    strcat(result, "First name: ");
    strcat(result, this -> firstName);
    strcat(result, "\n");
    strcat(result, "Last name: ");
    strcat(result, this -> lastName);
    strcat(result, "\n");
    strcat(result, "Birth date: ");
    strcat(result, this -> birthDate.toString());
    strcat(result, "\n");
    strcat(result, "Email: ");
    strcat(result, this -> email);
    strcat(result, "\n");
    strcat(result, "Phone: ");
    strcat(result, this -> phone);
    strcat(result, "\n");
    // strcat(result, "Class: ");
    // strcat(result, this -> _class.toString());
    strcat(result, "Grades: \n");
    strcat(result, this -> grades.toString());

    return result;

}