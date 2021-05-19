# cmake_minimum_required(VERSION <specify CMake version here>)
project(cpp_study_examples)

set (CMAKE_CXX_STANDARD 11)

#add_executable(cpp_study_examples
#         data_structure/list/list.h data_strcture/list/list.c data_strcture/list/test.c data_strcture/hashtable/hashtable.h data_strcture/hashtable/hashtable.c test_case/pointer_test.c)

#add_executable(cpp_study_examples test_case/pointer_test.c test_case/variable.c test_case/scope_test.c)
#add_executable(cpp_study_examples test_case/variable.c test_case/scope_test.c test_case/variable.h test_case/const_test.c)
#add_executable(cpp_study_examples  test_case/const_test.c test_case/enum_test.c)
add_executable(cpp_study_examples  test_case/union_test.c )
add_executable(smartPtr_examples  cpp_lesson/smartPtr/demo2.cpp cpp_lesson/smartPtr/TestA.h)