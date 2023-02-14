#pragma once

class ToDo{

     private:
        char *description;
        unsigned id;
        bool isDone;

    public:
        ToDo();
        ToDo(const int id, const char *description, const bool isDone);
        ToDo(const ToDo &other);
        ~ToDo();

        const ToDo &operator =(const ToDo &other);
        void markAsDone();
        const char *toString() const;

};