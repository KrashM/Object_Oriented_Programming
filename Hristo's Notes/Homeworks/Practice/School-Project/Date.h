#pragma once

class Date{

    private:
        unsigned day, mounth, year;

    public:
        Date();
        Date(unsigned, unsigned, unsigned);
        Date(const Date &);

        const Date &operator =(const Date &);

        const char *toString() const;

};