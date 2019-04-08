//
// Created by cloudy064 on 2019/4/8.
//

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/combinations/

class Solution {
public:
	inline int element(int index) {
		return index + 1;
	}

	void pickElement(int size, int skip, int takes, vector<int>& temp, vector<vector<int>>& result) {
		if (skip + takes > size) return;

		if (skip + takes == size) {
			for (int i = skip; i < size; ++i) {
				temp.push_back(element(i));
			}

			result.emplace_back(temp);
			for (int i = skip; i < size; ++i) {
				temp.pop_back();
			}

			return;
		}

		if (takes == 1) {
			for (int i = skip; i < size; ++i) {
				temp.push_back(element(i));
				result.emplace_back(temp);
				temp.pop_back();
			}

			return;
		}

		// take current element
		int num = element(skip);
		temp.push_back(num);
		pickElement(size, skip + 1, takes - 1, temp, result);
		
		// don't take current element
		temp.pop_back();
		pickElement(size, skip + 1, takes, temp, result);
	}

	vector<vector<int>> combine(int n, int k) {
		if (k > n || k == 0) return {};

		vector<int> temp;
		vector<vector<int>> result;
		pickElement(n, 0, k, temp, result);
		return result;
	}
};

class Test077Solution : public ::testing::Test {
public:
	Solution sln;
};

TEST_F(Test077Solution, t1) {
	vector<vector<int>> expect = {
		{2, 4},
	{3, 4},
	{2, 3},
	{1, 2},
	{1, 3},
	{1, 4}
	};

	auto result = sln.combine(4, 2);

	sort(expect.begin(), expect.end());
	sort(result.begin(), result.end());

	EXPECT_EQ(result, expect);
}

TEST_F(Test077Solution, t2) {
	vector<vector<int>> expect = {
	};

	auto result = sln.combine(4, 5);

	sort(expect.begin(), expect.end());
	sort(result.begin(), result.end());

	EXPECT_EQ(result, expect);
}

TEST_F(Test077Solution, t3) {
	vector<vector<int>> expect = {
	};

	auto result = sln.combine(0, 0);

	sort(expect.begin(), expect.end());
	sort(result.begin(), result.end());

	EXPECT_EQ(result, expect);
}

TEST_F(Test077Solution, t4) {
	vector<vector<int>> expect = {
		{1}, {2}, {3}, {4}, {5}
	};

	auto result = sln.combine(5, 1);

	sort(expect.begin(), expect.end());
	sort(result.begin(), result.end());

	EXPECT_EQ(result, expect);
}

TEST_F(Test077Solution, t5) {
	vector<vector<int>> expect = {
		{1, 2, 3, 4, 5}
	};

	auto result = sln.combine(5, 5);

	sort(expect.begin(), expect.end());
	sort(result.begin(), result.end());

	EXPECT_EQ(result, expect);
}

GTEST_MAIN
