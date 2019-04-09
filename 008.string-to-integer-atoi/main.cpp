//
// Created by cloudy064 on 2018/6/19.
//

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/string-to-integer-atoi/description/

class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) return 0;
        int i = 0;
        int length = str.length();
        while (i < length && isblank(str[i])) ++i;

        if (i >= length) return 0;
        bool negative = false;
        if (str[i] == '-')
        {
            negative = true;
            ++i;
        }
        else if (str[i] == '+')
        {
            //negative = false;
            ++i;
        }

        int result = 0;
        int multi_max = INT_MAX / 10;
        for (; i < length && isdigit(str[i]); ++i)
        {
            int digit = str[i] - '0';
            if (result > multi_max) return negative ? INT_MIN : INT_MAX;
            if (result == multi_max)
            {
                if (negative && digit >= 8)
                {
                    return INT_MIN;
                }
                else if (!negative && digit >= 7)
                {
                    return INT_MAX;
                }
            }
            result = result * 10 + digit;
        }

        return negative ? -result : result;
    }
};

class Test008Solution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(Test008Solution, negative)
{
    ASSERT_EQ(sln.myAtoi("-1"), -1);
    ASSERT_EQ(sln.myAtoi("-123abc"), -123);
    ASSERT_EQ(sln.myAtoi("   -123"), -123);
    ASSERT_EQ(sln.myAtoi("   -123abc"), -123);
    ASSERT_EQ(sln.myAtoi("-123"), -123);
    ASSERT_EQ(sln.myAtoi("-2147483648"), INT_MIN);
    ASSERT_EQ(sln.myAtoi("-2147483649"), INT_MIN);
    ASSERT_EQ(sln.myAtoi("-21474836490"), INT_MIN);
}

TEST_F(Test008Solution, positive)
{
    ASSERT_EQ(sln.myAtoi("1"), 1);
    ASSERT_EQ(sln.myAtoi("123abc"), 123);
    ASSERT_EQ(sln.myAtoi("   123"), 123);
    ASSERT_EQ(sln.myAtoi("   123abc"), 123);
    ASSERT_EQ(sln.myAtoi("123"), 123);
    ASSERT_EQ(sln.myAtoi("2147483647"), INT_MAX);
    ASSERT_EQ(sln.myAtoi("2147483648"), INT_MAX);
    ASSERT_EQ(sln.myAtoi("21474836470"), INT_MAX);
}

TEST_F(Test008Solution, zero)
{
    ASSERT_EQ(sln.myAtoi("0"), 0);
    ASSERT_EQ(sln.myAtoi("-"), 0);
    ASSERT_EQ(sln.myAtoi("abc"), 0);
    ASSERT_EQ(sln.myAtoi("    "), 0);
}

TEST_F(Test008Solution, simbol)
{
    ASSERT_EQ(sln.myAtoi("+1"), 1);
    ASSERT_EQ(sln.myAtoi("-1"), -1);
    ASSERT_EQ(sln.myAtoi("-+1"), 0);
}

GTEST_MAIN