#pragma once

class CarTravel{

    public:
        CarTravel();
        CarTravel(const size_t *, const size_t, const size_t);
        CarTravel(const CarTravel &);
        CarTravel &operator =(const CarTravel &);

        CarTravel *clone() const;
        size_t getTravelTime() const;
        virtual void print() const;

    protected:
        size_t *regNumber, distance, travelTime;

    private:
        void copy(const CarTravel &);

};