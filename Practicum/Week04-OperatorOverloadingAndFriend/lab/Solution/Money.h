#pragma once

#include <ios>

#include "Currency.h"
#include "ConvertionRate.h"

class Money {
public:
    Money();
    Money(double money, Currency currency);

    double money() const;
    Currency currency() const;
    const char* currencyStr() const;

    Money softConvert(const ConvertionRate& convertionRate) const;
    void hardConvert(const ConvertionRate& convertionRate);

    Money operator+(double money) const;
    Money operator+(const Money& money) const;
    Money operator-(double money) const;
    Money operator-(const Money& money) const;

    Money& operator+=(double money);
    Money& operator+=(const Money& money);
    Money& operator-=(double money);
    Money& operator-=(const Money& money);

    Money operator-() const;

    bool operator==(const Money& other) const;
    bool operator!=(const Money& other) const;
    bool operator<(const Money& other) const;
    bool operator<=(const Money& other) const;
    bool operator>(const Money& other) const;
    bool operator>=(const Money& other) const;
    
    friend std::ostream& operator<<(std::ostream& out, const Money& money);

private:
    double m_money{ 0 };
    Currency m_currency{ Currency::BGN };
};
