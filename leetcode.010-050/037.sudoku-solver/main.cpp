//
// Created by cloudy064 on 2019/4/9.
//

#include "common.h"
#include <unordered_set>

using namespace std;

/// Solution for https://leetcode-cn.com/problems/sudoku-solver/

class Solution {
public:
	unordered_set<char> occurs;
	const string chars = "123456789";

	vector<vector<int>> rowMissing = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1}
	};

	vector<vector<int>> colMissing = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1}
	};

	vector<vector<int>> sqrMissing = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1}
	};

	inline int square(int i, int j) {
		return i / 3 * 3 + j / 3;
	}

	void scanMissing(vector<vector<char>> & board) {
		// Mark the values taken
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.') {
					int val = board[i][j] - '1';

					rowMissing[i][val] = 0;
					colMissing[j][val] = 0;
					sqrMissing[square(i, j)][val] = 0;
				}
			}
		}
	}

	bool solveSudokuImpl(vector<vector<char>> & board) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.') continue;

				for (auto c : chars) {
					int s = square(i, j);

					int val = c - '1';

					// Check if val has been set in row/column/square
					if (!rowMissing[i][val]) continue;
					if (!colMissing[j][val]) continue;
					if (!sqrMissing[s][val]) continue;

					// Take this character and mark val has been taken in row/column/square
					board[i][j] = c;
					rowMissing[i][val] = 0;
					colMissing[j][val] = 0;
					sqrMissing[s][val] = 0;

					if (solveSudokuImpl(board)) return true;

				fail:
					// Store row/column/square
					rowMissing[i][val] = 1;
					colMissing[j][val] = 1;
					sqrMissing[s][val] = 1;
				}

				board[i][j] = '.';
				return false;
			}
		}

		return true;
	}

	void solveSudoku(vector<vector<char>> & board) {
		scanMissing(board);
		solveSudokuImpl(board);
	}
};

class TestSolution : public ::testing::Test {
public:
	Solution sln;
};

TEST_F(TestSolution, t1) {
	vector<vector<char>> board = {
		{'.', '.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.', '.'}
	};

	sln.solveSudoku(board);

	vector<vector<char>> expect = {
	{'1','2','3','4','5','6','7','8','9'},
	{'4','5','6','7','8','9','1','2','3'},
	{'7','8','9','1','2','3','4','5','6'},
	{'2','1','4','3','6','5','8','9','7'},
	{'3','6','5','8','9','7','2','1','4'},
	{'8','9','7','2','1','4','3','6','5'},
	{'5','3','1','6','4','2','9','7','8'},
	{'6','4','2','9','7','8','5','3','1'},
	{'9','7','8','5','3','1','6','4','2'}
	};

	EXPECT_EQ(board, expect);
}

TEST_F(TestSolution, t2) {
	vector<vector<char>> board = { {'5','3','.','.','7','.','.','.','.'},
{'6','.','.','1','9','5','.','.','.'},
{'.','9','8','.','.','.','.','6','.'},
{'8','.','.','.','6','.','.','.','3'},
{'4','.','.','8','.','3','.','.','1'},
{'7','.','.','.','2','.','.','.','6'},
{'.','6','.','.','.','.','2','8','.'},
{'.','.','.','4','1','9','.','.','5'},
{'.','.','.','.','8','.','.','7','9'} };

	sln.solveSudoku(board);

	vector<vector<char>> expect = { {'5','3','4','6','7','8','9','1','2'},
{'6','7','2','1','9','5','3','4','8'},
{'1','9','8','3','4','2','5','6','7'},
{'8','5','9','7','6','1','4','2','3'},
{'4','2','6','8','5','3','7','9','1'},
{'7','1','3','9','2','4','8','5','6'},
{'9','6','1','5','3','7','2','8','4'},
{'2','8','7','4','1','9','6','3','5'},
{'3','4','5','2','8','6','1','7','9'} };

	EXPECT_EQ(board, expect);
}

GTEST_MAIN