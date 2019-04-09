//
// Created by cloudy064 on 2019/2/22.
//

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/spiral-matrix-ii/

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> result(n, vector<int>(n, 0));

		int max = n * n;
		int round = 0;
		int row = 0;
		int col = 0;
		int i = 1;
		while (i <= max)
		{
			int direction = round % 4;
			int offset = round / 4;
			switch (direction)
			{
			case 0:
				for (; col < n - offset; ++col) result[row][col] = i++;
				++row;
				--col;
				break;

			case 1:
				for (; row < n - offset; ++row) result[row][col] = i++;
				--row;
				--col;
				break;

			case 2:
				for (; col >= offset; --col) result[row][col] = i++;
				--row;
				++col;
				break;

			default: //case 3:
				for (; row > offset; --row) result[row][col] = i++;
				++row;
				++col;
				break;
			}

			++round;
		}

		return result;
	}
};

class Test059Solution : public ::testing::Test {
public:
	Solution sln;
};

TEST_F(Test059Solution, t1) {
	vector<vector<int>> expect = { {1} };
	EXPECT_EQ(sln.generateMatrix(1), expect);
}

TEST_F(Test059Solution, t2) {
	vector<vector<int>> expect = { {1,2}, {4,3} };
	EXPECT_EQ(sln.generateMatrix(2), expect);
}

TEST_F(Test059Solution, t3) {
	vector<vector<int>> expect = { {1,2, 3}, {8,9,4}, {7,6,5} };
	EXPECT_EQ(sln.generateMatrix(3), expect);
}

TEST_F(Test059Solution, t4) {
	vector<vector<int>> expect = { 
		{1,2,3,4}, 
		{12,13,14,5}, 
		{11,16,15,6},
		{10,9,8,7}
	};
	EXPECT_EQ(sln.generateMatrix(4), expect);
}

GTEST_MAIN