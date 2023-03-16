// Да се реализират методите на този клас...

struct Beer{

    Beer(const char * const &, const int &);
    ~Beer();

    char *getName() const;
    int getML() const;

    void add(const Beer &);
    void fill(const int &);
    bool check(const char * const &);

    char *name;
    int ml;

};