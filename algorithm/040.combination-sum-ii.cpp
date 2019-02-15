//
// Created by 常永耘 on 2019/2/15.
//

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/combination-sum-ii/

class Solution {
public:
    void sumImpl(vector<int>& candidates, vector<int>& counts, int target, vector<vector<int>>& result, vector<int>& prefix, int idx) {
        if (idx >= candidates.size()) return;

        auto num = candidates[idx];
        if (num > target) return;

        int count = target / num;
        int prefixSize = prefix.size();
        for (int i = 0; i <= count && i <= counts[idx]; i++) {
            prefix.resize(prefixSize);
            for (int j = 0; j < i; j++) {
                prefix.emplace_back(num);
            }

            if (target - num * i != 0) {
                sumImpl(candidates, counts, target - num * i, result, prefix, idx + 1);
            } else {
                result.emplace_back(prefix);
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> counts;
        vector<int> nums;
        int prev = 0;
        int count = 0;
        for (auto num : candidates) {
            if (count == 0) {
                count = 1;
                nums.emplace_back(num);
            } else if (prev != num) {
                counts.emplace_back(count);

                count = 1;
                nums.emplace_back(num);
            } else {
                ++count;
            }

            prev = num;
        }

        counts.emplace_back(count);

        vector<vector<int>> result;
        vector<int> prefix;
        sumImpl(nums, counts, target, result, prefix, 0);
        return result;
    }
};

class Test040Solution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(Test040Solution, t1) {
    vector<int> candidates = {2,3,6,7};
    vector<vector<int>> expects = {{7}};

    auto result = sln.combinationSum2(candidates, 7);
    sort(expects.begin(), expects.end());
    sort(result.begin(), result.end());
    ASSERT_EQ(expects, result);
}

TEST_F(Test040Solution, t2) {
    vector<int> candidates = {2,3,5};
    vector<vector<int>> expects = {{3,5}};

    auto result = sln.combinationSum2(candidates, 8);
    sort(expects.begin(), expects.end());
    sort(result.begin(), result.end());
    ASSERT_EQ(expects, result);
}

TEST_F(Test040Solution, t3) {
    vector<int> candidates = {10,1,2,7,6,1,5};
    vector<vector<int>> expects = {{1,7},{1,2,5},{2,6},{1,1,6}};

    auto result = sln.combinationSum2(candidates, 8);
    sort(expects.begin(), expects.end());
    sort(result.begin(), result.end());
    ASSERT_EQ(expects, result);
}

TEST_F(Test040Solution, t4) {
    vector<int> candidates = {2,5,2,1,2};
    vector<vector<int>> expects = {{1,2,2},{5}};

    auto result = sln.combinationSum2(candidates, 5);
    sort(expects.begin(), expects.end());
    sort(result.begin(), result.end());
    ASSERT_EQ(expects, result);
}

GTEST_MAIN