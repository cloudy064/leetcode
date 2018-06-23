//
// Created by cloudy064 on 2018/6/21.
//


#include <algorithm>
#include <unordered_map>
#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/roman-to-integer/description/

/**
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
 */

class Solution {
public:
    int romanToInt(string s) {
		unordered_map<char, int> map = {
			{ 'I', 1 },
			{ 'V', 5 },
			{ 'X', 10 },
			{ 'L', 50 },
			{ 'C', 100 },
			{ 'D', 500 },
			{ 'M', 1000 }
		};

        int len = s.length();
        int num = 0;
        for (int i = 0; i < len; ++i) {
            char c = s[i];
            if (c == 'I' || c == 'X' || c =='C') {
                if (i + 1 < len && map[c] < map[s[i + 1]]) {
                    num -= map[c];
                    continue;
                }
            }

            num += map[c];
        }

        return num;
    }
};

class Test013Solution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(Test013Solution, t1)
{
    EXPECT_EQ(sln.romanToInt("III"), 3);
}

TEST_F(Test013Solution, t2)
{
    EXPECT_EQ(sln.romanToInt("IV"), 4);
}

TEST_F(Test013Solution, t3)
{
    EXPECT_EQ(sln.romanToInt("IX"), 9);
}

TEST_F(Test013Solution, t4)
{
    EXPECT_EQ(sln.romanToInt("LVIII"), 58);
}

TEST_F(Test013Solution, t5)
{
    EXPECT_EQ(sln.romanToInt("MCMXCIV"), 1994);
}

GTEST_MAIN