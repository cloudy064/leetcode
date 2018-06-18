cmake_minimum_required(VERSION 3.10)
project(leetcode)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(./googletest/googletest)
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
