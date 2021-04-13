# cmake_minimum_required(VERSION <specify CMake version here>)
project(cpp_study_examples C)

set(CMAKE_C_STANDARD 11)

add_executable(cpp_study_examples
         data_strcture/list/list.h data_strcture/list/list.c data_strcture/list/test.c data_strcture/hashtable/hashtable.h data_strcture/hashtable/hashtable.c)
