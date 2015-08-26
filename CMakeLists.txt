CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

PROJECT(big-integer-tests)

ADD_SUBDIRECTORY(external/gmock-1.7.0)

ADD_DEFINITIONS(-std=c++11)

INCLUDE_DIRECTORIES(bitest include ${gtest_SOURCE_DIR}/include)

ADD_EXECUTABLE(bitest biginteger.h biginteger.tests.cpp main.cpp)

TARGET_LINK_LIBRARIES(bitest gtest)
