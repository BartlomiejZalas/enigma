cmake_minimum_required(VERSION 3.14)
project(enigma)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/b796f7d44681514f58a683a3a71ff17c94edb0c1.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

set(
  SRC
  functions.cpp
  functions.h
  Rotor.cpp
  Rotor.h
)
set(LIBRARY_NAME ${PROJECT_NAME}-lib)
set(MAIN_NAME ${PROJECT_NAME})
set(TEST_NAME ${PROJECT_NAME}-tests)

add_library(${LIBRARY_NAME} ${SRC})
add_executable(${MAIN_NAME} main.cpp)
add_executable(${TEST_NAME} hello_test.cpp)

target_link_libraries(${MAIN_NAME}  ${LIBRARY_NAME})
target_link_libraries(${TEST_NAME}  ${LIBRARY_NAME})
target_link_libraries(${TEST_NAME}  GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(${TEST_NAME})
