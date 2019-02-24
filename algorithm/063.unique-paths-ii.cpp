//
// Created by 常永耘 on 2019/2/24.
//

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/unique-paths-ii/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty()) return 0;
        if (obstacleGrid[0].empty()) return 0;

        if (obstacleGrid[0][0] == 1) return 0;

        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if (obstacleGrid[n - 1][m - 1] == 1) return 0;
        vector<vector<long>> paths(n, vector<long>(m, 0)); // watch for overflow
        paths[0][0] = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 && j == 0) continue;

                if (obstacleGrid[i][j] == 1) {
                    continue;
                }

                if (i >= 1) {
                    paths[i][j] += paths[i-1][j];
                }

                if (j >= 1) {
                    paths[i][j] += paths[i][j-1];
                }
            }
        }

        return int(paths[n - 1][m - 1]);
    }
};

class Test063Solution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(Test063Solution, t1) {
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    EXPECT_EQ(sln.uniquePathsWithObstacles(obstacleGrid), 2);
}

TEST_F(Test063Solution, t2) {
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0},{0,1,0}};
    EXPECT_EQ(sln.uniquePathsWithObstacles(obstacleGrid), 2);
}

TEST_F(Test063Solution, t3) {
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{1,1,1},{0,1,0}};
    EXPECT_EQ(sln.uniquePathsWithObstacles(obstacleGrid), 0);
}

TEST_F(Test063Solution, t4) {
    vector<vector<int>> obstacleGrid = {{0,0},{1,1},{0,0}};
    EXPECT_EQ(sln.uniquePathsWithObstacles(obstacleGrid), 0);
}

GTEST_MAIN
