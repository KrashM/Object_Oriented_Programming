// Да се реализират методите на този клас...

struct Sum{

    Sum();
    Sum(const size_t &);
    ~Sum();

    void add(const int &);
    void removeLast();

    void changeAt(const int &, const size_t &);

    int getSum() const;

    int *array;
    size_t index;

};