cmake_minimum_required(VERSION 3.27)
project(vk-test-task)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON) 

file(COPY ${CMAKE_SOURCE_DIR}/graph.txt
     DESTINATION ${CMAKE_BINARY_DIR}
)

include_directories(include)

file(GLOB_RECURSE SRC_FILES src/*.cpp)

add_executable(vktask ${SRC_FILES})

target_compile_options(vktask PRIVATE -O2 -Wall -Wextra -pedantic -pedantic-errors)