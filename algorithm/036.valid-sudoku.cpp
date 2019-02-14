//
// Created by 常永耘 on 2019/2/14.
//

#include <vector>
#include <unordered_set>

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/valid-sudoku/

class Solution {
public:
    bool isValidRow(vector<vector<char>>& board, int row) {
        unordered_set<char> occurs;

        for (auto c : board[row]) {
            if (c == '.') continue;

            auto it = occurs.find(c);
            if (it != occurs.end()) return false;

            occurs.insert(c);
        }

        return true;
    }

    bool isValidColumn(vector<vector<char>>& board, int col) {
        unordered_set<char> occurs;

        for (auto vec : board) {
            auto c = vec[col];
            if (c == '.') continue;

            auto it = occurs.find(c);
            if (it != occurs.end()) return false;

            occurs.insert(c);
        }

        return true;
    }

    bool isValidSquare(vector<vector<char>>& board, int index) {
        unordered_set<char> occurs;

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

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            if (!isValidRow(board, i)) return false;
            //isValidColumn(board, i);
            //isValidSquare(board, i);
        }

        for (int i = 0; i < 9; i++) {
            //isValidRow(board, i);
            if (!isValidColumn(board, i)) return false;
            //isValidSquare(board, i);
        }

        for (int i = 0; i < 9; i++) {
            //isValidRow(board, i);
            //isValidColumn(board, i);
            if (!isValidSquare(board, i)) return false;
        }

        return true;
    }
};

class Test036Solution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(Test036Solution, t1) {
    vector<vector<char>> board = {
            {'5','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
    };
    ASSERT_TRUE(sln.isValidSudoku(board));
}

TEST_F(Test036Solution, t2) {
    vector<vector<char>> board = {
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    ASSERT_FALSE(sln.isValidSudoku(board));
}

GTEST_MAIN
