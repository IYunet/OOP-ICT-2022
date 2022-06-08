add_library(labs)

target_sources(labs
  PRIVATE
        lab1/Point.cpp
        lab1/Polyline.cpp
        lab1/ClosedPolyline.cpp
        lab1/Polygon.cpp
        lab1/Triangle.cpp
        lab1/Trapeze.cpp
        lab1/RegularPolygon.cpp
  PUBLIC
        lab1/Point.h
        lab1/Polyline.h
        lab1/ClosedPolyline.h
        lab1/Polygon.h
        lab1/Triangle.h
        lab1/Trapeze.h
        lab1/RegularPolygon.h
  )

target_include_directories(labs
  PUBLIC
        .
  )

# we use this to get code coverage
# flags are only valid with the GNU compiler and on Linux
if(CMAKE_CXX_COMPILER_ID MATCHES GNU AND CMAKE_HOST_SYSTEM_NAME STREQUAL "Linux")
  target_compile_options(labs
    PUBLIC
      "--coverage"
    )
  target_link_options(labs
    INTERFACE
      "--coverage"
    )
endif()
