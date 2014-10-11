#pragma once

#include <gmpxx.h>
#include <gmp.h>
#include <boost/numeric/interval.hpp>
#include <boost/math/constants/constants.hpp>

using namespace boost::numeric;
//using namespace interval_lib;

typedef interval<double> I;
typedef mpq_class R;
typedef double D;

const double m_pi = boost::math::constants::pi<double>();

enum turn_t {
    t_left = 1,
    t_right = -1,
    collinear = 0
};