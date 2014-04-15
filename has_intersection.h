#pragma once

template<class T>
struct Point {
    Point(T x, T y, T z);
//    ~Point();
    T x;
    T y;
    T z;
};

struct Segment{
    Segment(Point<double> * left,Point<double> * right);
    ~Segment();
    Point<double>* left;
    Point<double>* right;
};



bool is_intersects(Segment seg1,Segment seg2);
Point<double> get_euclide_coords(double r, double polar_angle, double azimuth);
