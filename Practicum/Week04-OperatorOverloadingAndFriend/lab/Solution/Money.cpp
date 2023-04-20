#include "Money.h"

#include <iostream>
#include <cassert>

Money::Money() {}

Money::Money(double money, Currency currency)
    : m_money(money), m_currency(currency) {}

double Money::money() const {
    return m_money;
}

Currency Money::currency() const {
    return m_currency;
}

const char* Money::currencyStr() const {
    switch (m_currency) {
    case Currency::BGN:
        return "BGN";
    case Currency::EUR:
        return "EUR";
    case Currency::USD:
        return "USD";
    default:
        assert(false);
    }
}

Money Money::softConvert(const ConvertionRate& convertionRate) const {
    assert(m_currency == convertionRate.m_oldCurrency);
    
    return Money(m_money * convertionRate.m_excangeRate, convertionRate.m_newCurrency);
}

void Money::hardConvert(const ConvertionRate& convertionRate) {
    assert(m_currency == convertionRate.m_oldCurrency);

    m_money *= convertionRate.m_excangeRate;
    m_currency = convertionRate.m_newCurrency;
}

Money Money::operator+(double money) const {
    return Money(m_money + money, m_currency);
}

Money Money::operator+(const Money& money) const {
    assert(m_currency == money.m_currency);
    
    return Money(m_money + money.m_money, m_currency);
}

Money Money::operator-(double money) const {
    return (*this) + (-money);
}

Money Money::operator-(const Money& money) const {
    return (*this) + (-money);
}

Money& Money::operator+=(double money) {
    m_money += money;

    return *this;
}

Money& Money::operator+=(const Money& money) {
    assert(m_currency == money.m_currency);

    m_money += money.m_money;

    return *this;
}

Money& Money::operator-=(double money) {
    *this += -money;
    
    return (*this);
}

Money &Money::operator-=(const Money& money) {
    *this += -money;

    return (*this);
}

Money Money::operator-() const {
    return Money(-m_money, m_currency);
}

bool Money::operator==(const Money& other) const {
    return m_currency == other.m_currency &&
           m_money == other.m_money;
}

bool Money::operator!=(const Money& other) const {
    return !(*this == other);
}

bool Money::operator<(const Money& other) const {
    return m_currency == other.m_currency &&
           m_money < other.m_money;
}

bool Money::operator<=(const Money& other) const {
    return (*this < other) ||
           (*this == other);
}

bool Money::operator>(const Money& other) const {
    return m_currency == other.m_currency &&
           m_money > other.m_money;
}

bool Money::operator>=(const Money& other) const {
    return (*this > other) ||
           (*this == other);
}

std::ostream& operator<<(std::ostream& out, const Money& money) {
    out << money.m_money << (money.currencyStr());

    return out;
}
