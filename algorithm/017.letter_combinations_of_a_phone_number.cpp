//
// Created by cloudy064 on 2018/6/21.
//


#include <algorithm>
#include <unordered_map>
#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

		unordered_map<char, string> digit_map = {
			{ '2', "abc" },
			{ '3', "def" },
			{ '4', "ghi" },
			{ '5', "jkl" },
			{ '6', "mno" },
			{ '7', "pqrs" },
			{ '8', "tuv" },
			{ '9', "wxyz" }
		};

        vector<string> result;
        int len = digits.length();
        vector<int> idxs(len);
        idxs.assign(len, 0);
        vector<string> mapping;
        mapping.reserve(len);
        for (int i = 0; i < len; ++i) {
            mapping.push_back(digit_map[digits[i]]);
        }

        string temp;
        temp.resize(len, '\0');
        while (true) {
            for (int i = len - 1; i >= 0; --i) {
                if (idxs[i] < mapping[i].length()) break;

                if (i == 0) {
                    return result;
                }

                idxs[i] = 0;
                idxs[i - 1] += 1;
            }

            for (int i = 0; i < len; ++i) {
                temp[i] = mapping[i][idxs[i]];
            }

            result.push_back(temp);

            idxs[len - 1] += 1;
        }
    }
};

class Test017Solution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(Test017Solution, t1)
{
    vector<string> result = sln.letterCombinations("23");
    vector<string> expect = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
    EXPECT_EQ(result, expect);
}

TEST_F(Test017Solution, t2)
{
    vector<string> result = sln.letterCombinations("");
    vector<string> expect;
    EXPECT_EQ(result, expect);
}

TEST_F(Test017Solution, t3)
{
    vector<string> result = sln.letterCombinations("32");
    vector<string> expect = {"da", "db", "dc", "ea", "eb", "ec", "fa", "fb", "fc"};
    EXPECT_EQ(result, expect);
}

TEST_F(Test017Solution, t4)
{
    vector<string> result = sln.letterCombinations("22");
    vector<string> expect = {"aa", "ab", "ac", "ba", "bb", "bc", "ca", "cb", "cc"};
    EXPECT_EQ(result, expect);
}


GTEST_MAIN