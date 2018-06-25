//
// Created by cloudy064 on 2018/6/17.
//

#include <iostream>
#include <vector>
#include <unordered_map>

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/implement-strstr/description/

class Solution {
public:
    vector<int> getNext(string str) {
        int size = str.size();
        vector<int> next;
        next.resize(size, 0);
        for (int i = 1, j = 0; i < str.size(); ++i) {
            while (j > 0 && str[i] != str[j]) {
                j = next[j - 1];
            }

            if (str[j] == str[i]) {
                ++j;
            }

            next[i] = j;
    
        }

        return next;
    }

	int strStr(string haystack, string needle) {
		if (needle.empty()) return 0;
		auto next = getNext(needle);

		for (int i = 0, j = 0; i < haystack.length(); ++i)
		{
			while (j > 0 && haystack[i] != needle[j])
			{
				j = next[j - 1];
			}

			if (haystack[i] == needle[j])
			{
				++j;
			}

			if (j == needle.length()) return i - needle.length() + 1;
		}

		return -1;
	}
};

class Test028Solution : public ::testing::Test {
public:
	Solution sln;
};

TEST_F(Test028Solution, t1) {
	auto idx = sln.strStr("abcde", "abcde");
	EXPECT_EQ(idx, 0);
}

TEST_F(Test028Solution, t2) {
	auto idx = sln.strStr("abcde", "cd");
	EXPECT_EQ(idx, 2);
}

TEST_F(Test028Solution, t3) {
	auto idx = sln.strStr("abcababa", "ababa");
	EXPECT_EQ(idx, 3);
}

TEST_F(Test028Solution, t4) {
	auto idx = sln.strStr("abcde", "");
	EXPECT_EQ(idx, 0);
}

TEST_F(Test028Solution, t5) {
	auto idx = sln.strStr("abcde", "abce");
	EXPECT_EQ(idx, -1);
}

TEST_F(Test028Solution, t6)
{
	auto idx = sln.strStr("mississippi", "issip");
	EXPECT_EQ(idx, 4);
}

GTEST_MAIN