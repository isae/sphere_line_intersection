#include "exampleclass.h"

ExampleClass::ExampleClass()
{
    setLineSegments(20);
    setSpaceSegments(35);

    // 1 spherical right triangle
/*<<<<<<< Updated upstream
    addLine(Vector2D(0, 0), Vector2D(M_PI / 2, 0));
    addLine(Vector2D(M_PI / 2, 0), Vector2D(M_PI / 2, M_PI / 2));
    //this line will be green
    addLine(Vector2D(0, M_PI / 2), Vector2D(M_PI / 2, M_PI / 2), QColor::fromRgb(0x0, 0xFF, 0));

    // Add point and remove equal points
    addPoint(Vector2D(5,5));
    removePoints(Vector2D(5,5));

    // Add point and remove equal lines
    addLine(Vector2D(6,7), Vector2D(8, 9.1));
    removeLines(Vector2D(6,7), Vector2D(8, 9.1));

    // 30 random points
    for (int i = 0; i < 30; ++i)
    {
        Vector2D v;
        v.x = Random::nextDouble(0, M_PI);
        v.y = Random::nextDouble(0, M_PI);
        addPoint(v);
    }
=======*/

    //!test
    addLine(Vector2D(M_PI / 2, M_PI / 6), Vector2D(M_PI / 2, M_PI));
    addLine(Vector2D(M_PI / 2, M_PI / 4), Vector2D(M_PI / 2, M_PI / 2));
    //!test result = true

    //!test
    //addLine(Vector2D(2, M_PI/4), Vector2D(2, -M_PI/4));
    //addLine(Vector2D(1, 0), Vector2D(1, M_PI/2));
    //!test result = false

    //!test
   // space->addLine(Vector2D(-M_PI / 4, 2), Vector2D(M_PI / 4, 2));
    //space->addLine(Vector2D(-3*M_PI / 4, 1), Vector2D(2*M_PI / 4, 1));
    //!test result = false, different semispheres

    //!test
    //space->addLine(Vector2D(0, M_PI/4), Vector2D(0, -M_PI/4));
    //space->addLine(Vector2D(0, 3*M_PI/4), Vector2D(0, -3*M_PI/4));
    //!test result = false, equator

    //!test
    //space->addLine(Vector2D(0, M_PI/4), Vector2D(0, -M_PI/4));
    //space->addLine(Vector2D(0, 0), Vector2D(0, M_PI/2));
    //!test result = true, equator

    //space->addLine(Vector2D(M_PI / 2, 0), Vector2D(M_PI / 2, M_PI / 2));
    //  space->addLine(Vector2D(0, M_PI / 2), Vector2D(M_PI / 2, M_PI / 2));

    // Add point and remove equal point
    //space->addPoint(Vector2D(5,5));
    //space->removePoint(Vector2D(5,5));

    // 30 random points
    // for (int i = 0; i < 30; ++i)
    //{
    //   Vector2D v;
    //  v.x = Random::nextDouble(0, M_PI);
    // v.y = Random::nextDouble(0, M_PI);
    //space->addPoint(v);
    //}
//>>>>>>> Stashed changes
}
