set(${HEADERS} ./has_intersection.h ./point.h ./segment.h ./common.h)
set(SOURCES ${SOURCES} ./has_intersection.cpp)
add_library(intersection_logic ${HEADERS} ${SOURCES} )
target_link_libraries(intersection_logic Geometry2 ${GMP_LIBRARIES} ${Boost_LIBRARIES})
