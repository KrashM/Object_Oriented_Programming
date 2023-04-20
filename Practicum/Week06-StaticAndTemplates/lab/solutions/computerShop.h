#pragma once

#include "computer.h"
#include "list.h"
#include <string>

using filterFunction = bool (*) (const Computer& computer);

class ComputerShop
{
private:
    std::string name;
    List<Computer> computers;

    ComputerShop(const std::string& name);

public:
    ComputerShop& operator = (const ComputerShop& other) = delete;
    ComputerShop(const ComputerShop& other) = delete;

    static ComputerShop& getInstance(const std::string& name);

    void addComputer(const Computer& computer);
    void print() const;
    void buyComputer(const std::string& brand, double customerMoney);

    List<Computer> filter(filterFunction func) const;
};