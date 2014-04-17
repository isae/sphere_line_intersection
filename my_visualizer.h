#ifndef MY_VISUALIZER_H
#define MY_VISUALIZER_H

#include <visualizer/visualization.h>

class MyVisualizer : public Visualization
{
private:
    bool isLastAdded = false;
    Vector2D lastAdded;

public:
    MyVisualizer();
    void handleAddingPoint(const Vector2D&);
    void handleAddingLine(const Vector2D&, const Vector2D&);
    void handleRemovingPoint(const Vector2D&);
};

#endif // MY_VISUALIZER_H
