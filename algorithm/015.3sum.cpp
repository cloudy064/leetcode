//
// Created by cloudy064 on 2018/6/21.
//


#include <algorithm>
#include <unordered_map>
#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/3sum/description/

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		int size = nums.size();
		if (size < 3) return {};

		sort(nums.begin(), nums.end());
		vector<vector<int>> result;
		int i = 0;
		while (i < size - 2)
		{
			int j = i + 1;
			int k = size - 1;
			int target = nums[i];
			while (j < k)
			{
				int left = nums[j];
				int right = nums[k];
				int sum = left + right;
				if (sum == -target)
				{
					result.push_back({nums[i], nums[j], nums[k]});
				}

				if (sum <= -target)
				{
					for (++j; (j < k) && (nums[j] == left) && (nums[j] != right); ++j);
				} else
				{
					for (--k; (j < k) && (nums[k] == right) && (nums[k] != left); --k);
				}

                if (left == right) break;
			}

			for (++i; (i < size - 2) && (nums[i] == target); ++i);
		}

		return result;
	}
};

class Test015Solution : public ::testing::Test {
public:
	Solution sln;
};

TEST_F(Test015Solution, t1)
{
	vector<int> nums = { -1, 0, 1, 2, -1, -4 };
	auto result = sln.threeSum(nums);
	vector<vector<int>> expect = {{-1, -1, 2}, {-1, 0, 1}};
	EXPECT_EQ(expect, result);
}

TEST_F(Test015Solution, t2)
{
    vector<int> nums = { 0, 0, 0 };
    auto result = sln.threeSum(nums);
    vector<vector<int>> expect = {{0, 0, 0}};
    EXPECT_EQ(expect, result);
}

TEST_F(Test015Solution, t3)
{
    vector<int> nums = { 0, 0 };
    auto result = sln.threeSum(nums);
    vector<vector<int>> expect = {};
    EXPECT_EQ(expect, result);
}

TEST_F(Test015Solution, t4)
{
    vector<int> nums = { 1, 2, 3, 4 };
    auto result = sln.threeSum(nums);
    vector<vector<int>> expect = {};
    EXPECT_EQ(expect, result);
}


TEST_F(Test015Solution, t5)
{
    vector<int> nums = { -1, -2, -3, -4 };
    auto result = sln.threeSum(nums);
    vector<vector<int>> expect = {};
    EXPECT_EQ(expect, result);
}

TEST_F(Test015Solution, t6)
{
    vector<int> nums = { -1, -2, 4 };
    auto result = sln.threeSum(nums);
    vector<vector<int>> expect = {};
    EXPECT_EQ(expect, result);
}

GTEST_MAIN