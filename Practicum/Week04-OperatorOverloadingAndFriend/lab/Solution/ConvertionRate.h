#pragma once

#include "Currency.h"

struct ConvertionRate {
public:
    double m_excangeRate{ 0 };
    Currency m_oldCurrency;
    Currency m_newCurrency;
};

