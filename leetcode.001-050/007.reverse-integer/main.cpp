//
// Created by cloudy064 on 2018/6/18.
//

#include <iostream>
#include <cmath>

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/reverse-integer/description/

class Solution {
public:
    // The question has declared that the range of the number is [-2^31, 2^31-1]
    int reverse(int num) {
        int res = 0;
        int max_before = INT_MAX / 10;
        int min_before = INT_MIN / 10;

        while (num != 0) {
            int mod = num % 10;

            if ((res > max_before)
                || (res < min_before)
                || (res == max_before && mod > 7)
                || (res == min_before && mod < -8)) return 0;

            res = 10 * res + mod;
            num /= 10;
        }

        return res;
    }
};


class Test007Solution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(Test007Solution, zero) {
    int expect = 0;
    int result = sln.reverse(0);
    ASSERT_EQ(expect, result);
}

TEST_F(Test007Solution, positive) {
    int expect = 1234;
    int result = sln.reverse(4321);
    ASSERT_EQ(expect, result);
}

TEST_F(Test007Solution, negative) {
    int expect = -1234;
    int result = sln.reverse(-4321);
    ASSERT_EQ(expect, result);
}

TEST_F(Test007Solution, overflow_positive) {
    int expect = 0;
    int result = sln.reverse(1534236469);
    ASSERT_EQ(expect, result);
}

TEST_F(Test007Solution, overflow_negative) {
    int expect = 0;
    int result = sln.reverse(INT_MIN);
    ASSERT_EQ(expect, result);
}

GTEST_MAIN