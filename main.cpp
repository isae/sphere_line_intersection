#include <iostream>
#include <gmpxx.h>
#include <gmp.h>
#include <boost/numeric/interval.hpp>
#include <boost/math/constants/constants.hpp>
#include <has_intersection.h>
#include <gtest/gtest.h>
#include <QApplication>

using namespace std;
using namespace boost::numeric;
using namespace interval_lib;

typedef interval<double> I;
typedef mpq_class R;
typedef double D;

const double m_pi = boost::math::constants::pi<double>();

enum turn_t {
    t_left = 1,
    t_right = -1,
    collinear = 0
};

template<class T>
Point<T>::Point(T x, T y, T z){
    this->x = x;
    this->y = y;
    this->z = z;
}

Segment::Segment(Point<double>* left, Point<double>* right){
    this->left = left;
    this->right = right;
}

Segment::~Segment(){
}

//Visual::Visual()
//{
//    setLineSegments(20);
//    setSpaceSegments(35);
//}

//Visual::~Visual(){
//}

/*in radians*/
Point<double> get_euclide_coords(double r, double polar_angle, double azimuth){
    return Point<double>(
                r*sin(polar_angle)*cos(azimuth),
                r*sin(polar_angle)*sin(azimuth),
                r*cos(polar_angle));
}

I in(D doub){
    return I(doub);
}

R rat(D doub){
    return R(doub);
}

template<class T> T triple_product(Point<T> a, Point<T> b, Point<T> c){
    return a.x*(b.y*c.z - b.z*c.y) - a.y*(b.x*c.z - b.z*c.x) + a.z*(b.x*c.y - b.y*c.x);
}

turn_t left_turn(double ax, double ay, double az,
                 double bx, double by, double bz,
                 double cx, double cy, double cz){
    double A = by*cz - bz*cy;
    double B = bx*cz - bz*cx;
    double C = bx*cy - by*cx;

    //magic constant!!
    double e = (abs(A*ax) + abs(B*ay)+abs(C*az)) * numeric_limits<double>::epsilon() * 18;

    double det = A*ax -B*ay+C*az;

    if (det > e)
        return t_left;
    if (det < -e)
        return t_right;

    Point<I> ai = Point<I>(in(ax),in(ay),in(az));
    Point<I> bi = Point<I>(in(bx),in(by),in(bz));
    Point<I> ci = Point<I>(in(cx),in(cy),in(cz));

    I idet = triple_product(ai,bi,ci);

    if (!zero_in(idet))
    {
        if (idet > 0)
            return t_left;

        return t_right;
    }

    Point<R> ar =  Point<R>(rat(ax),rat(ay),rat(az));
    Point<R> br =  Point<R>(rat(bx),rat(by),rat(bz));
    Point<R> cr =  Point<R>(rat(cx),rat(cy),rat(cz));

    R rdet = triple_product(ar,br,cr);

    if (rdet > 0)
        return t_left;
    if (rdet < 0)
        return t_right;

    return collinear;
}

bool on_equator(Segment seg1,Segment seg2){
    Point<double> a = *seg1.left;
    Point<double> b = *seg1.right;
    Point<double> c = *seg2.left;
    Point<double> d = *seg2.right;

//    cout<<a.x<<" "<<a.y<<" "<<a.z<<endl;
//    cout<<b.x<<" "<<b.y<<" "<<b.z<<endl;
//    cout<<c.x<<" "<<c.y<<" "<<c.z<<endl;
//    cout<<d.x<<" "<<d.y<<" "<<d.z<<endl;

    turn_t l = left_turn(a.x, a.y, a.z,
                         b.x, b.y, b.z,
                         c.x, c.y, c.z);
    turn_t r = left_turn(a.x, a.y, a.z,
                         b.x, b.y, b.z,
                         d.x, d.y, d.z);
//    cout<<l<<endl;
//    cout<<r<<endl;
    if(l!=collinear || r!=collinear){
        return false;
    }
    return true;
}

bool in_same_hemisphere(Segment seg1,Segment seg2){
    Point<double> a = *seg1.left;
    Point<double> b = *seg1.right;
    Point<double> c = *seg2.left;
    Point<double> d = *seg2.right;

    turn_t t1 = left_turn(a.x-d.x,a.y-d.y,a.z-d.z,
                          b.x-d.x,b.y-d.y,b.z-d.z,
                          c.x-d.x,c.y-d.y,c.z-d.z);
    turn_t t2 =left_turn(a.x,a.y,a.z,
                         b.x,b.y,b.z,
                         c.x,c.y,c.z);


    turn_t  t3 = left_turn(d.x-a.x,d.y-a.y,d.z-a.z,
                           b.x-a.x,b.y-a.y,b.z-a.z,
                           c.x-a.x,c.y-a.y,c.z-a.z);
    turn_t  t4 = left_turn(d.x,d.y,d.z,
                           b.x,b.y,b.z,
                           c.x,c.y,c.z);


    turn_t  t5=left_turn(a.x-b.x,a.y-b.y,a.z-b.z,
                         d.x-b.x,d.y-b.y,d.z-b.z,
                         c.x-b.x,c.y-b.y,c.z-b.z);
    turn_t  t6=left_turn(a.x,a.y,a.z,
                         d.x,d.y,d.z,
                         c.x,c.y,c.z);



    turn_t  t7 = left_turn(a.x-c.x,a.y-c.y,a.z-c.z,
                           b.x-c.x,b.y-c.y,b.z-c.z,
                           d.x-c.x,d.y-c.y,d.z-c.z);
    turn_t  t8 =  left_turn(a.x,a.y,a.z,
                            b.x,b.y,b.z,
                            d.x,d.y,d.z);

    if(t1!=t2||t3!=t4||t5!=t6||t7!=t8){
        return true;
    }
    return false;
}
/*checks if [a,b] intersects [c,d] on the sphere*/
bool is_intersects(Segment seg1,Segment seg2){
    Point<double> a = *seg1.left;
    Point<double> b = *seg1.right;
    Point<double> c = *seg2.left;
    Point<double> d = *seg2.right;

    if(on_equator(seg1,seg2)){
//        cout<<"Hello!!!"<<endl;
        double nx = a.y*b.z - a.z*b.y;
        double ny = a.z*b.x - a.x*b.z;
        double nz = a.x*b.y - a.y*b.x;

        double abx = a.x-b.x;
        double aby = a.y-b.y;
        double abz = a.z-b.z;


        turn_t l = left_turn(nx,ny,nz,
                             abx, aby, abz,
                             c.x-a.x,c.y-a.y,c.z-a.z);
        turn_t r = left_turn(
                    nx,ny,nz,
                    abx, aby, abz,
                    d.x-a.x,d.y-a.y,d.z-a.z);
        if(l>=collinear || r>=collinear) return true;
        return false;

    }

    if(!in_same_hemisphere(seg1,seg2)){
        return false;
    }


    turn_t l= left_turn(a.x,a.y,a.z,
                        b.x,b.y,b.z,
                        c.x,c.y,c.z);
    turn_t r = left_turn(a.x,a.y,a.z,
                         b.x,b.y,b.z,
                         d.x,d.y,d.z);
    turn_t l2= left_turn(c.x,c.y,c.z,
                         d.x,d.y,d.z,
                         a.x,a.y,a.z);
    turn_t r2 = left_turn(c.x,c.y,c.z,
                          d.x,d.y,d.z,
                          b.x,b.y,b.z);

    return abs(l+r)<2&&abs(l2+r2)<2;
}

int main(int argc, char *argv[])
{
    //QApplication app(argc, argv);
    ::testing::InitGoogleTest(&argc, argv);
    bool result =  RUN_ALL_TESTS();
    //Visual myVisual;
    //myVisual.show();
//    cout<<"Hello"<<endl;


//    Point<double> p1 = get_euclide_coords(10,m_pi/2,m_pi/6);
//    Point<double> p2 = get_euclide_coords(10,m_pi/2,m_pi);
//    Point<double> p3 = get_euclide_coords(10,m_pi/2,m_pi/4);
//    Point<double> p4 = get_euclide_coords(10,m_pi/2,m_pi/2);
//    std::cout.setf(std::ios::boolalpha);
//    Segment seg1 = Segment(&p1,&p2);
//    Segment seg2 = Segment(&p3,&p4);
//    cout<<is_intersects(seg1,seg2)<<endl;

    return result;//app.exec();
}
