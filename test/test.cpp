#include <gtest/gtest.h>
#include <boost/math/constants/constants.hpp>
#include "has_intersection.h"

const double rad = 200;

TEST(has_intersection, different_hemisphere)
{
    Point<double> p1 = get_euclide_coords(rad,2,-m_pi/4);
    Point<double> p2 = get_euclide_coords(rad,2,m_pi/4);
    Point<double> p3 = get_euclide_coords(rad,1,-3*m_pi/4);
    Point<double> p4 = get_euclide_coords(rad,1,3*m_pi/4);
    Segment seg1 = Segment(p1,p2);
    Segment seg2 = Segment(p3,p4);
    ASSERT_FALSE(has_intersection(seg1, seg2));
}

TEST(has_intersection, equator_cross_true)
{
    Point<double> p1 = get_euclide_coords(rad,m_pi/2,0);
    Point<double> p2 = get_euclide_coords(rad,m_pi/2,m_pi/2);
    Point<double> p3 = get_euclide_coords(rad,m_pi/2,m_pi/4);
    Point<double> p4 = get_euclide_coords(rad,m_pi/2,3*m_pi/4);
    Segment seg1 = Segment(p1,p2);
    Segment seg2 = Segment(p3,p4);
    ASSERT_TRUE(has_intersection(seg1, seg2));
}

TEST(has_intersection, equator_cross_false)
{
    Point<double> p1 = get_euclide_coords(rad,m_pi/2,0);
    Point<double> p2 = get_euclide_coords(rad,m_pi/2,m_pi/2);
    Point<double> p3 = get_euclide_coords(rad,m_pi/2,m_pi);
    Point<double> p4 = get_euclide_coords(rad,m_pi/2,3*m_pi/2);
    Segment seg1 = Segment(p1,p2);
    Segment seg2 = Segment(p3,p4);
    ASSERT_FALSE(has_intersection(seg1, seg2));
}

TEST(has_intersection, common_false_1)
{
    Point<double> p1 = get_euclide_coords(rad,m_pi/2,0);
    Point<double> p2 = get_euclide_coords(rad,m_pi/2,m_pi/2);
    Point<double> p3 = get_euclide_coords(rad,m_pi/4,m_pi/4);
    Point<double> p4 = get_euclide_coords(rad,-m_pi/4,m_pi/4);
    Segment seg1 = Segment(p1,p2);
    Segment seg2 = Segment(p3,p4);
    ASSERT_FALSE(has_intersection(seg1, seg2));
}

TEST(has_intersection, common_true_1)
{
    Point<double> p1 = get_euclide_coords(rad,m_pi/2,0);
    Point<double> p2 = get_euclide_coords(rad,m_pi/2,m_pi/2);
    Point<double> p3 = get_euclide_coords(rad,m_pi/4,m_pi/4);
    Point<double> p4 = get_euclide_coords(rad,3*m_pi/4,m_pi/4);
    Segment seg1 = Segment(p1,p2);
    Segment seg2 = Segment(p3,p4);
    ASSERT_TRUE(has_intersection(seg1, seg2));
}

TEST(has_intersection, common_touch_true_1)
{
    Point<double> p1 = get_euclide_coords(rad,m_pi/2,0);
    Point<double> p2 = get_euclide_coords(rad,m_pi/2,m_pi/2);
    Point<double> p3 = get_euclide_coords(rad,m_pi/4,m_pi/4);
    Point<double> p4 = get_euclide_coords(rad,m_pi/2,m_pi/4);
    Segment seg1 = Segment(p1,p2);
    Segment seg2 = Segment(p3,p4);
    ASSERT_TRUE(has_intersection(seg1, seg2));
}





