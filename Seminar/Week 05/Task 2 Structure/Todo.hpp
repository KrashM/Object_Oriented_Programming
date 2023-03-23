#pragma once

class Todo{

    public:
        Todo();
        Todo(char const * const &, unsigned const &, bool const &);
        Todo(Todo const &);
        ~Todo();

        Todo &operator =(Todo const &);

        void complete();
        void print() const;
    
    private:
        void copyFrom(Todo const &);
        void free();

        char *description;
        unsigned id;
        bool done;

};