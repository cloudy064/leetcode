//
// Created by cloudy064 on 2019/4/8.
//

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/set-matrix-zeroes/

/*
hints:
Regardless of the costs, our destination is just marking the rows/cols which contains zero. We can achieve this goal 
with two vectors, with O(m+n) space. 

But, if we want to solve this problem with O(1) space, we can take use of the first row/col in the original matrix, 
as the two vectors mentioned before.

For example, with matrix as below, in which matrix[1][1] is zero:
[
	[1, 1, 1],
	[1, 0, 1],
	[1, 1, 1]
]

We can handle this problem with two phases.

1. In the first phase, we mark matrix[0][1] and matrix[1][0] as 0 and we get:
[
	[1, 0, 1],
	[0, 0, 1],
	[1, 1, 1]
]

2. In the second phase, we just scan the first row/column. Once we get 0, set the whole row/col to 0.

HOWEVER, what if the first row or column contains zero, such as the matrix as below?
[
	[1, 0, 1],
	[1, 1, 1],
	[1, 1, 1]
]

We get a matrix in the first phase
[
	[0, 0, 1],
	[1, 1, 1],
	[1, 1, 1]
]

Obviously, we cannot set the whole first column to zero. 

So! WE HAVE TO HANDLE THE FIRST ROW/COLUMN SEPERATELY, WITH TWO VARIABLES TO MARK IF THE FIRST ROW/COLUMN CONTAINS 0!
*/

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		if (matrix.empty() || matrix[0].empty()) return;

		bool firstRow = false;
		bool firstCol = false;
		
		int row = matrix.size();
		int col = matrix[0].size();
	
		for (auto i = 0; i < row; i++) {
			for (auto j = 0; j < col; j++) {
				if (matrix[i][j] == 0) {
					if (i == 0) firstRow = true;

					if (j == 0) firstCol = true;

					matrix[0][j] = 0;
					matrix[i][0] = 0;
				}
			}
		}

		for (auto i = 1; i < row; i++) {
			if (matrix[i][0] != 0) continue;

			for (auto j = 0; j < col; j++) matrix[i][j] = 0;
		}

		for (auto j = 1; j < col; j++) {
			if (matrix[0][j] != 0) continue;

			for (auto i = 0; i < row; i++) matrix[i][j] = 0;
		}

		if (firstRow) {
			for (auto j = 0; j < col; j++) matrix[0][j] = 0;
		}

		if (firstCol) {
			for (auto i = 0; i < row; i++) matrix[i][0] = 0;
		}
	}
};

class Test073Solution : public ::testing::Test {
public:
	Solution sln;
};

TEST_F(Test073Solution, t1) {
	vector<vector<int>> matrix = {
		{1, 1, 1},
	{1, 0, 1},
	{1, 1, 1}
	};

	vector<vector<int>> expect = {
		{1, 0, 1},
	{0, 0, 0},
	{1, 0, 1}
	};

	sln.setZeroes(matrix);
	EXPECT_EQ(matrix, expect);
}

TEST_F(Test073Solution, t2) {
	vector<vector<int>> matrix = {
		{0, 1, 1},
	{1, 0, 1},
	{1, 1, 1}
	};

	vector<vector<int>> expect = {
		{0, 0, 0},
	{0, 0, 0},
	{0, 0, 1}
	};

	sln.setZeroes(matrix);
	EXPECT_EQ(matrix, expect);
}

TEST_F(Test073Solution, t3) {
	vector<vector<int>> matrix = {
		{0, 1, 2, 0},
	{3, 4, 5, 2},
	{1, 3, 1, 5}
	};

	vector<vector<int>> expect = {
		{0, 0, 0, 0},
	{0, 4, 5, 0},
	{0, 3, 1, 0}
	};

	sln.setZeroes(matrix);
	EXPECT_EQ(matrix, expect);
}

GTEST_MAIN