//
// Created by cloudy064 on 2018/6/17.
//

#include <iostream>
#include <map>

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> map;
        int max_index = 0;
        int max_length = 0;
        int cur_index = 0;
        int cur_length = 0;
        for (int i = 0; i < s.length(); i++) {
            auto it = map.find(s[i]);
            if (it != map.end() && it->second >= cur_index) {
                if (cur_length > max_length) {
                    max_length = cur_length;
                }

                cur_length = cur_length - it->second + cur_index;
                cur_index = it->second + 1;
                it->second = i;
            }
            else {
                map[s[i]] = i;
                cur_length += 1;
            }
        }

        if (cur_length > max_length) {
            max_length = cur_length;
        }

        return max_length;
    }
};


class Test003Solution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(Test003Solution, t1) {
    string str = "abcabcbb";
    int length = sln.lengthOfLongestSubstring(str);
    ASSERT_EQ(length, 3);
}

TEST_F(Test003Solution, t2) {
    string str = "bbbbb";
    int length = sln.lengthOfLongestSubstring(str);
    ASSERT_EQ(length, 1);
}

TEST_F(Test003Solution, t3) {
    string str = "pwwkew";
    int length = sln.lengthOfLongestSubstring(str);
    ASSERT_EQ(length, 3);
}

TEST_F(Test003Solution, t4) {
    string str = "abba";
    int length = sln.lengthOfLongestSubstring(str);
    ASSERT_EQ(length, 2);
}

GTEST_MAIN