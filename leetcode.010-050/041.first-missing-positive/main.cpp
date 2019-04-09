//
// Created by 常永耘 on 2019/2/15.
//

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/first-missing-positive/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.empty()) return 1;

        int size = nums.size();
        int i = 0;

        while (i < size) {
            auto num = nums[i];
            if (num <= 0 || num > size) {
                ++i;
                continue;
            }

            auto idx = num - 1; // Overflow!!!
            if (i == idx || nums[idx] == num) { // If the target value is already num, DON't SWAP!
                ++i;
                continue;
            }

            swap(nums[i], nums[idx]);
        }

        int result = 0;
        for (int i = 0; i < size; i++) {
            auto num = nums[i];
            if (num != i + 1)  return i + 1;
        }

        return size + 1;
    }
};

class Test041Solution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(Test041Solution, t1) {
    vector<int> candidates = {2,3,6,7};

    auto result = sln.firstMissingPositive(candidates);
    ASSERT_EQ(1, result);
}

TEST_F(Test041Solution, t2) {
    vector<int> candidates = {3,4,-1,1};

    auto result = sln.firstMissingPositive(candidates);
    ASSERT_EQ(2, result);
}

TEST_F(Test041Solution, t3) {
    vector<int> candidates = {1,2,0};

    auto result = sln.firstMissingPositive(candidates);
    ASSERT_EQ(3, result);
}

TEST_F(Test041Solution, t4) {
    vector<int> candidates = {7,8,9,11,12};

    auto result = sln.firstMissingPositive(candidates);
    ASSERT_EQ(1, result);
}

TEST_F(Test041Solution, t5) {
    vector<int> candidates = {1,1};

    auto result = sln.firstMissingPositive(candidates);
    ASSERT_EQ(2, result);
}

TEST_F(Test041Solution, t6) {
    vector<int> candidates = {INT_MAX,2147483646,2147483645,3,2,1,-1,0,INT_MIN };
    auto result = sln.firstMissingPositive(candidates);
    ASSERT_EQ(4, result);
}

TEST_F(Test041Solution, t7) {
    vector<int> candidates = {1,2,3,4};

    auto result = sln.firstMissingPositive(candidates);
    ASSERT_EQ(5, result);
}

GTEST_MAIN