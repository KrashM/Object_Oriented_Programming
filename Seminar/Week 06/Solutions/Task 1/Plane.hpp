#include "Nvector.hpp"

class Plane{

    public:
        Plane() = delete;
        Plane(Nvector const &, Nvector const &);
        Plane(Plane const &);
        ~Plane() = default;

        Plane &operator =(Plane const &);

        Nvector getVectorByCoordinates(int, int) const;
        Nvector getCoordinatesByVector(Nvector const &) const;
    
    private:
        Nvector v1, v2;

};