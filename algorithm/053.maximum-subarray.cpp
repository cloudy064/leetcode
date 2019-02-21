//
// Created by ≥£”¿‘≈ on 2019/2/21.
//

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/maximum-subarray/


class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.empty()) return 0;

		int max = nums[0];
		int sum = 0;
		for (auto i : nums)
		{
			if (sum > 0)
			{
				sum += i;
			}
			else
			{
				sum = i;
			}

			if (sum > max) max = sum;
		}

		return max;
	}
};

class Test053Solution : public ::testing::Test {
public:
	Solution sln;
};

TEST_F(Test053Solution, t1) {
	vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };

	EXPECT_EQ(sln.maxSubArray(nums), 6);
}

TEST_F(Test053Solution, t2) {
	vector<int> nums = { -2, -1, -3, -5};

	EXPECT_EQ(sln.maxSubArray(nums), -1);
}

TEST_F(Test053Solution, t3) {
	vector<int> nums = { 1,2,3,4 };

	EXPECT_EQ(sln.maxSubArray(nums), 10);
}

GTEST_MAIN