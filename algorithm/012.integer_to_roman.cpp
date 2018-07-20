//
// Created by cloudy064 on 2018/6/21.
//


#include <algorithm>
#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/integer-to-roman/description/

class Solution {
public:
    string intToRoman(int num) {
        const string roman = "IVXLCDM."; // last character is used for bound check

        string res;

        int idx = 0;
        while (num > 0) {
            int mod = num % 10;
            if (mod < 5) {
                if (mod == 4) {
                    res.push_back(roman[2 * idx + 1]);
                    res.push_back(roman[2 * idx]);
                } else {
                    res.append(mod, roman[2 * idx]);
                }
            } else {
                if (mod == 9) {
                    res.push_back(roman[2 * idx + 2]);
                    res.push_back(roman[2 * idx]);
                } else {
                    res.append(mod - 5, roman[2 * idx]);
                    res.push_back(roman[2 * idx + 1]);
                }
            }

            num /= 10;
            ++idx;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

class Test012Solution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(Test012Solution, t1)
{
    string expect = "III";
    string result = sln.intToRoman(3);
    EXPECT_TRUE(expect.compare(result) == 0);
}

TEST_F(Test012Solution, t2)
{
    string expect = "IV";
    string result = sln.intToRoman(4);
    EXPECT_TRUE(expect.compare(result) == 0);
}

TEST_F(Test012Solution, t3)
{
    string expect = "IX";
    string result = sln.intToRoman(9);
    EXPECT_TRUE(expect.compare(result) == 0);
}

TEST_F(Test012Solution, t4)
{
    string expect = "LVIII";
    string result = sln.intToRoman(58);
    EXPECT_TRUE(expect.compare(result) == 0);
}

TEST_F(Test012Solution, t5)
{
    string expect = "MCMXCIV";
    string result = sln.intToRoman(1994);
    EXPECT_TRUE(expect.compare(result) == 0);
}

GTEST_MAIN