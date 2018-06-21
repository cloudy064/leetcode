//
// Created by cloudy064 on 2018/6/21.
//


#include <algorithm>
#include <unordered_map>
#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/3sum-closest/description/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();

        sort(nums.begin(), nums.end());
        int closest = 0;
        int closest_diff = 0;
        bool init = false;
        vector<vector<int>> result;
        int i = 0;
        while (i < size - 2)
        {
            int j = i + 1;
            int k = size - 1;
            int first = nums[i];
            while (j < k)
            {
                int left = nums[j];
                int right = nums[k];
                int sum = left + right + first;
                int diff = abs(sum - target);
                if (diff == 0) return sum;

                if (closest_diff > diff || !init) {
                    closest_diff = diff;
                    closest = sum;
                    init = true;
                }

                if (left == right) break;

                if (sum < target)
                {
                    for (++j; (j < k) && (nums[j] == left) && (nums[j] != right); ++j);
                } else
                {
                    for (--k; (j < k) && (nums[k] == right) && (nums[k] != left); --k);
                }

            }

            for (++i; (i < size - 2) && (nums[i] == first); ++i);
        }

        return closest;
    }
};

class Test016Solution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(Test016Solution, t1)
{
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    ASSERT_EQ(2, sln.threeSumClosest(nums, target));
}

TEST_F(Test016Solution, t2)
{
    vector<int> nums = {1, 2, 3, 4};
    int target = 1;
    ASSERT_EQ(6, sln.threeSumClosest(nums, target));
}

TEST_F(Test016Solution, t3)
{
    vector<int> nums = {-1, -2, -3, -4};
    int target = 1;
    ASSERT_EQ(-6, sln.threeSumClosest(nums, target));
}

TEST_F(Test016Solution, t4)
{
    vector<int> nums = {-1, 2, 0, -4};
    int target = 1;
    ASSERT_EQ(1, sln.threeSumClosest(nums, target));
}

GTEST_MAIN