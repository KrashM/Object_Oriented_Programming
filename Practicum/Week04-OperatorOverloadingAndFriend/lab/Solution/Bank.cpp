#include "Bank.h"

#include <iostream>s
#include <cstring>
#include <cassert>

Bank::Bank(const char* name, const ConvertionRate convertionRates[CONVERTION_RATES_SIZE]) {
    allocateClientsMemory(INITIAL_CLIENTS_CAPACITY);

    setName(name);
    setConvertionRates(convertionRates);
}

Bank::Bank(const Bank& other) {
    copyDataFrom(other);
}

Bank::~Bank() {
    deleteData();
}

void Bank::addClient(const Client& client) {
    if (nClientsSize >= nClientsCapacity) allocateClientsMemory(nClientsCapacity * CLIENTS_CAPACITY_MULTIPLIER);

    m_clients[nClientsSize++] = new Client(client);
}

int Bank::getClientIndex(const char* identificationNumber) const {
    for (std::size_t index{ 0 }; index < nClientsSize; ++index) {
        if (strcmp(m_clients[index]->getIdentificationNumber(), identificationNumber) == 0) {
            return index;
        }
    }
    
    return -1;
}

bool Bank::deposit(const char* identificationNumber, const Money& toDeposit) {
    int clientIndex{ getClientIndex(identificationNumber) };

    if (clientIndex == -1) {
        return false;
    }

    return m_clients[clientIndex]->deposit(toDeposit);
}

bool Bank::withdraw(const char* identificationNumber, const Money& toWithdraw) {
    int clientIndex{ getClientIndex(identificationNumber) };

    if (clientIndex == -1) {
        return false;
    }

    return m_clients[clientIndex]->withdraw(toWithdraw);
}

bool Bank::transfer(const char* sourceClientIdentificationNumber, const char* destinationClientIdentifinationNumber, Money moneyToTransfer) {
    int sourceIndex{ getClientIndex(sourceClientIdentificationNumber) };

    if (sourceIndex == -1) {
        return false;
    }

    int destinationIndex{ getClientIndex(destinationClientIdentifinationNumber) };

    if (destinationIndex == -1) {
        return false;
    }

    Client* source{ m_clients[sourceIndex] };
    Client* destination{ m_clients[destinationIndex] };

    if (moneyToTransfer.currency() != source->getMoney().currency()) {
        moneyToTransfer.hardConvert(findConvertionRate(moneyToTransfer.currency(), source->getMoney().currency()));
    }

    if (source->getMoney() < moneyToTransfer) {
        return false;
    }

    source->withdraw(moneyToTransfer);

    if (moneyToTransfer.currency() != destination->getMoney().currency()) {
        moneyToTransfer.hardConvert(findConvertionRate(moneyToTransfer.currency(), destination->getMoney().currency()));
    }

    destination->deposit(moneyToTransfer);
    
    return true;
}

bool Bank::convertClientMoney(const char* identificationNumber, Currency newCurrency) {
    int clientIndex{ getClientIndex(identificationNumber) };

    if (clientIndex != -1) {
        return false;
    }

    m_clients[clientIndex]->convert(findConvertionRate(m_clients[clientIndex]->getMoney().currency(), newCurrency));
    
    return true;
}

Client& Bank::operator[](std::size_t index) {
    assert(index < nClientsSize);

    return *m_clients[index];
}

const Client& Bank::operator[](std::size_t index) const {
    assert(index < nClientsSize);

    return *m_clients[index];
}

Client& Bank::operator[](const char* identificationNumber) {
    int index{ getClientIndex(identificationNumber) };
    
    assert(index >= 0 && index < nClientsSize);

    return *m_clients[index];
}

const Client& Bank::operator[](const char* identificationNumber) const {
    int index{ getClientIndex(identificationNumber) };
    
    assert(index >= 0 && index < nClientsSize);

    return *m_clients[index];
}

Bank& Bank::operator=(const Bank& other) {
    if (this != &other) {
        deleteData();
        copyDataFrom(other);
    }
    
    return *this;
}

void Bank::allocateClientsMemory(std::size_t newCapacity) {
    if (newCapacity <= nClientsCapacity) newCapacity = nClientsCapacity + 1;

    Client** blockOfMem = new Client*[newCapacity];

    for (std::size_t index{ 0 }; index < nClientsSize; ++index) {
        blockOfMem[index] = new Client(*m_clients[index]);
    }

    deleteClients();

    m_clients = blockOfMem;
    nClientsCapacity = newCapacity;
}

void Bank::copyDataFrom(const Bank& other) {
    setConvertionRates(other.m_convertionRates);
    setName(other.m_name);

    m_clients = new (std::nothrow) Client*[other.nClientsCapacity];

    for (std::size_t index{ 0 }; index < other.nClientsSize; ++index) {
        m_clients[index] = new (std::nothrow) Client(*other.m_clients[index]);
    }

    nClientsCapacity = other.nClientsCapacity;
    nClientsSize = other.nClientsSize;
}

void Bank::deleteClients() {
    for (std::size_t index{ 0 }; index < nClientsSize; ++index) {
        delete m_clients[index];
        m_clients[index] = nullptr;
    }

    delete[] m_clients;
    m_clients = nullptr;
}

void Bank::deleteData()
{
    delete[] m_name;
    m_name = nullptr;

    deleteClients();
}

void Bank::setName(const char* name) {
    delete[] m_name;

    m_name = new (std::nothrow) char[strlen(name) + 1];

    if (!m_name) {
        std::cout << "Memory problem!" << std::endl;

        assert(false);
    }

    strcpy(m_name, name);
}

void Bank::setConvertionRates(const ConvertionRate convertionRates[CONVERTION_RATES_SIZE]) {
    for (std::size_t index{ 0 }; index < CONVERTION_RATES_SIZE; ++index) {
        m_convertionRates[index] = convertionRates[index];
    }
}

std::ostream& operator<<(std::ostream& out, const Bank& bank) {
    out << "Bank:" << std::endl;
    out << "Name: " << bank.m_name << std::endl;

    for (std::size_t index{ 0 }; index < bank.nClientsSize; ++index) {
        out << *bank.m_clients[index] << std::endl;
    }

    out << "Convertion Rates:" << std::endl;

    for (std::size_t index{ 0 }; index < CONVERTION_RATES_SIZE; ++index) {
        out << currencyToString(bank.m_convertionRates[index].m_oldCurrency) << " -> " << currencyToString(bank.m_convertionRates[index].m_newCurrency) << " = " << bank.m_convertionRates[index].m_excangeRate << std::endl;
    }
    
    return out;
}
