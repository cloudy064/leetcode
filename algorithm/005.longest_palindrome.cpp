//
// Created by 常永耘 on 2018/6/18.
//

#include <iostream>

#include "common.h"

using namespace std;

class Solution {
public:
	// Manacher algorithm
	string longestPalindrome(string s) {
		int length = s.length();
		string pretreatment(2 * length + 1, '#');
		for (size_t i = 0; i < length; ++i) {
			pretreatment[2 * i + 1] = s.at(i);
		}

		int palindromeRight = 1; // the right limit of the current palindrome
		int mid = 0; // the mid character of the current palindrome
		int* palindromeLength = new int[2 * length + 1]{ 1 };

		int max_mid = 0;
		for (int i = 1; i < 2 * length + 1; ++i) {
			if (i < palindromeRight) {
				palindromeLength[i] = min(palindromeLength[2 * mid - i], palindromeRight - i);
			}

			while (i + palindromeLength[i] < 2 * length + 1
				&& i - palindromeLength[i] >= 0
				&& pretreatment[i + palindromeLength[i]] == pretreatment[i - palindromeLength[i]]) {
				++palindromeLength[i];
			}

			if (i + palindromeLength[i] > palindromeRight) {
				mid = i;
				palindromeRight = i + palindromeLength[i];
			}

			if (palindromeLength[max_mid] < palindromeLength[i]) {
				max_mid = i;
			}
		}

		string res = pretreatment.substr(max_mid - palindromeLength[max_mid] + 1, 2 * palindromeLength[max_mid] - 1);
		string palindrome;
		palindrome.reserve(palindromeLength[max_mid]);
		for (int i = 0; i < 2 * palindromeLength[max_mid] - 1; i++) {
			char c = res.at(i);
			if (c == '#') continue;
			palindrome.push_back(c);
		}

		return palindrome;
	}
};


class Test005Solution : public ::testing::Test {
public:
	Solution sln;
};


TEST_F(Test005Solution, t1) {
	string expect = "bab";
	string result = sln.longestPalindrome("babad");
	ASSERT_EQ(expect.compare(result), 0);
}

TEST_F(Test005Solution, t2) {
	string expect = "bb";
	string result = sln.longestPalindrome("cbbd");
	ASSERT_EQ(expect.compare(result), 0);
}

TEST_F(Test005Solution, t3) {
	string expect = "cbbc";
	string result = sln.longestPalindrome("cbbc");
	ASSERT_EQ(expect.compare(result), 0);
}

TEST_F(Test005Solution, t4) {
	string expect = "adada";
	string result = sln.longestPalindrome("babadada");
	ASSERT_EQ(expect.compare(result), 0);
}

TEST_F(Test005Solution, t5) {
	string expect = "a";
	string result = sln.longestPalindrome("a");
	ASSERT_EQ(expect.compare(result), 0);
}


GTEST_MAIN