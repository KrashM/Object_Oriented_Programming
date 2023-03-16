struct Time{

    Time();
    Time(unsigned const &, unsigned const &, unsigned const &);

    Time timeTillMidnight() const;
    void increaseWithSecond();
    bool isTimeForDinner() const;
    bool isTimeForParty() const;
    Time difference(Time const &) const;
    int compare(Time const &) const;
    void print() const;

    unsigned hours, minutes, seconds;

};

void sort(Time * const &, size_t const &);