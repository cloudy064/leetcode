//
// Created by cloudy064 on 2018/6/18.
//

#include <iostream>

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/zigzag-conversion/description/

class Solution {
public:
	string convert(string s, int numRows) {
		int length = s.length();
		if (length == 0 || numRows <= 1) {
			return s;
		}

		int numCols = (length - 1) / (2 * numRows - 2) + 1;
		int tempLength = numCols * (2 * numRows - 2);
		s.resize(tempLength, '\0');
		string res;
		res.reserve(length);
		for (int i = 0; i < numRows; ++i) {
			for (int j = 0; j < numCols; ++j) {
				int mid = (2 * j + 1) * (numRows - 1);
				int max = mid + numRows - 1;
				int step = numRows - i - 1;
				if (step != 0) {
					int left = mid - step;
					int right = mid + step;
					if (left < length) {
						res.push_back(s[left]);
					}

					if (right < length && right < max) {
						res.push_back(s[right]);
					}
				}
				else if (mid < length) {
					res.push_back(s[mid]);
				}
			}
		}

		return res;
	}
};


class Test006Solution : public ::testing::Test {
public:
	Solution sln;
};

TEST_F(Test006Solution, t1) {
	string expect = "PAHNAPLSIIGYIR";
	string result = sln.convert("PAYPALISHIRING", 3);
	ASSERT_EQ(expect.compare(result), 0);
}

TEST_F(Test006Solution, t2) {
	string expect = "PINALSIGYAHRPI";
	string result = sln.convert("PAYPALISHIRING", 4);
	ASSERT_EQ(expect.compare(result), 0);
}

TEST_F(Test006Solution, t3) {
	string expect = "P";
	string result = sln.convert("P", 3);
	ASSERT_EQ(expect.compare(result), 0);
}

TEST_F(Test006Solution, t4) {
	string expect = "";
	string result = sln.convert("", 3);
	ASSERT_EQ(expect.compare(result), 0);
}

TEST_F(Test006Solution, t5) {
	string expect = "AB";
	string result = sln.convert("AB", 2);
	ASSERT_EQ(expect.compare(result), 0);
}

TEST_F(Test006Solution, t6) {
	string expect = "ABDC";
	string result = sln.convert("ABCD", 3);
	ASSERT_EQ(expect.compare(result), 0);
}

GTEST_MAIN