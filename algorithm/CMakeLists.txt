cmake_minimum_required(VERSION 3.10)
project(leetcode)

set(CMAKE_CXX_STANDARD 17)

if (MSVC)
# For MSVC, CMake sets certain flags to defaults we want to override.
# This replacement code is taken from sample in the CMake Wiki at
# http://www.cmake.org/Wiki/CMake_FAQ#Dynamic_Replace.
foreach (flag_var
            CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
            CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
    # When Google Test is built as a shared library, it should also use
    # shared runtime libraries.  Otherwise, it may end up with multiple
    # copies of runtime library data in different modules, resulting in
    # hard-to-find crashes. When it is built as a static library, it is
    # preferable to use CRT as static libraries, as we don't have to rely
    # on CRT DLLs being available. CMake always defaults to using shared
    # CRT libraries, so we override that default here.
    string(REPLACE "/MD" "-MT" ${flag_var} "${${flag_var}}")
endforeach()
endif()


add_subdirectory(./googletest)
include_directories(./googletest/googletest/include)
link_directories(./googletest/googletest)

add_executable(001.two_sum 001.two_sum.cpp)
target_link_libraries(001.two_sum gtest)

add_executable(002.add_two_numbers 002.add_two_numbers.cpp)
target_link_libraries(002.add_two_numbers gtest)

add_executable(003.length_of_longest_substring 003.length_of_longest_substring.cpp)
target_link_libraries(003.length_of_longest_substring gtest)

add_executable(004.find_median_sorted_arrays 004.find_median_sorted_arrays.cpp)
target_link_libraries(004.find_median_sorted_arrays gtest)

add_executable(005.longest_palindrome 005.longest_palindrome.cpp)
target_link_libraries(005.longest_palindrome gtest)

add_executable(006.convert 006.convert.cpp)
target_link_libraries(006.convert gtest)

add_executable(007.reverse 007.reverse.cpp)
target_link_libraries(007.reverse gtest)

add_executable(009.is_palindrome 009.is_palindrome.cpp)
target_link_libraries(009.is_palindrome gtest)

add_executable(010.is_match 010.is_match.cpp)
target_link_libraries(010.is_match gtest)