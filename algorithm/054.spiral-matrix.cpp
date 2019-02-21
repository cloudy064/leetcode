//
// Created by ≥£”¿‘≈ on 2019/2/21.
//

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/spiral-matrix/


class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.empty()) return {};
		if (matrix[0].empty()) return {};

		int m = matrix.size();
		int n = matrix[0].size();

		auto total = m * n;
		auto count = 0;
		int round = 0;
		
		vector<int> result;
		int i = 0, j = 0;
		while (count < total)
		{
			int mod = round % 4;
			int div = round / 4;
			switch (mod)
			{
			case 0:
				while (i < n - div) {
					result.emplace_back(matrix[j][i++]);
					++count;
				}
				--i;
				++j;
				break;

			case 1:
				while (j < m - div)
				{
					result.emplace_back(matrix[j++][i]);
					++count;
				}
				--i;
				--j;
				break;

			case 2:
				while (i >= div)
				{
					result.emplace_back(matrix[j][i--]);
					++count;
				}
				++i;
				--j;
				break;
			default: //case 3:
				while (j > div)
				{
					result.emplace_back(matrix[j--][i]);
					++count;
				}
				++i;
				++j;
				break;
			}

			++round;
		}

		return result;
	}
};

class Test054Solution : public ::testing::Test {
public:
	Solution sln;
};

TEST_F(Test054Solution, t1) {
	vector<vector<int>> nums = { 
		{1,2,3}, {4,5,6}, {7,8,9}
	};

	EXPECT_EQ(sln.spiralOrder(nums), vector<int>({1,2,3,6,9,8,7,4,5}));
}

TEST_F(Test054Solution, t2) {
	vector<vector<int>> nums = {
		{1,2,3, 4}, {5,6,7,8}, {9,10,11,12}
	};

	EXPECT_EQ(sln.spiralOrder(nums), vector<int>({ 1,2,3,4,8,12,11,10,9,5,6,7 }));
}

TEST_F(Test054Solution, t3) {
	vector<vector<int>> nums = {
		{}, {}, {}
	};

	EXPECT_EQ(sln.spiralOrder(nums), vector<int>({  }));
}

TEST_F(Test054Solution, t4) {
	vector<vector<int>> nums = {
	
	};

	EXPECT_EQ(sln.spiralOrder(nums), vector<int>({  }));
}

TEST_F(Test054Solution, t5) {
	vector<vector<int>> nums = {
		{1,2,3,4,5,6}
	};

	EXPECT_EQ(sln.spiralOrder(nums), vector<int>({ 1,2,3,4,5,6 }));
}

TEST_F(Test054Solution, t6) {
	vector<vector<int>> nums = {
		{1},{2},{3},{4},{5},{6} 
	};

	EXPECT_EQ(sln.spiralOrder(nums), vector<int>({ 1,2,3,4,5,6 }));
}


GTEST_MAIN