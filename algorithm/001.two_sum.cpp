//
// Created by cloudy064 on 2018/6/17.
//

#include <iostream>
#include <vector>
#include <unordered_map>

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/two-sum/description/

class Solution {
public:
	vector<int> twoSum(vector<int> &nums, int target) {
		unordered_map<int, int> map;

		for (int i = 0; i < nums.size(); ++i) {
			map[nums[i]] = i;
		}

		for (int i = 0; i < nums.size(); ++i) {
			int j = target - nums[i];
			auto it = map.find(j);
			if (it != map.end() && it->second != i) {
				return { i , it->second };
			}
		}

		return { 0, 0 };
	}
};

class Test001Solution : public ::testing::Test {
public:
	Solution sln;
};

TEST_F(Test001Solution, t1) {
	vector<int> nums = { 0, 1, 2, 3, 4, 5 };
	vector<int> result = sln.twoSum(nums, 8);
	vector<int> expect = { 3, 5 };
	ASSERT_EQ(result, expect);
}

TEST_F(Test001Solution, t2) {
	vector<int> nums = { 3, 9, 1, 4, 10, 7 };
	vector<int> result = sln.twoSum(nums, 16);
	vector<int> expect = { 1, 5 };
	ASSERT_EQ(result, expect);
}

TEST_F(Test001Solution, t3) {
	vector<int> nums = { 3, 2, 4 };
	vector<int> result = sln.twoSum(nums, 6);
	vector<int> expect = { 1, 2 };
	ASSERT_EQ(result, expect);
}

GTEST_MAIN