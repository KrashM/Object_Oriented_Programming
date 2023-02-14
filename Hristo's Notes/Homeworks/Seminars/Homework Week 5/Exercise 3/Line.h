#ifndef LINE
#define LINE
#include "Point.h"

class Line{

    private:
        Point a, b;
    
    public:
        Line();
        Line(const Point &a, const Point &b);

        double getLength();

};

#endif