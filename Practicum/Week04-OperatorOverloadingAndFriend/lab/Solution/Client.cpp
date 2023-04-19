#include "Client.h"

#include <iostream>
#include <cstring>
#include <cassert>

Client::Client(const char* name, const char* identificationNumber, const Date& birthDate, const Money& money)
    : m_birthDay(birthDate), m_money(money) {
    setIdentificationNumber(identificationNumber);
    setName(name);
}

Client::Client(const Client &other) {
    copyDataFrom(other);
}

Client::~Client() {
    deleteData();
}

const char* Client::getName() const {
    return m_name;
}

const char* Client::getIdentificationNumber() const {
    return m_identificationNumber;
}

const Date &Client::getBirthDay() const {
    return m_birthDay;
}

const Money& Client::getMoney() const {
    return m_money;
}

bool Client::deposit(const Money& toDeposit) {
    m_money += toDeposit;
    
    return true;
}

bool Client::withdraw(const Money& toWithdraw) {
    if (m_money < toWithdraw) {
        return false;
    }

    m_money -= toWithdraw;
    
    return true;
}

void Client::convert(ConvertionRate& convertionRate) {
    m_money.hardConvert(convertionRate);
}

Client& Client::operator=(const Client& other) {
    if (this != &other) {
        deleteData();
        copyDataFrom(other);
    }

    return *this;
}

void Client::copyDataFrom(const Client& other) {
    setName(other.m_name);
    setIdentificationNumber(other.m_identificationNumber);
    m_birthDay = other.m_birthDay;
    m_money = other.m_money;
}

void Client::deleteData() {
    delete[] m_name;
    m_name = nullptr;
}

void Client::setName(const char* name) {
    delete[] m_name;
    m_name = new (std::nothrow) char[strlen(name) + 1];

    if (!m_name) {
        std::cout << "Memory problem!" << std::endl;

        assert(false);
    }

    strcpy(m_name, name);
}

void Client::setIdentificationNumber(const char* identificationNumber) {
    strcpy(m_identificationNumber, identificationNumber);
}

std::ostream& operator<<(std::ostream& out, const Client& client) {
    out << "Client:" << std::endl;
    out << "Name: " << client.m_name << std::endl;
    out << "Identification Number (ID): " << client.m_identificationNumber << std::endl;
    out << "Birthday: " << client.m_birthDay << std::endl;
    out << "Money: " << client.m_money << std::endl;
    
    return out;
}
