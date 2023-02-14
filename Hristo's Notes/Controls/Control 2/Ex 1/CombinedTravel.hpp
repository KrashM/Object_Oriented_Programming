#pragma once

#include "CarTravel.hpp"
#include "AirTravel.hpp"

class CombinedTravel: public CarTravel, AirTravel{

    public:
        CombinedTravel();
        CombinedTravel(const CarTravel *&, const AirTravel *&, const char **, const size_t, const size_t);
        CombinedTravel(const CombinedTravel &);
        ~CombinedTravel();
        CombinedTravel &operator=(const CombinedTravel &);

        size_t getDuration() const;
        void print() const override;

    private:
        CarTravel *travelWithCar;
        AirTravel *travelWithAir;
        char **destinations;
        size_t numberOfDestinations, freeTime;

        void free();
        void copy(const CombinedTravel &);

};