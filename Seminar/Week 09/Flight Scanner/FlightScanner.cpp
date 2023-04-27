#include "FlightScanner.hpp"
#include "Utils.hpp"
#include <exception>
#include <iostream>
#include <cstring>
#include <sstream>
#include <chrono>
#include <thread>

FlightScanner::FlightScanner(char const * const input, char const * const output, int const scanInterval){

    if(!input) throw std::invalid_argument("Input file name is not a string");
    if(!output) throw std::invalid_argument("Output file name is not a string");
    if(scanInterval & 1 << 31) throw std::invalid_argument("Sleep interval should not be negative");

    strcpy(inputFileName, input);
    strcpy(outputFileName, output);
    sec = scanInterval;

}

void FlightScanner::run(){

    while(true){

        std::cout << "Scanning for file...\n";

        std::ifstream ifs(inputFileName);

        if(ifs.fail()) std::cout << "Input file not found! Sleeping...\n";
        else{

            if(readAndExportData(ifs)) std::cout << "Success!\n";
            else std::cout << "Error occured while exporting\n";

            ifs.close();
            remove(inputFileName);

        }

        std::this_thread::sleep_for(std::chrono::seconds(sec));

    }

}

void FlightScanner::handleAirport(char *airport) const{

    if(strlen(airport) != 3) throw std::length_error("Airport string should be 3 characters long\n");
    toUpper(airport);

}

void FlightScanner::parseLine(char const * const line, FlightRecord &record) const{

    std::stringstream stream(line);

    stream >> record.origin;
    try{ handleAirport(record.origin); }
    catch(std::exception const &ex){

        std::cerr << "Exception occured when parsing the origin\n";
        throw;

    }

    stream >> record.dest;
    try{ handleAirport(record.dest); }
    catch(std::exception const &ex){

        std::cerr << "Exception occured when parsing the destination\n";
        throw;

    }

    char amount[64];
    stream >> amount;

    try{ record.amount = convertToNumber(amount); }
    catch(std::exception const &ex){

        std::cerr << "Exception occured when casting the amount\n";
        throw;

    }

}

bool FlightScanner::readAndExportData(std::ifstream &ifs){

    std::ofstream ofs(outputFileName, std::ios::app);

    if(!ofs.is_open()){

        std::cout << "Couldn't open the output file\n";
        return false;

    }

    char line[30];
    FlightRecord record;
    uint32_t lineIndex = 1;
    bool errorOccured = false;

    while(!ifs.eof()){

        ifs.getline(line, 30);

        try{

            parseLine(line, record);
            saveRecord(ofs, record);

        }
        catch(std::invalid_argument const &ex){
            
            std::cerr << "Error occured on line: " << lineIndex << ": Message: " << ex.what() << '\n';
            errorOccured = true;
            
        }
        catch(std::length_error const &ex){
            
            std::cerr << "Error occured on line: " << lineIndex << ": Message: " << ex.what() << '\n';
            errorOccured = true;
            
        }
        catch(std::bad_cast const &ex){
            
            std::cerr << "Error occured on line: " << lineIndex << ": Message: " << ex.what() << '\n';
            errorOccured = true;
            
        }
        catch(std::exception const &ex){
            
            std::cerr << "Error occured on line: " << lineIndex << ": Message: " << ex.what() << '\n';
            errorOccured = true;
            
        }
        catch(...){
            
            std::cerr << "Exception occured on line: " << lineIndex << '\n';
            errorOccured = true;
            
        }

        lineIndex++;

    }

    return errorOccured;

}

void FlightScanner::saveRecord(std::ofstream &ofs, const FlightRecord &record) const{
	
	static double const CONV_RATE = 1.98;
    ofs << record.origin << ' ' << record.dest << ' ' << record.amount * CONV_RATE << '\n';

}
