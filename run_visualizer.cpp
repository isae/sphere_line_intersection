#include <QApplication>

#include "my_visualizer.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MyVisualizer p;
    p.show();

    return app.exec();
}

