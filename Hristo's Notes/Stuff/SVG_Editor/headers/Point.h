#pragma once

struct point{

    point();
    point(double, double);
    point(const point &);

    double getDist(const point &) const;

    double x;
    double y;

};