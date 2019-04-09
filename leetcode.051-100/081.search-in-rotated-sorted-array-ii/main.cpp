//
// Created by cloudy064 on 2019/4/9.
//

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/

/*
hints:

Binary search.
Find the first element index.
*/

class Solution {
public:
	inline int element(vector<int>& nums, int i, int offset) {
		int index = (offset + i) % nums.size();
		return nums[index];
	}

	bool search(vector<int>& nums, int target) {
		if (nums.empty()) return false;

		int size = nums.size();

		int i = 0;

		while (i < size - 1 && nums[i] <= nums[i + 1]) i++;

		int offset = (i + 1) % size;

		int min = 0;
		int max = size - 1;

		while (min <= max) {
			int mid = (min + max) / 2;

			int midEle = element(nums, mid, offset);

			if (midEle == target) return true;

			if (midEle > target) max = mid - 1;
			else min = mid + 1;
		}

		return false;
	}
};

class TestSolution : public ::testing::Test {
public:
	Solution sln;
};

TEST_F(TestSolution, t1) {
	vector<int> nums = { 0,0,1,1,1,1,2,3,3 };
	EXPECT_TRUE(sln.search(nums, 0));
	EXPECT_TRUE(sln.search(nums, 1));
	EXPECT_TRUE(sln.search(nums, 2));
	EXPECT_TRUE(sln.search(nums, 3));
	EXPECT_FALSE(sln.search(nums, 4));
}

TEST_F(TestSolution, t2) {
	vector<int> nums = { 2,5,6,0,0,1,2 };
	EXPECT_TRUE(sln.search(nums, 0));
	EXPECT_TRUE(sln.search(nums, 1));
	EXPECT_TRUE(sln.search(nums, 2));
	EXPECT_FALSE(sln.search(nums, 3));
	EXPECT_FALSE(sln.search(nums, 4));
	EXPECT_TRUE(sln.search(nums, 5));
	EXPECT_TRUE(sln.search(nums, 6));
}

TEST_F(TestSolution, t3) {
	vector<int> nums = { };
	EXPECT_FALSE(sln.search(nums, 0));
	EXPECT_FALSE(sln.search(nums, 1));
	EXPECT_FALSE(sln.search(nums, 2));
	EXPECT_FALSE(sln.search(nums, 3));
	EXPECT_FALSE(sln.search(nums, 4));
	EXPECT_FALSE(sln.search(nums, 5));
	EXPECT_FALSE(sln.search(nums, 6));
}

TEST_F(TestSolution, t4) {
	vector<int> nums = { 1};
	EXPECT_FALSE(sln.search(nums, 0));
	EXPECT_TRUE(sln.search(nums, 1));
	EXPECT_FALSE(sln.search(nums, 2));
	EXPECT_FALSE(sln.search(nums, 3));
	EXPECT_FALSE(sln.search(nums, 4));
	EXPECT_FALSE(sln.search(nums, 5));
	EXPECT_FALSE(sln.search(nums, 6));
}

GTEST_MAIN
