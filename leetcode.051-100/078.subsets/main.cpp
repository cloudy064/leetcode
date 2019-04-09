//
// Created by cloudy064 on 2019/4/8.
//

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/subsets/

class Solution {
public:
	void pickElement(vector<int>& nums, int skip, int takes, vector<int>& temp, vector<vector<int>>& result) {
		int size = nums.size();
		if (skip + takes > size) return;

		if (skip + takes == size) {
			for (int i = skip; i < size; ++i) {
				temp.push_back(nums[i]);
			}

			result.emplace_back(temp);
			for (int i = skip; i < size; ++i) {
				temp.pop_back();
			}

			return;
		}

		if (takes == 1) {
			for (int i = skip; i < size; ++i) {
				temp.push_back(nums[i]);
				result.emplace_back(temp);
				temp.pop_back();
			}

			return;
		}

		// take current element
		int num = nums[skip];
		temp.push_back(num);
		pickElement(nums, skip + 1, takes - 1, temp, result);

		// don't take current element
		temp.pop_back();
		pickElement(nums, skip + 1, takes, temp, result);
	}

	vector<vector<int>> subsets(vector<int>& nums) {
		if (nums.empty()) return { {} };

		vector<int> temp;
		vector<vector<int>> result;

		result.push_back({});
		result.emplace_back(nums);

		int size = nums.size();
		for (int i = 1; i < size; i++) {
			temp.clear();
			pickElement(nums, 0, i, temp, result);
		}

		return result;
	}
};

class Test078Solution : public ::testing::Test {
public:
	Solution sln;
};

TEST_F(Test078Solution, t1) {
	vector<vector<int>> expect = {
		{3},
	{1},
	{2},
	{1,2,3},
	{1,3},
	{1,2},
	{2,3},
	{}
	};

	vector<int> nums = { 1,2,3 };
	auto result = sln.subsets(nums);

	sort(expect.begin(), expect.end());
	sort(result.begin(), result.end());

	EXPECT_EQ(result, expect);
}

TEST_F(Test078Solution, t2) {
	vector<vector<int>> expect = {
	{}
	};

	vector<int> nums = { };
	auto result = sln.subsets(nums);

	sort(expect.begin(), expect.end());
	sort(result.begin(), result.end());

	EXPECT_EQ(result, expect);
}

TEST_F(Test078Solution, t3) {
	vector<vector<int>> expect = {
	{1},
	{}
	};

	vector<int> nums = {1 };
	auto result = sln.subsets(nums);

	sort(expect.begin(), expect.end());
	sort(result.begin(), result.end());

	EXPECT_EQ(result, expect);
}

TEST_F(Test078Solution, t4) {
	vector<vector<int>> expect = {
	{},
	{6},
	{5},
	{5,6},
	{3},
	{3,6},
	{3,5},
	{3,5,6},
	{2},
	{2,6},
	{2,5},
	{2,5,6},
	{2,3},
	{2,3,6},
	{2,3,5},
	{2,3,5,6},
	{1},
	{1,6},
	{1,5},
	{1,5,6},
	{1,3},
	{1,3,6},
	{1,3,5},
	{1,3,5,6},
	{1,2},
	{1,2,6},
	{1,2,5},
	{1,2,5,6},
	{1,2,3},
	{1,2,3,6},
	{1,2,3,5},
	{1,2,3,5,6}
	};

	vector<int> nums = { 1,2,3,5,6 };
	auto result = sln.subsets(nums);

	sort(expect.begin(), expect.end());
	sort(result.begin(), result.end());

	EXPECT_EQ(result, expect);
}


GTEST_MAIN
