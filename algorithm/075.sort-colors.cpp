//
// Created by cloudy064 on 2019/4/8.
//

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/sort-colors/

/*
hints:

Move 0s to the leading position.
Move 2s to the tail position.
The lest is 1s.
*/

class Solution {
public:
	void sortColors(vector<int>& nums) {
		auto size = nums.size();

		int zeroIndex = 0;
		int twoIndex = size - 1;

		int i = 0;
		while (i <= twoIndex) {
			if (nums[i] == 0 && i != zeroIndex) {
				swap(nums[zeroIndex], nums[i]);
				zeroIndex++;
				continue;
			}

			if (nums[i] == 2 && i != twoIndex) {
				swap(nums[twoIndex], nums[i]);
				twoIndex--;
				continue;
			}

			i++;
		}
	}
};

class Test075Solution : public ::testing::Test {
public:
	Solution sln;
};

TEST_F(Test075Solution, t1) {
	vector<int> nums = { 2,0,2,1,1,0 };
	vector<int> expect = { 0,0,1,1,2,2 };
	sln.sortColors(nums);
	EXPECT_EQ(nums, expect);
}

TEST_F(Test075Solution, t2) {
	vector<int> nums = {  };
	vector<int> expect = {  };
	sln.sortColors(nums);
	EXPECT_EQ(nums, expect);
}

TEST_F(Test075Solution, t3) {
	vector<int> nums = { 1 };
	vector<int> expect = { 1 };
	sln.sortColors(nums);
	EXPECT_EQ(nums, expect);
}

TEST_F(Test075Solution, t4) {
	vector<int> nums = { 0 };
	vector<int> expect = { 0 };
	sln.sortColors(nums);
	EXPECT_EQ(nums, expect);
}

TEST_F(Test075Solution, t5) {
	vector<int> nums = { 2 };
	vector<int> expect = { 2 };
	sln.sortColors(nums);
	EXPECT_EQ(nums, expect);
}

GTEST_MAIN
