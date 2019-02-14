//
// Created by 常永耘 on 2019/2/14.
//

#include <vector>

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/search-insert-position/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();

        int left = 0;
        int right = size - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};

class Test035Solution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(Test035Solution, t1) {
    vector<int> nums = {5,7,7,8,8,10};
    ASSERT_EQ(sln.searchInsert(nums, 8), 3);
    ASSERT_EQ(sln.searchInsert(nums, 6), 1);
}

TEST_F(Test035Solution, t2) {
    vector<int> nums = {1,3,5,6};
    ASSERT_EQ(sln.searchInsert(nums, 5), 2);
    ASSERT_EQ(sln.searchInsert(nums, 2), 1);
    ASSERT_EQ(sln.searchInsert(nums, 7), 4);
    ASSERT_EQ(sln.searchInsert(nums, 0), 0);
}

TEST_F(Test035Solution, t3) {
    vector<int> nums = {1,1,1,1};
    ASSERT_EQ(sln.searchInsert(nums, 5), 4);
    ASSERT_EQ(sln.searchInsert(nums, 2), 4);
    ASSERT_EQ(sln.searchInsert(nums, 7), 4);
    ASSERT_EQ(sln.searchInsert(nums, 0), 0);
}

GTEST_MAIN
