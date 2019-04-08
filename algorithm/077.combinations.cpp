//
// Created by cloudy064 on 2019/4/8.
//

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/combinations/

class Solution {
public:
	vector<vector<int>> pickElement(int size, int skip, int takes) {
		if (skip + takes > size) return {};

		if (skip + takes == size) {
			vector<int> temp;
			for (int i = skip; i < size; ++i) {
				temp.push_back(i + 1);
			}

			return { temp };
		}

		if (takes == 1) {
			vector<vector<int>> result;
			for (int i = skip; i < size; ++i) {
				result.push_back({ i + 1 });
			}

			return result;
		}

		vector<vector<int>> result;

		int num = skip + 1;
		auto temp = pickElement(size, skip + 1, takes - 1);
		vector<int> item;
		for (auto t : temp) {
			item.clear();
			item.push_back(num);
			item.insert(item.end(), t.begin(), t.end());
			result.emplace_back(item);
		}

		temp = pickElement(size, skip + 1, takes);
		for (auto t : temp) result.emplace_back(t);

		return result;
	}

	vector<vector<int>> combine(int n, int k) {
		if (k > n || k == 0) return {};

		return pickElement(n, 0, k);
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
