//
// Created by 常永耘 on 2018/6/18.
//

#include <iostream>
#include <cmath>

#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int reverse(int num) {
        auto lnum = static_cast<long>(num);
        auto int_max = static_cast<long>(pow(2, 31));
        auto int_min = static_cast<long>(pow(2 ,31) - 1);
        long positive = abs(lnum);
        long res = 0;
        while (positive != 0) {
            long mod = positive % 10;
            res = res * 10 + mod;
            if (res > pow(2, 31) -1 && num > 0) return 0;
            if (res > pow(2, 31) && num < 0) return 0;
            positive /= 10;
        }

        return static_cast<int>((num < 0) ? -res : res);
    }
};


class TestSolution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(TestSolution, zero) {
    int expect = 0;
    int result = sln.reverse(0);
    ASSERT_EQ(expect, result);
}

TEST_F(TestSolution, positive) {
    int expect = 1234;
    int result = sln.reverse(4321);
    ASSERT_EQ(expect, result);
}

TEST_F(TestSolution, negative) {
    int expect = -1234;
    int result = sln.reverse(-4321);
    ASSERT_EQ(expect, result);
}

TEST_F(TestSolution, overflow_positive) {
    int expect = 0;
    int result = sln.reverse(1534236469);
    ASSERT_EQ(expect, result);
}

TEST_F(TestSolution, overflow_negative) {
    int expect = 0;
    int result = sln.reverse(-2147483648);
    ASSERT_EQ(expect, result);
}

GTEST_API_ int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
