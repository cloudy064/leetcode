//
// Created by cloudy064 on 2018/6/22.
//


#include <algorithm>
#include <unordered_map>
#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/valid-parentheses/description/

class Solution {
public:
    bool isValid(string s) {
        int size = s.length();
        if (size == 0) return true;
        if (size % 2 == 1) return false;

        vector<char> vec;
        vec.reserve(size / 2);
        int count = 0;
        for (auto c : s) {
            if (vec.empty()) {
                vec.push_back(c);
                ++count;
            } else {
                switch (c) {
                    case ')':
                        if (vec[count - 1] == '(') {
                            vec.pop_back();
                            --count;
                        }
                        continue;

                    case '}':
                        if (vec[count - 1] == '{') {
                            vec.pop_back();
                            --count;
                        }
                        continue;
                    case ']':
                        if (vec[count - 1] == '[') {
                            vec.pop_back();
                            --count;
                        }
                        continue;
                }

                vec.push_back(c);
                ++count;
            }
        }

        return vec.empty();
    }
};

class Test020Solution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(Test020Solution, t1)
{
    ASSERT_TRUE(sln.isValid(""));
}

TEST_F(Test020Solution, t2)
{
    ASSERT_TRUE(sln.isValid("()"));
    ASSERT_TRUE(sln.isValid("([])"));
    ASSERT_TRUE(sln.isValid("({})"));
    ASSERT_TRUE(sln.isValid("{([])}"));
}

TEST_F(Test020Solution, t3)
{
    ASSERT_FALSE(sln.isValid("(]"));
    ASSERT_FALSE(sln.isValid("([)]"));
    ASSERT_FALSE(sln.isValid("([)"));
}


GTEST_MAIN