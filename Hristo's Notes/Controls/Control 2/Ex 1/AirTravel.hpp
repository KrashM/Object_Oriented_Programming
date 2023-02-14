#pragma once

class AirTravel{

    public:
        AirTravel();
        AirTravel(const char *, const size_t);
        AirTravel(const AirTravel &);
        ~AirTravel();
        AirTravel &operator =(const AirTravel &);

        AirTravel *clone() const;
        size_t getTravelTime() const;
        virtual void print() const;

    protected:
        char *travelNumber;
        size_t flightTime;

    private:
        void free();
        void copy(const AirTravel &);

};