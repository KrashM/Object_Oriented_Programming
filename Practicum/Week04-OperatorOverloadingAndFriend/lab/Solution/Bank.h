#pragma once

#include "Client.h"

constexpr std::size_t CONVERTION_RATES_SIZE{ 6 };
constexpr std::size_t INITIAL_CLIENTS_CAPACITY{ 4 };
constexpr std::size_t CLIENTS_CAPACITY_MULTIPLIER{ 2 };

class Bank {
public:
    Bank(const char* name, const ConvertionRate convertionRates[CONVERTION_RATES_SIZE]);
    Bank(const Bank& other);
    ~Bank();

    void addClient(const Client& client);

    int getClientIndex(const char* identificationNumber) const;

    bool deposit(const char* identificationNumber, const Money& toDeposit);
    bool withdraw(const char* identificationNumber, const Money& toWithdraw);
    bool transfer(const char* sourceClientIdentificationNumber, const char* destinationClientIdentifinationNumber, Money moneyToTransfer);
    bool convertClientMoney(const char* identificationNumber, Currency newCurrency);

    Client& operator[](std::size_t index);
    const Client& operator[](std::size_t index) const;
    Client& operator[](const char* identificationNumber);
    const Client& operator[](const char* identificationNumber) const;

    Bank& operator=(const Bank& other);

    friend std::ostream& operator<<(std::ostream& out, const Bank& bank);

private:
    void allocateClientsMemory(std::size_t newCapacity);

    void copyDataFrom(const Bank& other);
    
    void deleteClients();
    void deleteData();

    void setName(const char* name);
    void setConvertionRates(const ConvertionRate convertionRates[CONVERTION_RATES_SIZE]);

    ConvertionRate& findConvertionRate(Currency oldCurrency, Currency newCurrency) const;

private:
    char* m_name{ nullptr };
    
    Client** m_clients{ nullptr };
    std::size_t nClientsSize{ 0 };
    std::size_t nClientsCapacity{ 0 };

    ConvertionRate m_convertionRates[CONVERTION_RATES_SIZE];
};
