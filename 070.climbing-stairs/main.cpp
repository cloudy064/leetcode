//
// Created by cloudy064 on 2019/4/4.
//

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/climbing-stairs/


class Solution {
public:
	int climbStairs(int n) {
		if (n <= 3) return n;

		int prev = 2;
		int curr = 3;
		int temp = 0;
		for (int i = 3; i < n; i++) {
			temp = curr;
			curr += prev;
			prev = temp;
		}

		return curr;
	}
};

class Test070Solution : public ::testing::Test {
public:
	Solution sln;
};

TEST_F(Test070Solution, t1) {
	EXPECT_EQ(sln.climbStairs(1), 1);
	EXPECT_EQ(sln.climbStairs(2), 2);
	EXPECT_EQ(sln.climbStairs(3), 3);
	EXPECT_EQ(sln.climbStairs(4), 5);
	EXPECT_EQ(sln.climbStairs(5), 8);
}

GTEST_MAIN