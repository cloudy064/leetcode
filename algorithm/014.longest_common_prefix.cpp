//
// Created by cloudy064 on 2018/6/21.
//


#include <algorithm>
#include <unordered_map>
#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/longest-common-prefix/description/

class Solution {
public:

};

class Test012Solution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(Test012Solution, t1)
{
    EXPECT_EQ(sln.romanToInt("III"), 3);
}

TEST_F(Test012Solution, t2)
{
    EXPECT_EQ(sln.romanToInt("IV"), 4);
}

TEST_F(Test012Solution, t3)
{
    EXPECT_EQ(sln.romanToInt("IX"), 9);
}

TEST_F(Test012Solution, t4)
{
    EXPECT_EQ(sln.romanToInt("LVIII"), 58);
}

TEST_F(Test012Solution, t5)
{
    EXPECT_EQ(sln.romanToInt("MCMXCIV"), 1994);
}

GTEST_MAIN