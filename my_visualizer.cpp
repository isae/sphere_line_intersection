#include "my_visualizer.h"
#include "vector2d.h"
#include <iostream>
#include "has_intersection.h"


using namespace std;
MyVisualizer::MyVisualizer()
{
    setLineSegments(20);
    setSpaceSegments(35);

    addLine(Vector2D(M_PI / 2, M_PI / 6), Vector2D(M_PI / 2, M_PI));
    addLine(Vector2D(M_PI / 2, M_PI / 4), Vector2D(M_PI / 2, M_PI / 2));


}

void MyVisualizer::handleAddingPoint(const Vector2D& point)
{
    if(!isLastAdded)
    {
        isLastAdded = true;
        lastAdded = point;
      //  cout<<"Point was added"<<endl;
    }
    else {
      //  cout<<"Second point was added"<<endl;
        addLine(point,lastAdded);
        isLastAdded = false;
    }
}

void MyVisualizer::handleRemovingPoint(const Vector2D& point)
{
    isLastAdded = false;

}

void MyVisualizer::handleAddingLine(const Vector2D& from, const Vector2D& to)
{
    int thisPosition = -1;
    bool intersect = false;
    for(int i=0;i<lines.size();i++){
        tuple<Vector2D, Vector2D, QColor> tuple = lines[i];
        if(!(get<0>(tuple)==from && get<1>(tuple)==to)){
            Vector2D otherFrom= get<0>(tuple);
            Vector2D otherTo = get<1>(tuple);
            Vector3D a = map(from);
            Vector3D b = map(to);
            Vector3D c = map(otherFrom);
            Vector3D d = map(otherTo);
            Point<double> ap = Point<double>(a.x,a.y,a.z);
            Point<double> bp = Point<double>(b.x,b.y,b.z);
            Point<double> cp = Point<double>(c.x,c.y,c.z);
            Point<double> dp = Point<double>(d.x,d.y,d.z);
            Segment seg1 = Segment(&ap,&bp);
            Segment seg2 = Segment(&cp,&dp);
            if(is_intersects(seg1,seg2)){
                lines[i] = make_tuple(otherFrom, otherTo, QColor::fromRgbF(0,1,0,1));
                intersect = true;
            }
            //cout<<"Line was added"<<endl;
//            cout<<radius<<endl;
        } else {thisPosition = i;}
    }
    if(intersect){
        lines[thisPosition] = make_tuple(from, to, QColor::fromRgbF(0,1,0,1));
    }
}
