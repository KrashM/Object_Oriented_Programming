#pragma once

enum class Currency {
    BGN,
    USD,
    EUR
};

const char* currencyToString(Currency currency) {
    switch (currency) {
    case Currency::BGN:
        return "BGN";
    case Currency::EUR:
        return "EUR";
    case Currency::USD:
        return "USD";
    default:
        return "";
    }
}
