#pragma once

class Subject{

    private:
        char *name, *description;

    public:
        Subject();
        Subject(const char *, const char *);
        Subject(const Subject &);
        ~Subject();

        const Subject &operator =(const Subject&);
        const char *getName() const;
        const char *toString() const;

};