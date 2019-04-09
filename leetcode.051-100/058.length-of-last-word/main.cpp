//
// Created by cloudy064 on 2019/2/22.
//

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/length-of-last-word/

class Solution {
public:
	int lengthOfLastWord(string s) {
		int length = s.length();
		if (length == 0) return 0;

		int result = 0;
		int i = length - 1;
		while (i >= 0 && s[i--] == ' ');

		++i;
		while (i >= 0 && s[i--] != ' ') ++result;

		return result;
	}
};

class Test058Solution : public ::testing::Test {
public:
	Solution sln;
};

TEST_F(Test058Solution, t1) {
	EXPECT_EQ(sln.lengthOfLastWord(""), 0);
	EXPECT_EQ(sln.lengthOfLastWord(" "), 0);
}

TEST_F(Test058Solution, t2) {
	EXPECT_EQ(sln.lengthOfLastWord("abc"), 3);
	EXPECT_EQ(sln.lengthOfLastWord(" abc"), 3);
	EXPECT_EQ(sln.lengthOfLastWord("abc   "), 3);
}

TEST_F(Test058Solution, t3) {
	EXPECT_EQ(sln.lengthOfLastWord("hello world"), 5);
	EXPECT_EQ(sln.lengthOfLastWord(" hello world"), 5);
	EXPECT_EQ(sln.lengthOfLastWord("hello world   "), 5);
}

GTEST_MAIN