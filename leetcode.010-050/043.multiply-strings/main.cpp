//
// Created by 常永耘 on 2019/2/15.
//

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/multiply-strings/


class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int len2 = num2.length();
        int len1 = num1.length();
        string temp;
        vector<string> results;
        int carry = 0;
        int numOfZero = 0;
        int maxLength = 0;
        for (int i = len1 - 1; i >= 0; --i, ++numOfZero) {
            auto c1 = num1[i];
            temp.clear();
            carry = 0;

            for (int k = 0; k < numOfZero; ++k) {
                temp.push_back('0');
            }

            int n1 = c1 - '0';
            for (int j = len2 - 1; j >= 0; --j) {
                int n2 = num2[j] - '0';
                int r = n2 * n1 + carry;
                temp += (r % 10 + '0');
                carry = r / 10;
            }

            if (carry != 0) {
                temp += (carry + '0');
            }

            int l = temp.length();
            if (l > maxLength) {
                maxLength = l;
            }

            results.push_back(temp);
        }

        int resultsSize = results.size();
        string result;
        carry = 0;
        for (int i = 0; i < maxLength; ++i) {
            auto r = carry;
            for (auto str : results) {
                if (str.length() <= i) continue;

                r += (str[i] - '0');
            }

            result += (r % 10 + '0');
            carry = r / 10;
        }

        if (carry != 0) {
            result += (carry + '0');
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

class Test043Solution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(Test043Solution, t1) {
    ASSERT_EQ(sln.multiply("1", "2"), "2");
    ASSERT_EQ(sln.multiply("9", "99"), "891");
    ASSERT_EQ(sln.multiply("123", "456"), "56088");
}

GTEST_MAIN