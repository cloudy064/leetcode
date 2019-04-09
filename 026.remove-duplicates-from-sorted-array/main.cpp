//
// Created by cloudy064 on 2018/6/25.
//

#include <algorithm>
#include <unordered_map>
#include "common.h"

using namespace std;

/// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/description/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1) return size;

        int count = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[count-1]) continue;

            nums[count++] = nums[i];
        }

        return count;
    }
};

class Test026Solution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(Test026Solution, t1)
{
    vector<int> input = {1,2,3,4,5};
    vector<int> expect = {1,2,3,4,5};
    int len = sln.removeDuplicates(input);
    for (int i = 0; i < len; ++i) {
        EXPECT_EQ(input[i], expect[i]);
    }
}

TEST_F(Test026Solution, t2)
{
    vector<int> input = {1,1,1,4,5};
    vector<int> expect = {1,4,5};
    int len = sln.removeDuplicates(input);
    for (int i = 0; i < len; ++i) {
        EXPECT_EQ(input[i], expect[i]);
    }
}

TEST_F(Test026Solution, t3)
{
    vector<int> input = {};
    vector<int> expect = {};
    int len = sln.removeDuplicates(input);
    for (int i = 0; i < len; ++i) {
        EXPECT_EQ(input[i], expect[i]);
    }
}

TEST_F(Test026Solution, t4)
{
    vector<int> input = {1};
    vector<int> expect = {1};
    int len = sln.removeDuplicates(input);
    for (int i = 0; i < len; ++i) {
        EXPECT_EQ(input[i], expect[i]);
    }
}

GTEST_MAIN