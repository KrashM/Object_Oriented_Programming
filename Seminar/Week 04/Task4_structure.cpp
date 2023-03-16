struct Interval{

    Interval();
    Interval(int const &, int const &);

    int getLeft() const;
    int getRight() const;

    void setLeft(int const &);
    void setRight(int const &);

    unsigned getLength() const;
    bool isInInterval(int const &) const;

    unsigned countOfPrimeNumbers() const;
    unsigned countOfNumbers() const;
    unsigned countOfNumbersNonRepeating() const;

    bool arePowersOfTwo() const;
    Interval intersect(Interval const &) const;
    Interval unification(Interval const &) const;
    bool isSuperInterval(Interval const &) const;

    int a, b;

};