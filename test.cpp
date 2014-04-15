#include <has_intersection.h>
#include <gtest/gtest.h>
#include <boost/math/constants/constants.hpp>

const double rad = 200;

const double m_pi = boost::math::constants::pi<double>();
/*const double ClEquator = PI/2;
const double Grinvich = 0.0;

const double EightOffset = M_PI/4;
const double QuaterOffset = M_PI/2;
const double HalfOffset = M_PI;

const double M45 = PI/4;
const double M120 = PI/4;

const Point3d N = getDecart(0.0, Grinvich, kRadius); // @Grinvich
const Point3d S = getDecart(PI, Grinvich, kRadius); // @Grinvich*/


// space->addLine(Vector2D(-M_PI / 4, 2), Vector2D(M_PI / 4, 2));
 //space->addLine(Vector2D(-3*M_PI / 4, 1), Vector2D(2*M_PI / 4, 1));

TEST(is_intersects, different_hemisphere)
{
    Point<double> p1 = get_euclide_coords(rad,2,-m_pi/4);
    Point<double> p2 = get_euclide_coords(rad,2,m_pi/4);
    Point<double> p3 = get_euclide_coords(rad,1,-3*m_pi/4);
    Point<double> p4 = get_euclide_coords(rad,1,3*m_pi/4);
    Segment seg1 = Segment(&p1,&p2);
    Segment seg2 = Segment(&p3,&p4);
    EXPECT_TRUE(is_intersects(seg1,seg2));

 /*  Segment3D<double> s[] =
   {
      Segment3D<double>(getDecart(0.0,0.0,kRadius), getDecart(PI/2, PI/2, kRadius)),
      Segment3D<double>(getDecart(PI / 3, 0.0, kRadius), getDecart(PI / 3, PI / 2+0.1, kRadius)),
      Segment3D<double>(getDecart(2*PI / 3, 0.0, kRadius), getDecart(2*PI / 3, PI / 2+0.1,kRadius)),

      Segment3D<double>(N, S), // гринвичский мередиан
      Segment3d(getDecart(M45, Grinvich + EightOffset, kRadius),getDecart(M45, Grinvich+ QuaterOffset, kRadius)), // сбоку от гринвича
      Segment3d(getDecart(M120, Grinvich - EightOffset, kRadius),getDecart(M120, Grinvich + EightOffset, kRadius)),  // через гринвич

      Segment3d(getDecart(M45, Grinvich - EightOffset, kRadius),getDecart(M120, Grinvich+ QuaterOffset, kRadius)), // LR
      Segment3d(getDecart(M45, Grinvich + EightOffset, kRadius),getDecart(M120, Grinvich - EightOffset, kRadius)),  // RL
      Segment3d(getDecart(M45, Grinvich + EightOffset+PI, kRadius),getDecart(M120, Grinvich - EightOffset+PI, kRadius)),  // RL с другой стороны
      Segment3d(getDecart(M120, Grinvich + EightOffset+PI, kRadius),getDecart(M45, Grinvich - EightOffset+PI, kRadius)),  // LR с другой стороны

       Segment3d(N, getDecart(M45, 0.0, kRadius)),
       Segment3d(getDecart(M120, 0.0, kRadius), S)
   };



   EXPECT_TRUE(s(s[0], s[1]));
   EXPECT_TRUE(has_intersection(s[1], s[0]));
   EXPECT_FALSE(has_intersection(s[0], s[2]));
   EXPECT_FALSE(has_intersection(s[1], s[2]));


   EXPECT_FALSE(has_intersection(s[3], s[4]));
   EXPECT_TRUE(has_intersection(s[3], s[5]));

   EXPECT_TRUE(has_intersection(s[6], s[7]));
   EXPECT_TRUE(has_intersection(s[7], s[6]));

   EXPECT_TRUE(has_intersection(s[6], s[3]));
   EXPECT_TRUE(has_intersection(s[7], s[3]));

   EXPECT_FALSE(has_intersection(s[8], s[7]));
   EXPECT_FALSE(has_intersection(s[8], s[6]));
   EXPECT_FALSE(has_intersection(s[8], s[0]));

    //EXPECT_FALSE(has_intersection(s[7], s[9])); // случай с тетраэдром
    //EXPECT_FALSE(has_intersection(s[10], s[11]));*/
}

TEST(is_intersects, equator_true)
{}

TEST(is_intersects, equator_false)
{}

TEST(is_intersects, common_true)
{}

TEST(is_intersects, common_false)
{}





