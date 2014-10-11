cmake_minimum_required(VERSION 2.8)

set(PROJECT visualization)
project(${PROJECT})

# Add Qt packages
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5OpenGL REQUIRED)


file(GLOB HEADERS "*.h")
add_custom_target(v_h ${HEADERS})
set(SOURCES ./my_visualizer.cpp ./run_visualizer.cpp)


#
add_executable(${PROJECT} ${HEADERS} ${SOURCES})
target_link_libraries(${PROJECT} intersection_logic Geometry2 ${GMP_LIBRARIES})
#

qt5_use_modules(${PROJECT} Core Gui Widgets OpenGL)

# Fix OpenGL "undefined reference" problem
if( WIN32 )
    target_link_libraries(${PROJECT} OpenGL32)
else()
    target_link_libraries(${PROJECT} GL)
endif()
