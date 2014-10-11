cmake_minimum_required(VERSION 2.8)

project(test)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})

find_package(Boost COMPONENTS random REQUIRED)

find_package(GMP REQUIRED)
include_directories(include ${GMP_INCLUDE_DIR})

set(SOURCES test.cpp)

add_executable(test ${SOURCES})
target_link_libraries(test intersection_logic ${GTEST_BOTH_LIBRARIES} pthread ${GMP_LIBRARIES})
add_custom_target(test_headers ${SOURCES} ${HEADERS})
