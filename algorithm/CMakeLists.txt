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

add_executable(003.longest_substring_without_repeating_characters 003.longest_substring_without_repeating_characters.cpp)
target_link_libraries(003.longest_substring_without_repeating_characters gtest)

add_executable(005.longest_palindromic_substring 005.longest_palindromic_substring.cpp)
target_link_libraries(005.longest_palindromic_substring gtest)

add_executable(006.zigzag_conversion 006.zigzag_conversion.cpp)
target_link_libraries(006.zigzag_conversion gtest)

add_executable(007.reverse_integer 007.reverse_integer.cpp)
target_link_libraries(007.reverse_integer gtest)

add_executable(008.string_to_integer_atoi 008.string_to_integer_atoi.cpp)
target_link_libraries(008.string_to_integer_atoi gtest)

add_executable(009.palindrome_number 009.palindrome_number.cpp)
target_link_libraries(009.palindrome_number gtest)

add_executable(011.container_with_most_water 011.container_with_most_water.cpp)
target_link_libraries(011.container_with_most_water gtest)

add_executable(012.integer_to_roman 012.integer_to_roman.cpp)
target_link_libraries(012.integer_to_roman gtest)

add_executable(013.roman_to_integer 013.roman_to_integer.cpp)
target_link_libraries(013.roman_to_integer gtest)

add_executable(014.longest_common_prefix 014.longest_common_prefix.cpp)
target_link_libraries(014.longest_common_prefix gtest)

add_executable(015.3sum 015.3sum.cpp)
target_link_libraries(015.3sum gtest)

add_executable(016.3sum_closest 016.3sum_closest.cpp)
target_link_libraries(016.3sum_closest gtest)