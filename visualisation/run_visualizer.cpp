#include <QApplication>

#include "my_visualizer.h"
#include <gtest/gtest.h>
int main(int argc, char *argv[])
{
    //::testing::InitGoogleTest(&argc, argv);
    //bool result =  RUN_ALL_TESTS();
    QApplication app(argc, argv);

    MyVisualizer p;
    p.show();

    return app.exec();//&&result;
}

