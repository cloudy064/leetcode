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

add_executable(001.two_sum 001.two_sum.cpp common.cpp)
target_link_libraries(001.two_sum gtest)

add_executable(002.add_two_numbers 002.add_two_numbers.cpp common.cpp)
target_link_libraries(002.add_two_numbers gtest)

add_executable(003.longest_substring_without_repeating_characters 003.longest_substring_without_repeating_characters.cpp common.cpp)
target_link_libraries(003.longest_substring_without_repeating_characters gtest)

add_executable(005.longest_palindromic_substring 005.longest_palindromic_substring.cpp common.cpp)
target_link_libraries(005.longest_palindromic_substring gtest)

add_executable(006.zigzag_conversion 006.zigzag_conversion.cpp common.cpp)
target_link_libraries(006.zigzag_conversion gtest)

add_executable(007.reverse_integer 007.reverse_integer.cpp common.cpp)
target_link_libraries(007.reverse_integer gtest)

add_executable(008.string_to_integer_atoi 008.string_to_integer_atoi.cpp common.cpp)
target_link_libraries(008.string_to_integer_atoi gtest)

add_executable(009.palindrome_number 009.palindrome_number.cpp common.cpp)
target_link_libraries(009.palindrome_number gtest)

add_executable(011.container_with_most_water 011.container_with_most_water.cpp common.cpp)
target_link_libraries(011.container_with_most_water gtest)

add_executable(012.integer_to_roman 012.integer_to_roman.cpp common.cpp)
target_link_libraries(012.integer_to_roman gtest)

add_executable(013.roman_to_integer 013.roman_to_integer.cpp common.cpp)
target_link_libraries(013.roman_to_integer gtest)

add_executable(014.longest_common_prefix 014.longest_common_prefix.cpp common.cpp)
target_link_libraries(014.longest_common_prefix gtest)

add_executable(015.3sum 015.3sum.cpp common.cpp)
target_link_libraries(015.3sum gtest)

add_executable(016.3sum_closest 016.3sum_closest.cpp common.cpp)
target_link_libraries(016.3sum_closest gtest)

add_executable(017.letter_combinations_of_a_phone_number 017.letter_combinations_of_a_phone_number.cpp common.cpp)
target_link_libraries(017.letter_combinations_of_a_phone_number gtest)

add_executable(018.4sum 018.4sum.cpp common.cpp)
target_link_libraries(018.4sum gtest)

add_executable(019.remove_nth_node_from_end_of_list 019.remove_nth_node_from_end_of_list.cpp common.cpp)
target_link_libraries(019.remove_nth_node_from_end_of_list gtest)

add_executable(020.valid_parentheses 020.valid_parentheses.cpp common.cpp)
target_link_libraries(020.valid_parentheses gtest)

add_executable(021.merge_two_sorted_lists 021.merge_two_sorted_lists.cpp common.cpp)
target_link_libraries(021.merge_two_sorted_lists gtest)

add_executable(022.generate_parentheses 022.generate_parentheses.cpp common.cpp)
target_link_libraries(022.generate_parentheses gtest)

add_executable(023.merge_k_sorted_lists 023.merge_k_sorted_lists.cpp common.cpp)
target_link_libraries(023.merge_k_sorted_lists gtest)

add_executable(024.swap_nodes_in_pairs 024.swap_nodes_in_pairs.cpp common.cpp)
target_link_libraries(024.swap_nodes_in_pairs gtest)

add_executable(025.reverse_nodes_in_k_group 025.reverse_nodes_in_k_group.cpp common.cpp)
target_link_libraries(025.reverse_nodes_in_k_group gtest)

add_executable(026.remove_duplicates_from_sorted_array 026.remove_duplicates_from_sorted_array.cpp common.cpp)
target_link_libraries(026.remove_duplicates_from_sorted_array gtest)

add_executable(027.remove_element 027.remove_element.cpp common.cpp)
target_link_libraries(027.remove_element gtest)

add_executable(028.implement_strstr 028.implement_strstr.cpp common.cpp)
target_link_libraries(028.implement_strstr gtest)

add_executable(029.divide_two_integers 029.divide_two_integers.cpp common.cpp)
target_link_libraries(029.divide_two_integers gtest)

add_executable(030.substring_with_concatenation_of_all_words 030.substring_with_concatenation_of_all_words.cpp common.cpp)
target_link_libraries(030.substring_with_concatenation_of_all_words gtest)

add_executable(032.longest-valid-parentheses 032.longest-valid-parentheses.cpp common.cpp)
target_link_libraries(032.longest-valid-parentheses gtest)

add_executable(033.search-in-rotated-sorted-array 033.search-in-rotated-sorted-array.cpp common.cpp)
target_link_libraries(033.search-in-rotated-sorted-array gtest)

add_executable(034.find-first-and-last-position-of-element-in-sorted-array 034.find-first-and-last-position-of-element-in-sorted-array.cpp common.cpp)
target_link_libraries(034.find-first-and-last-position-of-element-in-sorted-array gtest)

add_executable(035.search-insert-position 035.search-insert-position.cpp common.cpp)
target_link_libraries(035.search-insert-position gtest)

add_executable(036.valid-sudoku 036.valid-sudoku.cpp common.cpp)
target_link_libraries(036.valid-sudoku gtest)

add_executable(038.count-and-say 038.count-and-say.cpp common.cpp)
target_link_libraries(038.count-and-say gtest)

add_executable(039.combination-sum 039.combination-sum.cpp common.cpp)
target_link_libraries(039.combination-sum gtest)

add_executable(040.combination-sum-ii 040.combination-sum-ii.cpp common.cpp)
target_link_libraries(040.combination-sum-ii gtest)

add_executable(041.first-missing-positive 041.first-missing-positive.cpp common.cpp)
target_link_libraries(041.first-missing-positive gtest)

add_executable(043.multiply-strings 043.multiply-strings.cpp common.cpp)
target_link_libraries(043.multiply-strings gtest)

add_executable(045.jump-game-ii 045.jump-game-ii.cpp common.cpp)
target_link_libraries(045.jump-game-ii gtest)

add_executable(046.permutations 046.permutations.cpp common.cpp)
target_link_libraries(046.permutations gtest)

add_executable(047.permutations-ii 047.permutations-ii.cpp common.cpp)
target_link_libraries(047.permutations-ii gtest)

add_executable(048.rotate-image 048.rotate-image.cpp common.cpp)
target_link_libraries(048.rotate-image gtest)

add_executable(049.group-anagrams 049.group-anagrams.cpp common.cpp)
target_link_libraries(049.group-anagrams gtest)

add_executable(050.powx-n 050.powx-n.cpp common.cpp)
target_link_libraries(050.powx-n gtest)

add_executable(061.rotate-list 061.rotate-list.cpp common.cpp)
target_link_libraries(061.rotate-list gtest)

add_executable(062.unique-paths 062.unique-paths.cpp common.cpp)
target_link_libraries(062.unique-paths gtest)

add_executable(063.unique-paths-ii 063.unique-paths-ii.cpp common.cpp)
target_link_libraries(063.unique-paths-ii gtest)