cmake_minimum_required(VERSION 3.27)
project(vk_test_task)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON) 

file(COPY ${CMAKE_SOURCE_DIR}/graph.txt
     DESTINATION ${CMAKE_BINARY_DIR}
)

include_directories(include)

file(GLOB_RECURSE SRC_FILES src/*.cpp)

add_executable(vktask ${SRC_FILES})

target_compile_options(vktask PRIVATE -O2 -Wall -Wextra -pedantic -pedantic-errors)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  runUnutTests
  test/test.cpp
  src/graph.cpp
)
target_link_libraries(
  runUnutTests
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(runUnutTests)

