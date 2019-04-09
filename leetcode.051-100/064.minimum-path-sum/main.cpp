//
// Created by 常永耘 on 2019/2/24.
//

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/minimum-path-sum/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        if (grid[0].empty()) return 0;

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<long>> sum(n, vector<long>(m, 0));
        sum[0][0] = grid[0][0];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 && j == 0) continue;

                if (i == 0) {
                    sum[i][j] = sum[i][j - 1] + grid[i][j];
                } else if (j == 0) {
                    sum[i][j] = sum[i - 1][j] + grid[i][j];
                } else {
                    sum[i][j] = min(sum[i - 1][j] + grid[i][j], sum[i][j - 1] + grid[i][j]);
                }
            }
        }

        return int(sum[n - 1][m - 1]);
    }
};

class Test064Solution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(Test064Solution, t1) {
    vector<vector<int>> obstacleGrid = {{1,3,1},{1,5,1},{4,2,1}};
    EXPECT_EQ(sln.minPathSum(obstacleGrid), 7);
}

TEST_F(Test064Solution, t2) {
    vector<vector<int>> obstacleGrid = {{}};
    EXPECT_EQ(sln.minPathSum(obstacleGrid), 0);
}

TEST_F(Test064Solution, t3) {
    vector<vector<int>> obstacleGrid = {};
    EXPECT_EQ(sln.minPathSum(obstacleGrid), 0);
}

TEST_F(Test064Solution, t4) {
    vector<vector<int>> obstacleGrid = {{0,0},{1,1},{0,0}};
    EXPECT_EQ(sln.minPathSum(obstacleGrid), 1);
}

GTEST_MAIN
