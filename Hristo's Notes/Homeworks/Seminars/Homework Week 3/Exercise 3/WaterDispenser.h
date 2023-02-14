#ifndef WATER_DISPENSER
#define WATER_DISPENSER

class WaterDispenser{

    private:
        double liters, maxLiters;

    public:
        WaterDispenser(double liters, double maxLiters);
        WaterDispenser(double maxLiters);
        bool dispence(double liters);
        void refill(double liters);
        double getLiters();
        
};

#endif