//
// Created by cloudy064 on 2019/2/19.
//

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/next-permutation/

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int length = nums.size();
		if (length <= 0) return;

		int i = length - 2;
		auto iterator = nums.end() - 1;
		for (; i >= 0; --i, --iterator) {
			if (nums[i] < nums[i + 1]) break;
		}

		if (i == -1) {
			sort(nums.begin(), nums.end());
		}
		else {
			int j = length - 1;
			for (; j >= i; --j) {
				if (nums[j] > nums[i]) break;
			}

			int temp = nums[j];
			nums[j] = nums[i];
			nums[i] = temp;

			sort(iterator, nums.end());
		}
	}
};

class TestSolution : public ::testing::Test {
public:
	Solution sln;
};

TEST_F(TestSolution, t1) {
	vector<int> nums = { 1,2,3 };
	sln.nextPermutation(nums);
	vector<int> expect = { 1,3,2 };
	EXPECT_EQ(nums, expect);
}

GTEST_MAIN