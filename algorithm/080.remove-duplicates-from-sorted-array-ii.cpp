//
// Created by cloudy064 on 2019/4/9.
//

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int size = nums.size();
		if (size <= 1) return size;

		int length = 1;
		int current = nums[0];
		int count = 1;
		
		for (int i = 1; i < size; i++) {
			if (nums[i] == current) {
				count++;
				if (length != i && nums[length] != nums[i]) {
					swap(nums[length], nums[i]);
				}

				if (count <= 2) {
					length++;
				} 
			}
			else {
				current = nums[i];
				count = 1;
				if (length != i) {
					swap(nums[length], nums[i]);
				}

				length++;
			}
		}

		return length;
	}
};

class Test080Solution : public ::testing::Test {
public:
	Solution sln2;
};

TEST_F(Test080Solution, t1) {
	vector<int> nums = { 0,0,1,1,1,1,2,3,3 };
	vector<int> expect = { 0, 0, 1, 1, 2, 3, 3 };

	EXPECT_EQ(sln2.removeDuplicates(nums), expect.size());
	for (int i = 0; i < expect.size(); i++) {
		EXPECT_EQ(expect[i], nums[i]);
	}
}

TEST_F(Test080Solution, t2) {
	vector<int> nums = { 0,0,1,1,1,1,2,3,3 };
	vector<int> expect = { 0, 0, 1, 1, 2, 3, 3 };

	EXPECT_EQ(sln2.removeDuplicates(nums), expect.size());
	for (int i = 0; i < expect.size(); i++) {
		EXPECT_EQ(expect[i], nums[i]);
	}
}

TEST_F(Test080Solution, t3) {
	vector<int> nums = { 0,0,0,0,0,0,0,0 };
	vector<int> expect = { 0, 0 };

	EXPECT_EQ(sln2.removeDuplicates(nums), expect.size());
	for (int i = 0; i < expect.size(); i++) {
		EXPECT_EQ(expect[i], nums[i]);
	}
}

TEST_F(Test080Solution, t4) {
	vector<int> nums = { 1,2,3,4,5,6,7,8 };
	vector<int> expect = { 1,2,3,4,5,6,7,8 };

	EXPECT_EQ(sln2.removeDuplicates(nums), expect.size());
	for (int i = 0; i < expect.size(); i++) {
		EXPECT_EQ(expect[i], nums[i]);
	}
}

TEST_F(Test080Solution, t5) {
	vector<int> nums = { 1,1,2,2,3,3,4,4 };
	vector<int> expect = { 1,1,2,2,3,3,4,4 };

	EXPECT_EQ(sln2.removeDuplicates(nums), expect.size());
	for (int i = 0; i < expect.size(); i++) {
		EXPECT_EQ(expect[i], nums[i]);
	}
}

GTEST_MAIN
