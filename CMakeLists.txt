cmake_minimum_required(VERSION 3.17)
project(contr)

set(CMAKE_CXX_STANDARD 98)

add_compile_options(-std=c++98)

add_executable(contr main.cpp test_vector.cpp test_list.cpp test_stack.cpp test_queue.cpp test_map.cpp)