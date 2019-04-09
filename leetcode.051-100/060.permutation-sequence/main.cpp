//
// Created by ≥£”¿‘≈ on 2019/2/22.
//

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/permutation-sequence/

class Solution {
public:
	string getPermutation(int n, int k) {
		if (n == 1) return "1";

		vector<int> temp(n, 1);
		for (int i = 2; i <= n; i++) temp[i - 1] = temp[i - 2] * i;

		
	}
};

class Test060Solution : public ::testing::Test {
public:
	Solution sln;
};

TEST_F(Test060Solution, t1) {
	vector<vector<int>> expect = { {1} };
	EXPECT_EQ(sln.generateMatrix(1), expect);
}

GTEST_MAIN