//
// Created by 常永耘 on 2019/2/14.
//

#include "common.h"

class Solution {
public:
    int longestValidParentheses(string s) {
        int length = 0;
        int sum = 0;
        int maxLength = 0;

        for (int i = 0; i < s.length(); ++i) {
            auto c = s[i];
            if (c == '(') {
                ++sum;
            } else {
                --sum;
            }

            ++length;
            if (sum == 0) {
                if (length > maxLength) {
                    maxLength = length;
                }
            } else if (sum < 0) {
                length = 0;
                sum = 0;
            }
        }

        length = 0;
        sum = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            auto c = s[i];
            if (c == ')') {
                ++sum;
            } else {
                --sum;
            }

            ++length;
            if (sum == 0) {
                if (length > maxLength) {
                    maxLength = length;
                }
            } else if (sum < 0) {
                length = 0;
                sum = 0;
            }
        }

        return maxLength;
    }
};

class Test032Solution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(Test032Solution, t1) {
    auto s = "()(()";
    ASSERT_EQ(sln.longestValidParentheses(s), 2);
}

TEST_F(Test032Solution, t2) {
    auto s = "()()()";
    ASSERT_EQ(sln.longestValidParentheses(s), 6);
}

TEST_F(Test032Solution, t3) {
    auto s = "()(())";
    ASSERT_EQ(sln.longestValidParentheses(s), 6);
}

TEST_F(Test032Solution, t4) {
    auto s = "((()()";
    ASSERT_EQ(sln.longestValidParentheses(s), 4);
}

TEST_F(Test032Solution, t5) {
    auto s = "()()))";
    ASSERT_EQ(sln.longestValidParentheses(s), 4);
}

TEST_F(Test032Solution, t6) {
    auto s = "((()))";
    ASSERT_EQ(sln.longestValidParentheses(s), 6);
}

GTEST_MAIN