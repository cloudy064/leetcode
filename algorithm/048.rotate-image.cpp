//
// Created by ≥£”¿‘≈ on 2019/2/18.
//

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/rotate-image/


class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		if (matrix.empty()) return;

		int size = matrix.size();

		for (int i = 0; i < size / 2; i++)
		{
			for (int j = i; j < size - i - 1; j++)
			{
				int temp = matrix[size - 1 - j][i];
				matrix[size - 1 - j][i] = matrix[size - 1 - i][size - 1 - j];
				matrix[size - 1 - i][size - 1 - j] = matrix[j][size - 1 - i];
				matrix[j][size - 1 - i] = matrix[i][j];
				matrix[i][j] = temp;
			}
		}
	}
};

class Test048Solution : public ::testing::Test {
public:
	Solution sln;
};

TEST_F(Test048Solution, t1) {
	vector<vector<int>> nums = {
		{1,2,3},
	{4,5,6},
	{7,8,9}
	};

	sln.rotate(nums);
	vector<vector<int>> expect = {
		{7,4,1},
	{8,5,2},
	{9,6,3}
	};

	EXPECT_EQ(nums, expect);
}

TEST_F(Test048Solution, t2) {
	vector<vector<int>> nums = {
  { 5, 1, 9,11},
  { 2, 4, 8,10},
  {13, 3, 6, 7},
  {15,14,12,16}
	};

	sln.rotate(nums);
	vector<vector<int>> expect = {
  {15,13, 2, 5},
  {14, 3, 4, 1},
  {12, 6, 8, 9},
  {16, 7,10,11}
	};

	EXPECT_EQ(nums, expect);
}

GTEST_MAIN