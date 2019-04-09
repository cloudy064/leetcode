//
// Created by cloudy064 on 2018/6/21.
//


#include <algorithm>
#include <unordered_map>
#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/longest-common-prefix/description/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        if (strs.size() == 1) return strs[0];

        string prefix;
        int first_length = strs[0].length();
        for (int i = 0; i < first_length; ++i) {
            char ch = strs[0][i];
            for (int j = 1; j < strs.size(); ++j) {
                if (i >= strs[j].length()) return prefix;
                if (ch != strs[j][i]) return prefix;
            }

            prefix.push_back(ch);
        }

        return prefix;
    }
};

class Test014Solution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(Test014Solution, t1)
{
    string expect;
    vector<string> strs;
    string result = sln.longestCommonPrefix(strs);
    EXPECT_TRUE(expect.compare(result) == 0);
}

TEST_F(Test014Solution, t2)
{
    string expect = "prefix";
    vector<string> strs = {"prefix"};
    string result = sln.longestCommonPrefix(strs);
    EXPECT_TRUE(expect.compare(result) == 0);
}

TEST_F(Test014Solution, t3)
{
    string expect = "fl";
    vector<string> strs = {"flower","flow","flight"};
    string result = sln.longestCommonPrefix(strs);
    EXPECT_TRUE(expect.compare(result) == 0);
}

TEST_F(Test014Solution, t4)
{
    string expect;
    vector<string> strs = {"dog","racecar","car"};
    string result = sln.longestCommonPrefix(strs);
    EXPECT_TRUE(expect.compare(result) == 0);
}

GTEST_MAIN