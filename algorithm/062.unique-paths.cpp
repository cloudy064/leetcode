//
// Created by 常永耘 on 2019/2/24.
//

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/unique-paths/

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m <= 0 || n <= 0) return 0;
        if (m == 1 || n == 1) return 1;

        int tmp1 = m + n - 2;
        int tmp2 = min(m - 1, n - 1);
        long a = 1;
        for (int i = 0; i < tmp2; i++) {
            a *= tmp1;
            --tmp1;
        }

        long b = 1;
        for (int i = 1; i <= tmp2; i++) {
            b *= i;
        }

        return int(a / b);
    }
};

class Test062Solution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(Test062Solution, t1) {
    EXPECT_EQ(sln.uniquePaths(1, 3), 1);
    EXPECT_EQ(sln.uniquePaths(1, 0), 0);
    EXPECT_EQ(sln.uniquePaths(1, -3), 0);
}

TEST_F(Test062Solution, t2) {
    EXPECT_EQ(sln.uniquePaths(2, 3), 3);
    EXPECT_EQ(sln.uniquePaths(5, 5), 70);
    EXPECT_EQ(sln.uniquePaths(4, 3), 10);
}

GTEST_MAIN
