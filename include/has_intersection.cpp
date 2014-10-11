#include <iostream>

#include "has_intersection.h"
#include "common.h"

using namespace std;

template<class T>
Point<T>::Point(T x, T y, T z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

/*in radians*/
Point<double> get_euclide_coords(double r, double polar_angle, double azimuth) {
    return Point<double>(
            r * sin(polar_angle) * cos(azimuth),
            r * sin(polar_angle) * sin(azimuth),
            r * cos(polar_angle));
}

template<class T>
T triple_product(Point<T> a, Point<T> b, Point<T> c) {
    return a.x * (b.y * c.z - b.z * c.y) - a.y * (b.x * c.z - b.z * c.x) + a.z * (b.x * c.y - b.y * c.x);
}

template<class T>
T newdet(Point<double> a, Point<double> b, Point<double> c) {
    Point<T> ai = Point<T>(a);
    Point<T> bi = Point<T>(b);
    Point<T> ci = Point<T>(c);

    return triple_product(ai, bi, ci);
};

template<class T>
turn_t left_turn(Point<T> const &a, Point<T> const &b, Point<T> const &c) {
    double A = b.y * c.z - b.z * c.y;
    double B = b.x * c.z - b.z * c.x;
    double C = b.x * c.y - b.y * c.x;

    double e = (abs(A * a.x) + abs(B * a.y) + abs(C * a.z)) * numeric_limits<double>::epsilon() * 8;

    double det = A * a.x - B * a.y + C * a.z;

    if (det > e)
        return t_left;
    if (det < -e)
        return t_right;


    I idet = newdet<I>(a, b, c);

    if (!zero_in(idet)) {
        if (idet > 0)
            return t_left;

        return t_right;
    }

    R rdet = newdet<R>(a, b, c);

    if (rdet > 0)
        return t_left;
    if (rdet < 0)
        return t_right;

    return collinear;
}

bool on_equator(Segment seg1, Segment seg2) {
    Point<double> a = seg1.left;
    Point<double> b = seg1.right;
    Point<double> c = seg2.left;
    Point<double> d = seg2.right;


    //  double A = b.y * c.z - b.z * c.y;
    // double B = b.z * c.x - b.x * c.z;
    //   double C = b.x * c.y - b.y * c.x;
    //Ax+By+Cz = 0 - plane equation for b, c, (0,0,0)
    //  double aSubst = A*a.x+B*a.y+C*a.z;
    //  double dSubst = A*d.x+B*d.y+C*d.z;
    return left_turn(a, b, c) == collinear && left_turn(a, b, d) == collinear;
}

bool in_same_hemisphere(Segment seg1, Segment seg2) {
    Point<double> a = seg1.left;
    Point<double> b = seg1.right;
    Point<double> c = seg2.left;
    Point<double> d = seg2.right;
    //lets check that left turn of zero and fourth vertex of tetraedr relatively to each edge are equal
    turn_t t1 = left_turn(a - d, b - d, c - d);
    turn_t t2 = left_turn(a, b, c);


    turn_t t3 = left_turn(d - a, b - a, c - a);
    turn_t t4 = left_turn(d, b, c);


    turn_t t5 = left_turn(a - b, d - b, c - b);
    turn_t t6 = left_turn(a, d, c);


    turn_t t7 = left_turn(a - c, b - c, d - c);
    turn_t t8 = left_turn(a, b, d);

    if (t1 != t2 || t3 != t4 || t5 != t6 || t7 != t8) {
        return true;
    }
    return false;
}

/*checks if [a,b] intersects [c,d] on the sphere*/
bool has_intersection(Segment seg1, Segment seg2) {
    Point<double> a = seg1.left;
    Point<double> b = seg1.right;
    Point<double> c = seg2.left;
    Point<double> d = seg2.right;

    if (on_equator(seg1, seg2)) {

        Point<double> n = Point<double>(
                a.y * b.z - a.z * b.y,
                a.z * b.x - a.x * b.z,
                a.x * b.y - a.y * b.x);

        Point<double> ab = Point<double>(a.x - b.x, a.y - b.y, a.z - b.z);
        Point<double> ca = Point<double>(c.x - a.x, c.y - a.y, c.z - a.z);
        Point<double> da = Point<double>(d.x - a.x, d.y - a.y, d.z - a.z);


        turn_t l = left_turn(n, ab, ca);
        turn_t r = left_turn(n, ab, da);
        if (l >= collinear || r >= collinear) return true;
        return false;

    }

    if (!in_same_hemisphere(seg1, seg2)) {
        return false;
    }


    turn_t l = left_turn(a, b, c);
    turn_t r = left_turn(a, b, d);
    turn_t l2 = left_turn(c, d, a);
    turn_t r2 = left_turn(c, d, b);

    return abs(l + r) < 2 && abs(l2 + r2) < 2;
}
