add_library(labs hotel/Workers.cpp hotel/Workers.h hotel/Rooms.cpp hotel/Rooms.h hotel/Clients.cpp hotel/Clients.h hotel/Book.cpp hotel/Book.h)

target_sources(labs
  PRIVATE
        hotel/Workers.cpp
  PUBLIC
        hotel/Workers.h
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
