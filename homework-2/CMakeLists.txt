#To choose 'easy' version of homework you should remove '#' on the second line and remove the    third line at all
#set(RUN_MODE "easy")
set(RUN_MODE "hard")

cmake_minimum_required(VERSION 3.9)
project(number-trie)

set(CMAKE_CXX_STANDARD 17)

include(testing/CMakeLists.txt)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-sign-compare -pedantic")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=undefined,address -fno-sanitize-recover=all -D_GLIBCXX_DEBUG")


set(SOURCES number/number.cpp trie/trie.cpp trie/trie.h)
set(HEADERS number/number.h trie/trie.cpp trie/trie.h)
set(TESTS number/number-test.cpp trie/trie.cpp trie/trie.h)

if ("${RUN_MODE}" STREQUAL "hard")
	set(SOURCES ${SOURCES} trie/trie-naive.cpp trie/trie.cpp trie/trie.h)
	set(HEADERS ${HEADERS} trie/trie-naive.h trie/trie.cpp trie/trie.h)
	set(TESTS ${TESTS} trie/trie-test.cpp number/number.cpp number/number.h trie/trie.cpp trie/trie.h)
endif()


add_executable(public-tests ${SOURCES} ${HEADERS} ${TESTS} trie/trie.cpp trie/trie.h)
target_link_libraries(public-tests gtest_main)
