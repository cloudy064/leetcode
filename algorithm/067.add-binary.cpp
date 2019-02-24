//
// Created by 常永耘 on 2019/2/24.
//

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/add-binary/

class Solution {
public:
    string addBinary(string a, string b) {
        int alen = a.length();
        int blen = b.length();
        if (alen == 0) return b;
        if (blen == 0) return a;

        int len = max(alen, blen) + 1;
        string result(len, '0');

        int ai = alen - 1;
        int bi = blen - 1;
        int i = len - 1;
        int carry = 0;
        while (ai >= 0 || bi >= 0) {
            int sum = carry;
            if (ai >= 0) {
                sum += (a[ai] - '0');
            }

            if (bi >= 0) {
                sum += (b[bi] - '0');
            }

            carry = sum / 2;
            result[i] = (sum % 2) + '0';

            --ai;
            --bi;
            --i;
        }

        if (carry != 0) {
            result[0] = carry + '0';
        } else {
            result = result.substr(1);
        }

        return result;
    }
};

class Test067Solution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(Test067Solution, t1) {
    EXPECT_EQ(sln.addBinary("0", ""), "0");
}

TEST_F(Test067Solution, t2) {
    EXPECT_EQ(sln.addBinary("0", "11"), "11");
}

TEST_F(Test067Solution, t3) {
    EXPECT_EQ(sln.addBinary("1", "11"), "100");
}

TEST_F(Test067Solution, t4) {
    EXPECT_EQ(sln.addBinary("11", "11"), "110");
}

TEST_F(Test067Solution, t5) {
    EXPECT_EQ(sln.addBinary("1010", "1011"), "10101");
}

GTEST_MAIN
