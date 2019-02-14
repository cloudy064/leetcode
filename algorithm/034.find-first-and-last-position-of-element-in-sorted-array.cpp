//
// Created by 常永耘 on 2019/2/14.
//

#include <vector>

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    int searchFirst(vector<int>& nums, int target, int left, int right) {
        int mid;

        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        if (nums[left] != target) return -1;

        return left;
    }

    int searchLast(vector<int>& nums, int target, int left, int right) {
        int mid;

        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        if (nums[right] != target) return -1;

        return right;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1,-1};

        int size = nums.size();
        if (size == 1) {
            if (nums[0] == target) {
                return {0, 0};
            }
        }


        if (nums[0] > target) return {-1, -1};
        if (nums[size - 1] < target) return {-1, -1};

        int left = searchFirst(nums, target, 0, size - 1);
        if (left == -1) return {-1, -1};

        return {left, searchLast(nums, target, left, size - 1)};
    }
};

class Test033Solution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(Test033Solution, t1) {
    vector<int> nums = {5,7,7,8,8,10};
    ASSERT_EQ(sln.searchRange(nums, 8), vector<int>({3, 4}));
    ASSERT_EQ(sln.searchRange(nums, 6), vector<int>({-1, -1}));
}

TEST_F(Test033Solution, t2) {
    vector<int> nums = {5,5,5,5,5,5,5,5};
    ASSERT_EQ(sln.searchRange(nums, 5), vector<int>({0, 7}));
    ASSERT_EQ(sln.searchRange(nums, 6), vector<int>({-1, -1}));
}

TEST_F(Test033Solution, t3) {
    vector<int> nums = {5,5,5,5,5,5,5};
    ASSERT_EQ(sln.searchRange(nums, 5), vector<int>({0, 6}));
    ASSERT_EQ(sln.searchRange(nums, 6), vector<int>({-1, -1}));
}

TEST_F(Test033Solution, t4) {
    vector<int> nums = {5};
    ASSERT_EQ(sln.searchRange(nums, 5), vector<int>({0, 0}));
    ASSERT_EQ(sln.searchRange(nums, 6), vector<int>({-1, -1}));
}

TEST_F(Test033Solution, t5) {
    vector<int> nums = {1,8,8,8,9,10};
    ASSERT_EQ(sln.searchRange(nums, 8), vector<int>({1, 3}));
    ASSERT_EQ(sln.searchRange(nums, 1), vector<int>({0,0}));
    ASSERT_EQ(sln.searchRange(nums, 9), vector<int>({4,4}));
    ASSERT_EQ(sln.searchRange(nums, 10), vector<int>({5,5}));
}

GTEST_MAIN
