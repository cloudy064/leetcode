//
// Created by cloudy064 on 2019/4/8.
//

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/search-a-2d-matrix/

/*
hint:
Binary search.

Index is denoted by row and column.

Index = r * column + c;
*/

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty()) return false;

		int row = matrix.size();
		int col = matrix[0].size();

		int c = row * col;

		if (matrix[0][0] > target) return false;

		if (matrix[row - 1][col - 1] < target) return false;

		int min = 0;
		int max = c - 1;

		while (min <= max) {
			int mid = (min + max) / 2;

			int i = mid / col;
			int j = mid % col;
			
			if (matrix[i][j] == target) return true;

			if (matrix[i][j] > target) {
				max = mid - 1;
			} else {
				min = mid + 1;
			}
		}

		return false;
	}
};

class Test074Solution : public ::testing::Test {
public:
	Solution sln;
};

TEST_F(Test074Solution, t1) {
	vector<vector<int>> matrix = {
		{1,2,3},
	{5,6,7},
	{9,9,10}
	};

	EXPECT_TRUE(sln.searchMatrix(matrix, 1));
	EXPECT_TRUE(sln.searchMatrix(matrix, 2));
	EXPECT_TRUE(sln.searchMatrix(matrix, 3));
	EXPECT_FALSE(sln.searchMatrix(matrix, 4));
	EXPECT_TRUE(sln.searchMatrix(matrix, 5));
	EXPECT_TRUE(sln.searchMatrix(matrix, 6));
	EXPECT_TRUE(sln.searchMatrix(matrix, 7));
	EXPECT_FALSE(sln.searchMatrix(matrix, 8));
	EXPECT_TRUE(sln.searchMatrix(matrix, 9));
	EXPECT_TRUE(sln.searchMatrix(matrix, 10));
	EXPECT_FALSE(sln.searchMatrix(matrix, 11));
}

TEST_F(Test074Solution, t2) {
	vector<vector<int>> matrix = {
		
	};

	EXPECT_FALSE(sln.searchMatrix(matrix, 1));
	EXPECT_FALSE(sln.searchMatrix(matrix, 2));
	EXPECT_FALSE(sln.searchMatrix(matrix, 3));
	EXPECT_FALSE(sln.searchMatrix(matrix, 4));
	EXPECT_FALSE(sln.searchMatrix(matrix, 5));
	EXPECT_FALSE(sln.searchMatrix(matrix, 6));
	EXPECT_FALSE(sln.searchMatrix(matrix, 7));
	EXPECT_FALSE(sln.searchMatrix(matrix, 8));
	EXPECT_FALSE(sln.searchMatrix(matrix, 9));
	EXPECT_FALSE(sln.searchMatrix(matrix, 10));
	EXPECT_FALSE(sln.searchMatrix(matrix, 11));
}

TEST_F(Test074Solution, t3) {
	vector<vector<int>> matrix = {
		{}
	};

	EXPECT_FALSE(sln.searchMatrix(matrix, 1));
	EXPECT_FALSE(sln.searchMatrix(matrix, 2));
	EXPECT_FALSE(sln.searchMatrix(matrix, 3));
	EXPECT_FALSE(sln.searchMatrix(matrix, 4));
	EXPECT_FALSE(sln.searchMatrix(matrix, 5));
	EXPECT_FALSE(sln.searchMatrix(matrix, 6));
	EXPECT_FALSE(sln.searchMatrix(matrix, 7));
	EXPECT_FALSE(sln.searchMatrix(matrix, 8));
	EXPECT_FALSE(sln.searchMatrix(matrix, 9));
	EXPECT_FALSE(sln.searchMatrix(matrix, 10));
	EXPECT_FALSE(sln.searchMatrix(matrix, 11));
}

TEST_F(Test074Solution, t4) {
	vector<vector<int>> matrix = {
		{1},
	{5},
	{9}
	};

	EXPECT_TRUE(sln.searchMatrix(matrix, 1));
	EXPECT_FALSE(sln.searchMatrix(matrix, 2));
	EXPECT_FALSE(sln.searchMatrix(matrix, 3));
	EXPECT_FALSE(sln.searchMatrix(matrix, 4));
	EXPECT_TRUE(sln.searchMatrix(matrix, 5));
	EXPECT_FALSE(sln.searchMatrix(matrix, 6));
	EXPECT_FALSE(sln.searchMatrix(matrix, 7));
	EXPECT_FALSE(sln.searchMatrix(matrix, 8));
	EXPECT_TRUE(sln.searchMatrix(matrix, 9));
	EXPECT_FALSE(sln.searchMatrix(matrix, 10));
	EXPECT_FALSE(sln.searchMatrix(matrix, 11));
}

GTEST_MAIN
