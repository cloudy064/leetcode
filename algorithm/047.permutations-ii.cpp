//
// Created by ≥£”¿‘≈ on 2019/2/18.
//

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/permutations-ii/


class Solution {
public:
	vector<vector<int>> permuteImpl(vector<int>& nums) const
	{
		vector<vector<int>> result;
		if (nums.size() == 2)
		{
			result.push_back(nums);
			if (nums[0] != nums[1]) {
				swap(nums[0], nums[1]);
				result.push_back(nums);
			}

			return result;
		}

		auto last = nums.back();
		nums.pop_back();
		auto temp = permuteImpl(nums);

		for (auto item : temp)
		{
			const int size = item.size();
			item.push_back(last);
			result.push_back(item);
			for (int i = 0; i < size; i++)
			{
				if (item[size - i] == item[size - i - 1]) break;

				swap(item[size - i], item[size - i - 1]);
				result.push_back(item);
			}
		}

		return result;
	}

	vector<vector<int>> permuteUnique(vector<int>& nums) {
		if (nums.empty()) return {};

		const int size = nums.size();
		if (size == 1)
		{
			vector<vector<int>> result;
			result.emplace_back(nums);
			return result;
		}

		return this->permuteImpl(nums);
	}
};

class Test047Solution : public ::testing::Test {
public:
	Solution sln;
};

TEST_F(Test047Solution, t1) {
	vector<int> nums = {};
	auto result = sln.permuteUnique(nums);
	vector<vector<int>> expect = {};
	sort(result.begin(), result.end());
	sort(expect.begin(), expect.end());

	EXPECT_EQ(result, expect);
}

TEST_F(Test047Solution, t2) {
	vector<int> nums = { 1 };
	auto result = sln.permuteUnique(nums);
	vector<vector<int>> expect = { {1} };
	sort(result.begin(), result.end());
	sort(expect.begin(), expect.end());

	EXPECT_EQ(result, expect);
}

TEST_F(Test047Solution, t3) {
	vector<int> nums = { 1,2 };
	auto result = sln.permuteUnique(nums);
	vector<vector<int>> expect = { {1,2}, {2,1} };
	sort(result.begin(), result.end());
	sort(expect.begin(), expect.end());

	EXPECT_EQ(result, expect);
}

TEST_F(Test047Solution, t4) {
	vector<int> nums = { 1,2,3 };
	auto result = sln.permuteUnique(nums);
	vector<vector<int>> expect = { {1,2,3},{1,3,2},{2,1,3}, {2,3,1},{3,1,2},{3,2,1} };
	sort(result.begin(), result.end());
	sort(expect.begin(), expect.end());

	EXPECT_EQ(result, expect);
}

TEST_F(Test047Solution, t5) {
	vector<int> nums = { 1,2,3,4 };
	auto result = sln.permuteUnique(nums);
	vector<vector<int>> expect = {
		{1,2,3,4}, {1,2,4,3},
		{1,3,2,4}, {1,3,4,2},
		{1,4,2,3}, {1,4,3,2},
		{2,1,3,4}, {2,1,4,3},
		{2,3,1,4}, {2,3,4,1},
		{2,4,1,3}, {2,4,3,1},
		{3,1,2,4}, {3,1,4,2},
		{3,2,1,4}, {3,2,4,1},
		{3,4,1,2}, {3,4,2,1},
		{4,1,2,3}, {4,1,3,2},
		{4,2,1,3}, {4,2,3,1},
		{4,3,1,2}, {4,3,2,1}
	};

	sort(result.begin(), result.end());
	sort(expect.begin(), expect.end());

	EXPECT_EQ(result, expect);
}

TEST_F(Test047Solution, t6) {
	vector<int> nums = { 1,1,2 };
	auto result = sln.permuteUnique(nums);
	vector<vector<int>> expect = {
		{1,1,2}, {1,2,1}, {2,1,1}
	};

	sort(result.begin(), result.end());
	sort(expect.begin(), expect.end());

	EXPECT_EQ(result, expect);
}

TEST_F(Test047Solution, t7) {
	vector<int> nums = { 1,1,2,2 };
	auto result = sln.permuteUnique(nums);
	vector<vector<int>> expect ={ 
		{1, 1, 2, 2},{1, 2, 1, 2},{1, 2, 2, 1},{2, 1, 1, 2},{2, 1, 2, 1},{2, 2, 1, 1}
	};

	sort(result.begin(), result.end());
	sort(expect.begin(), expect.end());

	EXPECT_EQ(result, expect);
}

TEST_F(Test047Solution, t8) {
	vector<int> nums = { 1,1,1,2,2 };
	auto result = sln.permuteUnique(nums);
	vector<vector<int>> expect = { {1,1,1,2,2},{1,1,2,1,2},{1,1,2,2,1},{1,2,1,1,2},{1,2,1,2,1},{1,2,2,1,1},{2,1,1,1,2},{2,1,1,2,1},{2,1,2,1,1},{2,2,1,1,1} };

	sort(result.begin(), result.end());
	sort(expect.begin(), expect.end());

	EXPECT_EQ(result, expect);
}

TEST_F(Test047Solution, t9)
{
	vector<int> nums = { 1,1,1,2,2,3,3 };
	auto result = sln.permuteUnique(nums);
	vector<vector<int>> expect = { {1,1,1,2,2,3,3},{1,1,1,2,3,2,3},{1,1,1,2,3,3,2},{1,1,1,3,2,2,3},{1,1,1,3,2,3,2},{1,1,1,3,3,2,2},{1,1,3,1,2,2,3},{1,1,3,1,2,3,2},{1,1,3,1,3,2,2},{1,1,3,3,1,2,2},{1,3,1,1,2,2,3},{1,3,1,1,2,3,2},{1,3,1,1,3,2,2},{1,3,1,3,1,2,2},{1,3,3,1,1,2,2},{3,1,1,1,2,2,3},{3,1,1,1,2,3,2},{3,1,1,1,3,2,2},{3,1,1,3,1,2,2},{3,1,3,1,1,2,2},{3,3,1,1,1,2,2},{1,1,2,1,2,3,3},{1,1,2,1,3,2,3},{1,1,2,1,3,3,2},{1,1,2,3,1,2,3},{1,1,2,3,1,3,2},{1,1,2,3,3,1,2},{1,1,3,2,1,2,3},{1,1,3,2,1,3,2},{1,1,3,2,3,1,2},{1,1,3,3,2,1,2},{1,3,1,2,1,2,3},{1,3,1,2,1,3,2},{1,3,1,2,3,1,2},{1,3,1,3,2,1,2},{1,3,3,1,2,1,2},{3,1,1,2,1,2,3},{3,1,1,2,1,3,2},{3,1,1,2,3,1,2},{3,1,1,3,2,1,2},{3,1,3,1,2,1,2},{3,3,1,1,2,1,2},{1,1,2,2,1,3,3},{1,1,2,2,3,1,3},{1,1,2,2,3,3,1},{1,1,2,3,2,1,3},{1,1,2,3,2,3,1},{1,1,2,3,3,2,1},{1,1,3,2,2,1,3},{1,1,3,2,2,3,1},{1,1,3,2,3,2,1},{1,1,3,3,2,2,1},{1,3,1,2,2,1,3},{1,3,1,2,2,3,1},{1,3,1,2,3,2,1},{1,3,1,3,2,2,1},{1,3,3,1,2,2,1},{3,1,1,2,2,1,3},{3,1,1,2,2,3,1},{3,1,1,2,3,2,1},{3,1,1,3,2,2,1},{3,1,3,1,2,2,1},{3,3,1,1,2,2,1},{1,2,1,1,2,3,3},{1,2,1,1,3,2,3},{1,2,1,1,3,3,2},{1,2,1,3,1,2,3},{1,2,1,3,1,3,2},{1,2,1,3,3,1,2},{1,2,3,1,1,2,3},{1,2,3,1,1,3,2},{1,2,3,1,3,1,2},{1,2,3,3,1,1,2},{1,3,2,1,1,2,3},{1,3,2,1,1,3,2},{1,3,2,1,3,1,2},{1,3,2,3,1,1,2},{1,3,3,2,1,1,2},{3,1,2,1,1,2,3},{3,1,2,1,1,3,2},{3,1,2,1,3,1,2},{3,1,2,3,1,1,2},{3,1,3,2,1,1,2},{3,3,1,2,1,1,2},{1,2,1,2,1,3,3},{1,2,1,2,3,1,3},{1,2,1,2,3,3,1},{1,2,1,3,2,1,3},{1,2,1,3,2,3,1},{1,2,1,3,3,2,1},{1,2,3,1,2,1,3},{1,2,3,1,2,3,1},{1,2,3,1,3,2,1},{1,2,3,3,1,2,1},{1,3,2,1,2,1,3},{1,3,2,1,2,3,1},{1,3,2,1,3,2,1},{1,3,2,3,1,2,1},{1,3,3,2,1,2,1},{3,1,2,1,2,1,3},{3,1,2,1,2,3,1},{3,1,2,1,3,2,1},{3,1,2,3,1,2,1},{3,1,3,2,1,2,1},{3,3,1,2,1,2,1},{1,2,2,1,1,3,3},{1,2,2,1,3,1,3},{1,2,2,1,3,3,1},{1,2,2,3,1,1,3},{1,2,2,3,1,3,1},{1,2,2,3,3,1,1},{1,2,3,2,1,1,3},{1,2,3,2,1,3,1},{1,2,3,2,3,1,1},{1,2,3,3,2,1,1},{1,3,2,2,1,1,3},{1,3,2,2,1,3,1},{1,3,2,2,3,1,1},{1,3,2,3,2,1,1},{1,3,3,2,2,1,1},{3,1,2,2,1,1,3},{3,1,2,2,1,3,1},{3,1,2,2,3,1,1},{3,1,2,3,2,1,1},{3,1,3,2,2,1,1},{3,3,1,2,2,1,1},{2,1,1,1,2,3,3},{2,1,1,1,3,2,3},{2,1,1,1,3,3,2},{2,1,1,3,1,2,3},{2,1,1,3,1,3,2},{2,1,1,3,3,1,2},{2,1,3,1,1,2,3},{2,1,3,1,1,3,2},{2,1,3,1,3,1,2},{2,1,3,3,1,1,2},{2,3,1,1,1,2,3},{2,3,1,1,1,3,2},{2,3,1,1,3,1,2},{2,3,1,3,1,1,2},{2,3,3,1,1,1,2},{3,2,1,1,1,2,3},{3,2,1,1,1,3,2},{3,2,1,1,3,1,2},{3,2,1,3,1,1,2},{3,2,3,1,1,1,2},{3,3,2,1,1,1,2},{2,1,1,2,1,3,3},{2,1,1,2,3,1,3},{2,1,1,2,3,3,1},{2,1,1,3,2,1,3},{2,1,1,3,2,3,1},{2,1,1,3,3,2,1},{2,1,3,1,2,1,3},{2,1,3,1,2,3,1},{2,1,3,1,3,2,1},{2,1,3,3,1,2,1},{2,3,1,1,2,1,3},{2,3,1,1,2,3,1},{2,3,1,1,3,2,1},{2,3,1,3,1,2,1},{2,3,3,1,1,2,1},{3,2,1,1,2,1,3},{3,2,1,1,2,3,1},{3,2,1,1,3,2,1},{3,2,1,3,1,2,1},{3,2,3,1,1,2,1},{3,3,2,1,1,2,1},{2,1,2,1,1,3,3},{2,1,2,1,3,1,3},{2,1,2,1,3,3,1},{2,1,2,3,1,1,3},{2,1,2,3,1,3,1},{2,1,2,3,3,1,1},{2,1,3,2,1,1,3},{2,1,3,2,1,3,1},{2,1,3,2,3,1,1},{2,1,3,3,2,1,1},{2,3,1,2,1,1,3},{2,3,1,2,1,3,1},{2,3,1,2,3,1,1},{2,3,1,3,2,1,1},{2,3,3,1,2,1,1},{3,2,1,2,1,1,3},{3,2,1,2,1,3,1},{3,2,1,2,3,1,1},{3,2,1,3,2,1,1},{3,2,3,1,2,1,1},{3,3,2,1,2,1,1},{2,2,1,1,1,3,3},{2,2,1,1,3,1,3},{2,2,1,1,3,3,1},{2,2,1,3,1,1,3},{2,2,1,3,1,3,1},{2,2,1,3,3,1,1},{2,2,3,1,1,1,3},{2,2,3,1,1,3,1},{2,2,3,1,3,1,1},{2,2,3,3,1,1,1},{2,3,2,1,1,1,3},{2,3,2,1,1,3,1},{2,3,2,1,3,1,1},{2,3,2,3,1,1,1},{2,3,3,2,1,1,1},{3,2,2,1,1,1,3},{3,2,2,1,1,3,1},{3,2,2,1,3,1,1},{3,2,2,3,1,1,1},{3,2,3,2,1,1,1},{3,3,2,2,1,1,1} };

	sort(result.begin(), result.end());
	sort(expect.begin(), expect.end());

	EXPECT_EQ(result, expect);
}

GTEST_MAIN