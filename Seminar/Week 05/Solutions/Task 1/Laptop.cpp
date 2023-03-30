#include <cstring>
#include "Laptop.hpp"

Laptop::Laptop(): cpu(CPU()), price(0), screenSize(0), brandName(new char[1]), model(new char[1]), ram(0), battery(0){

    this -> brandName[0] = '\0';
    this -> model[0] = '\0';

}

Laptop::Laptop(CPU const &cpu, unsigned const &ram, double const &price, double const &screenSize, char const * const &brandName, char const * const &model, unsigned const &battery):
    cpu(cpu), price(price), screenSize(screenSize), ram(ram), battery(battery), brandName(new char[strlen(brandName) + 1]), model(new char[strlen(model) + 1]){

    strcpy(this -> brandName, brandName);
    strcpy(this -> model, model);

}

Laptop::Laptop(Laptop const &other){
    copyFrom(other);
}

Laptop::~Laptop(){
    free();
}

Laptop &Laptop::operator =(Laptop const &other){

    if(this != &other){
        
        free();
        copyFrom(other);

    }

    return *this;

}

void Laptop::upgradeCPU(CPU const &cpu){ this -> cpu = cpu; }
void Laptop::upgradeRAM(unsigned const &ram){ this -> ram = ram; }

void Laptop::print() const{

    cout << "Brand: " << brandName << '\n'
        << "Model: " << model << '\n'
        << "CPU: ";
    cpu.print();
    cout << "\nRAM: " << ram << '\n'
        << "Battery: " << battery << '\n'
        << "Screen size: " << screenSize << '\n'
        << "Price: " << price << '\n';

}

void Laptop::copyFrom(Laptop const &other){

    this -> cpu = other.cpu;
    this -> price = other.price;
    this -> screenSize = other.screenSize;
    this -> ram = other.ram;
    this -> battery = other.battery;
    this -> brandName = new char[strlen(other.brandName) + 1];
    strcpy(this -> brandName, other.brandName);
    this -> model = new char[strlen(other.model) + 1];
    strcpy(this -> model, other.model);
    
}

void Laptop::free(){

    delete[] brandName;
    delete[] model;

}