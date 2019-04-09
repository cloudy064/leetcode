//
// Created by 常永耘 on 2019/2/24.
//

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/plus-one/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.empty()) return {1};

        int size = digits.size();
        vector<int> result;
        result.reserve(size + 1);
        int carry = 1;
        for (int i = size - 1; i >= 0; --i) {
            int sum = digits[i] + carry;
            carry = sum / 10;
            result.push_back(sum % 10);
        }

        if (carry != 0) {
            result.push_back(carry);
            size += 1;
        }

        for (int i = 0; i < size / 2; ++i) {
            swap(result[i], result[size - i - 1]);
        }

        return result;
    }
};

class Test066Solution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(Test066Solution, t1) {
    vector<int> nums = {0};
    EXPECT_EQ(sln.plusOne(nums), vector<int>({1}));
}

TEST_F(Test066Solution, t2) {
    vector<int> nums = {9};
    EXPECT_EQ(sln.plusOne(nums), vector<int>({1, 0}));
}

TEST_F(Test066Solution, t3) {
    vector<int> nums = {1,2,3};
    EXPECT_EQ(sln.plusOne(nums), vector<int>({1,2,4}));
}

GTEST_MAIN
