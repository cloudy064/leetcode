//
// Created by ≥£”¿‘≈ on 2019/2/22.
//

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/sqrtx/

class Solution {
public:
	int mySqrt(int x) {
		if (x == 0) return 0;

		int up = min(46340, x);
		int floor = 1;

		while (floor <= up) {
			int num = (floor + up) / 2;
			int result = num * num;
			if (result == x) return num;

			if (result > x) {
				up = num - 1;
			}
			else {
				floor = num + 1;
			}
		}

		return up;
	}
};

class Test069Solution : public ::testing::Test {
public:
	Solution sln;
};

TEST_F(Test069Solution, t1) {
	EXPECT_EQ(sln.mySqrt(1), 1);
	EXPECT_EQ(sln.mySqrt(0), 0);
	EXPECT_EQ(sln.mySqrt(4), 2);
	EXPECT_EQ(sln.mySqrt(8), 2);
	EXPECT_EQ(sln.mySqrt(9), 3);
	EXPECT_EQ(sln.mySqrt(8), 2);
	EXPECT_EQ(sln.mySqrt(INT_MAX), 46340);
}


GTEST_MAIN