#ifndef POINT
#define POINT

class Point{

    private:
        int x, y;
    
    public:
        Point();
        Point(int x, int y);
        
        int getX();
        int getY();

        static double distance(const Point &a, const Point &b);

};

#endif