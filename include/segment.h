#pragma once
#include "point.h"
struct Segment
{
    Segment(Point<double> &left, Point<double> &right) : left(left), right(right) {}

    Point<double> left;
    Point<double> right;
};
