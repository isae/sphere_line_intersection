#ifndef HAS_INTERSECTION_H
#define HAS_INTERSECTION_H

template<class T> class Point {
public:
    T x;
    T y;
    T z;
};

template<class T>
Point<T>::Point(T x, T y, T z);
Point<T>::~Point();

class Segment{

public:
  //  Segment(Point<double>* left, Point<double>* right);
    Point<double>* left;
    Point<double>* right;
   // ~Segment();
};

Segment::Segment(Point<double> * left,Point<double> * right);
Segment::~Segment();

bool is_intersects(Segment seg1,Segment seg2);
Point<double> get_euclide_coords(double r, double polar_angle, double azimuth);

#endif // HAS_INTERSECTION_H
