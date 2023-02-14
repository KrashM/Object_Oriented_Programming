#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../doctest.h"
#include "ToDo.h"
#include <cstring>

TEST_SUITE("Testing ToDo class"){

    TEST_CASE("Test default constructor"){

        ToDo todo;
        CHECK_EQ(strcmp(todo.toString(), "Id: 0\nDescription:\n\nDone: No"), 0);

    }

    TEST_CASE("Test parametric constructor"){

        ToDo todo(1, "Hello world!", false);
        CHECK_EQ(strcmp(todo.toString(), "Id: 1\nDescription:\nHello world!\nDone: No"), 0);

    }
    
    TEST_CASE("Test copy constructor"){

        ToDo todo(1, "Hello world!", false);
        ToDo newToDo(todo);
        CHECK_EQ(strcmp(newToDo.toString(), "Id: 1\nDescription:\nHello world!\nDone: No"), 0);

    }
    
    TEST_CASE("Test = operator"){

        ToDo todo = ToDo(1, "Hello world!", false);
        CHECK_EQ(strcmp(todo.toString(), "Id: 1\nDescription:\nHello world!\nDone: No"), 0);

    }
    
    TEST_CASE("Test mark as done"){

        ToDo todo(1, "Hello world!", false);
        todo.markAsDone();
        CHECK_EQ(strcmp(todo.toString(), "Id: 1\nDescription:\nHello world!\nDone: Yes"), 0);

    }

}