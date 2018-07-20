//
// Created by cloudy064 on 2018/6/19.
//

#include "common.h"

/// Solution for https://leetcode-cn.com/problems/palindrome-number/description/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;

        int digits[10];
        int len = 0;
        while (x != 0) {
            digits[len++] = x % 10;
            x /= 10;
        }

        for (size_t i = 0; i < len / 2; i++) {
            if (digits[i] != digits[len - i - 1]) return false;
        }

        return true;
    }
};

class Test009Solution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(Test009Solution, negative) {
    ASSERT_FALSE(sln.isPalindrome(-1));
    ASSERT_FALSE(sln.isPalindrome(-10));
    ASSERT_FALSE(sln.isPalindrome(-121));
}

TEST_F(Test009Solution, zero) {
    ASSERT_TRUE(sln.isPalindrome(0));
}

TEST_F(Test009Solution, positive) {
    ASSERT_TRUE(sln.isPalindrome(121));
    ASSERT_TRUE(sln.isPalindrome(1));
    ASSERT_TRUE(sln.isPalindrome(1331));
    ASSERT_FALSE(sln.isPalindrome(10));
    ASSERT_FALSE(sln.isPalindrome(1031));
}

GTEST_MAIN