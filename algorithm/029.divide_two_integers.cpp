//
// Created by cloudy064 on 2018/6/26.
//

#include <iostream>
#include <vector>
#include <unordered_map>

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/divide-two-integers/description/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        if (divisor == 1) return dividend;
        if (divisor == -1) {
            if (dividend == INT_MIN) return INT_MAX;
            return -dividend;
        }

        unordered_map<int, int> map;

        bool same_sign = true;
        if (dividend > 0 && divisor < 0 || dividend < 0 && divisor > 0) {
            same_sign = false;
        }

        if (dividend > 0) dividend = -dividend;
        if (divisor > 0) divisor = -divisor;

        if (dividend > divisor) return 0;

        map[0] = 0;
        map[1] = divisor;
        int sum = divisor;

        // sum + divisor > INT_MIN
        int count = 1;
        int idx = 1;
        while (INT_MIN - sum < sum && sum + sum > dividend) {
            sum <<= 1;
            count <<= 1;
            idx <<= 1;
            map[count] = sum;
        }

        int result = count;
        int remain = dividend - sum;
        while (remain != 0 && map[idx] != 0) {
            //while (remain > map[])
            while (remain > map[idx] && map[idx] != 0)
            {
                idx >>= 1;
            }

            remain -= map[idx];
            count += idx;
        }

        return same_sign ? count : -count;
    }
};


class Test029Solution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(Test029Solution, t1)
{
    EXPECT_EQ(sln.divide(10, 3), 3);
}

TEST_F(Test029Solution, t2)
{
    EXPECT_EQ(sln.divide(-10, 3), -3);
}

TEST_F(Test029Solution, t3)
{
    EXPECT_EQ(sln.divide(7, -3), -2);
}

TEST_F(Test029Solution, t4)
{
    EXPECT_EQ(sln.divide(1, 2), 1);
}

TEST_F(Test029Solution, t5)
{
    EXPECT_EQ(sln.divide(INT_MAX, 2), INT_MAX / 2);
}

TEST_F(Test029Solution, t6)
{
    EXPECT_EQ(sln.divide(INT_MIN, INT_MAX), -1);
}

TEST_F(Test029Solution, t7)
{
    EXPECT_EQ(sln.divide(INT_MAX, INT_MIN), 0);
}
