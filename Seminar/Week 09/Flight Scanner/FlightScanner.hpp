#pragma once

#include <fstream>
#include <cstdint>

class FlightScanner{
    
public:
    FlightScanner(char const * const, char const * const, int const);
    void run();

private:
    struct FlightRecord{

        char origin[64];
        char dest[64];
        uint32_t amount;

    };

    void handleAirport(char *) const;
    void parseLine(char const * const, FlightRecord &) const;
    bool readAndExportData(std::ifstream &);
    void saveRecord(std::ofstream &, const FlightRecord &) const;

    char inputFileName[1024] = "";
    char outputFileName[1024] = "";
    uint32_t lineIndex = 0;
    int sec = -1;

};