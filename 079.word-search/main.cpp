//
// Created by cloudy064 on 2019/4/8.
//

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/word-search/

class Solution {
public:
	bool search(vector<vector<char>>& board, vector<vector<int>>& visited, string word, int skip, int i, int j) {
		if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return false;
		if (board[i][j] != word[skip]) return false;
		if (visited[i][j]) return false;

		visited[i][j] = 1;
		if (skip + 1 == word.length()) return true;

		if (search(board, visited, word, skip + 1, i - 1, j)) return true;
		if (search(board, visited, word, skip + 1, i + 1, j)) return true;
		if (search(board, visited, word, skip + 1, i, j - 1)) return true;
		if (search(board, visited, word, skip + 1, i, j + 1)) return true;

		visited[i][j] = 0;

		return false;
	}

	bool exist(vector<vector<char>>& board, string word) {
		if (word.empty()) return true;

		if (board.empty() || board[0].empty()) return false;

		int row = board.size();
		int col = board[0].size();

		vector<vector<int>> visited(row, vector<int>(col, 0));

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (search(board, visited, word, 0, i, j)) return true;
			}
		}

		return false;
	}
};

class Test079Solution : public ::testing::Test {
public:
	Solution sln;
};

TEST_F(Test079Solution, t1) {
	vector<vector<char>> board = {
		{'A', 'B', 'C', 'E'},
	{'S', 'F', 'C', 'S'},
	{'A', 'D', 'E', 'E'}
	};
	EXPECT_TRUE(sln.exist(board, "ABCCED"));
	EXPECT_TRUE(sln.exist(board, "SEE"));
	EXPECT_FALSE(sln.exist(board, "ABCB"));
}


GTEST_MAIN
