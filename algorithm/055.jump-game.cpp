//
// Created by cloudy064 on 2019/2/21.
//

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/jump-game/


class Solution {
public:
	bool canJump(vector<int>& nums) {
		int size = nums.size();
		if (size <= 1) return true;

		int maxStep = 0;
		for (int i = 0; i < size; i++)
		{
			if (i > maxStep) return false;

			if (nums[i] + i > maxStep)
			{
				maxStep = nums[i] + i;
			}

			if (maxStep >= size) break;
		}

		return true;
	}
};

class Test055Solution : public ::testing::Test {
public:
	Solution sln;
};

TEST_F(Test055Solution, t1) {
	vector<int> nums = { 2,3,1,1,4 };

	EXPECT_EQ(sln.canJump(nums), true);
}

TEST_F(Test055Solution, t2) {
	vector<int> nums = { 3,2,1,0,4 };

	EXPECT_EQ(sln.canJump(nums), false);
}

GTEST_MAIN