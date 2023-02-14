#pragma once

class Beverage{

    private:
        double lieters, price;
        char *name;
        int calories;

    public:
        Beverage();
        Beverage(const char *name, const double lieters, const double price, const int calories);
        Beverage(const Beverage &other);
        ~Beverage();

        const bool operator ==(const Beverage &other);
        const bool operator >(const Beverage &other);

        void addLieters(const double lieters);
        const char *getName() const;
        const double getPrice() const;
        const double getLieters() const;

};