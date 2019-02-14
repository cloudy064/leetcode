//
// Created by cloudy064 on 2018/7/20.
//

#include <vector>

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int minOffset(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) {
            return 0;
        }

        if (nums[size - 1] > nums[0]) return 0;

        int left = 0;
        int right = size - 1;
        int mid = (left + right) / 2;

        while (left <= right) {
            mid = (left + right) / 2;
            int next = (mid + 1) % size;
            if (nums[mid] > nums[next]) break;

            if (nums[mid] >= nums[0]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return (mid + 1) % size;
    }

    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;

        int size = nums.size();
        int offset = minOffset(nums);
        if (nums[(0 + offset) % size] > target) return -1;
        if (nums[(size + offset - 1) % size] < target) return -1;

        int left = 0;
        int right = size - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            int index = (mid + offset) % size;
            if (nums[index] == target) {
                return index;
            }
            else if (nums[index] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return -1;
    }
};

class Test033Solution : public ::testing::Test {
public:
	Solution sln;
};

TEST_F(Test033Solution, testOffset)
{
    vector<int> nums = {0,1,2,3};
    ASSERT_EQ(sln.minOffset(nums), 0);

    nums = {1,2,3,0};
    ASSERT_EQ(sln.minOffset(nums), 3);

    nums = {2,3,0,1};
    ASSERT_EQ(sln.minOffset(nums), 2);

    nums = {3,0,1,2};
    ASSERT_EQ(sln.minOffset(nums), 1);

    nums = {0,1,2};
    ASSERT_EQ(sln.minOffset(nums), 0);

    nums = {1,2,0};
    ASSERT_EQ(sln.minOffset(nums), 2);

    nums = {2,0,1};
    ASSERT_EQ(sln.minOffset(nums), 1);

    nums = {3};
    ASSERT_EQ(sln.minOffset(nums), 0);

    nums = {1,3};
    ASSERT_EQ(sln.minOffset(nums), 0);

    nums = {3,1};
    ASSERT_EQ(sln.minOffset(nums), 1);
}

TEST_F(Test033Solution, t1) {
    vector<int> nums = {0,1,2,3};
    ASSERT_EQ(sln.search(nums, 0), 0);
    ASSERT_EQ(sln.search(nums, 1), 1);
    ASSERT_EQ(sln.search(nums, 2), 2);
    ASSERT_EQ(sln.search(nums, 3), 3);
    ASSERT_EQ(sln.search(nums, 4), -1);
}

TEST_F(Test033Solution, t2) {
    vector<int> nums = {0,1,2,3,4};
    ASSERT_EQ(sln.search(nums, 0), 0);
    ASSERT_EQ(sln.search(nums, 1), 1);
    ASSERT_EQ(sln.search(nums, 2), 2);
    ASSERT_EQ(sln.search(nums, 3), 3);
    ASSERT_EQ(sln.search(nums, 4), 4);
    ASSERT_EQ(sln.search(nums, 5), -1);
}

TEST_F(Test033Solution, t3) {
    vector<int> nums = {4,5,6,7,0,1,2};
    ASSERT_EQ(sln.minOffset(nums), 4);
    ASSERT_EQ(sln.search(nums, 0), 4);

    nums = {4,5,1,2,3};
    ASSERT_EQ(sln.minOffset(nums), 2);
    ASSERT_EQ(sln.search(nums, 1), 2);

    nums = {4,5,6,1,2,3};
    ASSERT_EQ(sln.minOffset(nums), 3);
    ASSERT_EQ(sln.search(nums, 1), 3);
}

GTEST_MAIN
