cmake_minimum_required(VERSION 2.8)

set(PROJECT sphere_intersections)
project(${PROJECT})


set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -std=c++11 -Wall")
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMake/Modules)

# Add Qt packages
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5OpenGL REQUIRED)

add_subdirectory(3rdParty/visualizer)
include_directories(include 3rdParty/visualizer/headers)

find_package(Boost REQUIRED)
include_directories(include ${Boost_INCLUDE_DIR})

find_package(GMP REQUIRED)
include_directories(include ${GMP_INCLUDE_DIR})

find_package(GTest REQUIRED)
include_directories(include ${GTEST_INCLUDE_DIR})

if(CMAKE_C_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
endif()

add_subdirectory(include)
#add_subdirectory(test)
add_subdirectory(visualisation)
