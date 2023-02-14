#pragma once

class CPU{

    private:
        double HZ;
        int CORES, CACHE;

    public:
        CPU(){}
        CPU(double HZ, int CORES, int CACHE);

        const CPU &operator =(const CPU &other);

        const bool operator ==(const CPU &other);
        const bool operator !=(const CPU &other);

        const char *toString() const;

};