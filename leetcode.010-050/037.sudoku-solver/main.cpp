//
// Created by cloudy064 on 2019/4/9.
//

#include "common.h"
#include <unordered_set>

using namespace std;

/// Solution for https://leetcode-cn.com/problems/sudoku-solver/

/*
hints:
Recursion
*/

class Solution {
public:
	unordered_set<char> occurs;
	const string chars = "123456789";

	bool isValidRow(vector<vector<char>>& board, int row) {
		occurs.clear();

		for (auto c : board[row]) {
			if (c == '.') continue;

			auto it = occurs.find(c);
			if (it != occurs.end()) return false;

			occurs.insert(c);
		}

		return true;
	}

	bool isValidColumn(vector<vector<char>> & board, int col) {
		occurs.clear();

		for (auto vec : board) {
			auto c = vec[col];
			if (c == '.') continue;

			auto it = occurs.find(c);
			if (it != occurs.end()) return false;

			occurs.insert(c);
		}

		return true;
	}

	bool isValidSquare(vector<vector<char>> & board, int index) {
		occurs.clear();

		int offsetI = index / 3 * 3;
		int offsetJ = (index % 3) * 3;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				auto c = board[i + offsetI][j + offsetJ];
				if (c == '.') continue;

				auto it = occurs.find(c);
				if (it != occurs.end()) return false;

				occurs.insert(c);
			}
		}

		return true;
	}

	bool isValidSudoku(vector<vector<char>> & board) {
		for (int i = 0; i < 9; i++) {
			if (!isValidRow(board, i)) return false;
		}

		for (int i = 0; i < 9; i++) {
			if (!isValidColumn(board, i)) return false;
		}

		for (int i = 0; i < 9; i++) {
			if (!isValidSquare(board, i)) return false;
		}

		return true;
	}

	inline int square(int i, int j) {
		return i / 3 * 3 + j / 3;
	}

	bool solveSudokuImpl(vector<vector<char>>& board) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.') continue;

				for (auto c : chars) {
					int s = square(i, j);

					board[i][j] = c;

					// Check if the soduku is valid
					if (!isValidColumn(board, j)) continue;
					if (!isValidRow(board, i)) continue;
					if (!isValidSquare(board, s)) continue;

					// If I can solve this soduku with setting board[i][j] to c, it is a correct answer.
					if (solveSudokuImpl(board)) return true; 
				}
				
				// In this case, we cannot solve this soduku with all characters.
				board[i][j] = '.';
				return false;
			}
		}

		// The program reaches here when i >= 9 and j >= 9
		return true;
	}

	void solveSudoku(vector<vector<char>>& board) {
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