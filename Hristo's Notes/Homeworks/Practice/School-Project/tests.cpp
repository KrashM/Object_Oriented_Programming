#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../includes/doctest.h"
#include "Subject.h"
#include "Student.h"
#include "Date.h"
#include "Class.h"
#include "Grade.h"
#include <cstring>
#include <iostream>

TEST_SUITE("Testing date class"){

    TEST_CASE("Testing default constructor"){

        Date date;
        CHECK_EQ(strcmp(date.toString(), "0.0.0"), 0);

    }
    
    TEST_CASE("Testing parametric constructor"){

        Date date(22, 6, 2002);
        CHECK_EQ(strcmp(date.toString(), "22.6.2002"), 0);

    }
    
    TEST_CASE("Testing copy constructor"){

        Date date(22, 6, 2002);
        Date cpy(date);
        CHECK_EQ(strcmp(cpy.toString(), "22.6.2002"), 0);

    }
    
    TEST_CASE("Testing = operator"){

        Date date(22, 6, 2002), eq;
        eq = date;
        CHECK_EQ(strcmp(eq.toString(), "22.6.2002"), 0);

    }

}

TEST_SUITE("Testing grade class"){

    TEST_CASE("Testing default constructor"){

        Grade g;
        CHECK_EQ(strcmp(g.toString(), "Subject:  ---> Grade: 0"), 0);

    }
    
    TEST_CASE("Testing parametric constructor"){

        Grade g(Subject("Mathematics", "Very cool"), 3);
        CHECK_EQ(strcmp(g.toString(), "Subject: Mathematics ---> Grade: 3"), 0);

    }
    
    TEST_CASE("Testing copy constructor"){

        Grade g(Subject("Hello", "World"), 4);
        Grade cpy(g);
        CHECK_EQ(strcmp(cpy.toString(), "Subject: Hello ---> Grade: 4"), 0);

    }
    
    TEST_CASE("Testing = operator"){

        Grade g(Subject("Programming", "The best"), 6), eq;
        eq = g;
        CHECK_EQ(strcmp(eq.toString(), "Subject: Programming ---> Grade: 6"), 0);

    }

}

TEST_SUITE("Testing subject class"){

    TEST_CASE("Testing default constructor"){

        Subject s;
        CHECK_EQ(strcmp(s.toString(), "Name: \nDescription: "), 0);

    }
    
    TEST_CASE("Testing parametric constructor"){

        Subject s("Mathematics", "Very cool");
        CHECK_EQ(strcmp(s.toString(), "Name: Mathematics\nDescription: Very cool"), 0);

    }
    
    TEST_CASE("Testing copy constructor"){

        Subject s("Hello", "World");
        Subject cpy(s);
        CHECK_EQ(strcmp(cpy.toString(), "Name: Hello\nDescription: World"), 0);

    }
    
    TEST_CASE("Testing = operator"){

        Subject s("Programming", "The best"), eq;
        eq = s;
        CHECK_EQ(strcmp(eq.toString(), "Name: Programming\nDescription: The best"), 0);

    }

    TEST_CASE("Testing getName method"){

        Subject s = (Subject("Programming", "The best"));
        CHECK_EQ(strcmp(s.getName(), "Programming"), 0);

    }

}

TEST_SUITE("Testing student class"){

    TEST_CASE("Testing default constructor"){

        Student s;
        CHECK_EQ(strcmp(s.toString(), "First name: \nLast name: \nBirth date: 0.0.0\nEmail: \nPhone: \nGrades: \n"), 0);

    }
    
    TEST_CASE("Testing parametric constructor"){

        Vector<Grade> grades;
        Grade newGrade(Subject("Mathematics", "Very cool"), 6);
        grades.pushBack(newGrade);
        Student s("Hristo", "Kanev", "878686974", Date(22, 6, 2002), Class(), grades);
        CHECK_EQ(strcmp(s.toString(), "First name: Hristo\nLast name: Kanev\nBirth date: 22.6.2002\nEmail: Hristo.Kanev@email.bg\nPhone: +359878686974\nGrades: \nSubject: Mathematics ---> Grade: 6"), 0);

    }
    
    TEST_CASE("Testing copy constructor"){

        Vector<Grade> grades;
        grades.pushBack(Grade(Subject("Mathematics", "Very cool"), 6));
        Student s("Hristo", "Kanev", "878686974", Date(22, 6, 2002), Class(), grades);
        Student cpy(s);
        CHECK_EQ(strcmp(cpy.toString(), "First name: Hristo\nLast name: Kanev\nBirth date: 22.6.2002\nEmail: Hristo.Kanev@email.bg\nPhone: +359878686974\nGrades: \nSubject: Mathematics ---> Grade: 6"), 0);

    }
    
    TEST_CASE("Testing = operator"){

        Vector<Grade> grades;
        grades.pushBack(Grade(Subject("Mathematics", "Very cool"), 6));
        Student s("Hristo", "Kanev", "878686974", Date(22, 6, 2002), Class(), grades), eq;
        eq = s;
        CHECK_EQ(strcmp(eq.toString(), "First name: Hristo\nLast name: Kanev\nBirth date: 22.6.2002\nEmail: Hristo.Kanev@email.bg\nPhone: +359878686974\nGrades: \nSubject: Mathematics ---> Grade: 6"), 0);

    }

}