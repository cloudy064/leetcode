//
// Created by 常永耘 on 2019/2/19.
//

#include "common.h"

#include <unordered_map>

using namespace std;

/// Solution for https://leetcode-cn.com/problems/group-anagrams/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> words;
        for (auto str : strs) {
            string copy = str;
            sort(str.begin(), str.end());
            auto it = words.find(str);
            if (it == words.end()) {
                vector<string> temp = {copy};
                words.insert(it, {str, temp});
            } else {
                it->second.emplace_back(copy);
            }
        }

        vector<vector<string>> result;
        for (auto it = words.begin(); it != words.end(); it++) {
            result.emplace_back(it->second);
        }

        return result;
    }
};

class Test049Solution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(Test049Solution, t1) {
    vector<string> words = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> expect = {
            {"eat","tea","ate"},
            {"tan","nat"},
            {"bat"}
    };

    auto result = sln.groupAnagrams(words);
    sort(expect.begin(), expect.end());
    sort(result.begin(), result.end());

    EXPECT_EQ(result, expect);
}

TEST_F(Test049Solution, t2) {
    vector<string> words = {};
    vector<vector<string>> expect = {};

    auto result = sln.groupAnagrams(words);
    sort(expect.begin(), expect.end());
    sort(result.begin(), result.end());

    EXPECT_EQ(result, expect);
}

GTEST_MAIN