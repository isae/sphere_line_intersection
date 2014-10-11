#pragma once

#include "common.h"

template<class T>
struct Point {
    Point(T x, T y, T z);

    ~Point() = default;
    T x;
    T y;
    T z;

    operator Point<I>() const {
        return Point<I>(I(x), I(y), I(z));
    }

    operator Point<R>() const {
        return Point<R>(R(x), R(y), R(z));
    }


    Point<T> operator-(const Point<T>& o) {
        return Point<T>(x - o.x, y - o.y, z - o.z);
    }
};
