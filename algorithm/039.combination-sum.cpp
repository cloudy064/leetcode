//
// Created by 常永耘 on 2019/2/15.
//

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/combination-sum/

class Solution {
public:
    void sumImpl(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& prefix, int idx) {
        if (idx >= candidates.size()) return;

        auto num = candidates[idx];
        if (num > target) return;

        int count = target / num;
        int prefixSize = prefix.size();
        for (int i = 0; i <= count; i++) {
            prefix.resize(prefixSize);
            for (int j = 0; j < i; j++) {
                prefix.emplace_back(num);
            }

            if (target - num * i != 0) {
                sumImpl(candidates, target - num * i, result, prefix, idx + 1);
            } else {
                result.emplace_back(prefix);
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> prefix;
        sumImpl(candidates, target, result, prefix, 0);
        return result;
    }
};

class Test039Solution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(Test039Solution, t1) {
    vector<int> candidates = {2,3,6,7};
    vector<vector<int>> expects = {{7},{2,2,3}};

    auto result = sln.combinationSum(candidates, 7);
    sort(expects.begin(), expects.end());
    sort(result.begin(), result.end());
    ASSERT_EQ(expects, result);
}

TEST_F(Test039Solution, t2) {
    vector<int> candidates = {2,3,5};
    vector<vector<int>> expects = {{2,2,2,2},{2,3,3},{3,5}};

    auto result = sln.combinationSum(candidates, 8);
    sort(expects.begin(), expects.end());
    sort(result.begin(), result.end());
    ASSERT_EQ(expects, result);
}

GTEST_MAIN