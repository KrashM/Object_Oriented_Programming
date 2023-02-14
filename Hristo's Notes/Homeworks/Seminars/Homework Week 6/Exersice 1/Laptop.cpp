#include "Laptop.h"
#include "../../../Converter.h"
#include <cstring>

Laptop::Laptop(){

    this -> cpu = CPU(0, 0, 0);
    this -> price = 0;
    this -> screenSize = 0;
    this -> brandName = new char[1];
    this -> brandName[0] = '\0';
    this -> model = new char[0];
    this -> model[0] = '\0';
    this -> ram = 0;
    this -> battery = 0;

}

Laptop::Laptop(const CPU cpu, const unsigned ram, const double price, const double screenSize, const char *brandName, const char *model, const unsigned battery){

    this -> cpu = cpu;
    this -> price = price;
    this -> screenSize = screenSize;
    this -> ram = ram;
    this -> battery = battery;
    this -> brandName = new char[strlen(brandName)];
    strcpy(this -> brandName, brandName);
    this -> model = new char[strlen(model)];
    strcpy(this -> model, model);

}

Laptop::Laptop(const Laptop &other){

    this -> cpu = other.cpu;
    this -> price = other.price;
    this -> screenSize = other.screenSize;
    this -> ram = other.ram;
    this -> battery = other.battery;
    this -> brandName = new char[strlen(other.brandName)];
    strcpy(this -> brandName, other.brandName);
    this -> model = new char[strlen(other.model)];
    strcpy(this -> model, other.model);

}

Laptop::~Laptop(){

    delete[] this -> brandName;
    delete[] this -> model;

}

const Laptop& Laptop::operator =(const Laptop &other){

    if(this != &other){
        
        this -> cpu = other.cpu;
        this -> price = other.price;
        this -> screenSize = other.screenSize;
        this -> ram = other.ram;
        this -> battery = other.battery;
        this -> brandName = new char[strlen(other.brandName)];
        strcpy(this -> brandName, other.brandName);
        this -> model = new char[strlen(other.model)];
        strcpy(this -> model, other.model);

    }

    return *this;

}

const bool Laptop::operator ==(const Laptop &other){ return this -> screenSize == other.screenSize; }
const bool Laptop::operator !=(const Laptop &other){ return this -> screenSize != other.screenSize; }
const bool Laptop::operator >(const Laptop &other){ return this -> screenSize > other.screenSize; }
const bool Laptop::operator <(const Laptop &other){ return this -> screenSize < other.screenSize; }

void Laptop::upgradeCPU(const CPU &cpu){ this -> cpu = cpu; }
void Laptop::upgradeRAM(const unsigned ram){ this -> ram = ram; }

const char *Laptop::toString() const{

    char *result = new char[1024];
    result[0] = '\0';

    strcat(result, "Brand: ");
    strcat(result, this -> brandName);
    strcat(result, "\n");

    strcat(result, "Model: ");
    strcat(result, this -> model);
    strcat(result, "\n");

    strcat(result, "CPU: ");
    strcat(result, this -> cpu.toString());
    strcat(result, "\n");

    strcat(result, "RAM: ");
    strcat(result, Converter::intToString(this -> ram));
    strcat(result, "\n");

    strcat(result, "Battery: ");
    strcat(result, Converter::intToString(this -> battery));
    strcat(result, "\n");

    strcat(result, "Screen size: ");
    strcat(result, Converter::doubleToString(this -> screenSize));
    strcat(result, "\n");

    strcat(result, "Price: ");
    strcat(result, Converter::doubleToString(this -> price));

    return result;

}