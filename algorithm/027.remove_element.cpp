//
// Created by cloudy064 on 2018/6/25.
//

#include <algorithm>
#include <unordered_map>
#include "common.h"

using namespace std;

/// https://leetcode-cn.com/problems/remove-element/description/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        if (size <= 0) return 0;

        int count_of_val = 0;
        int elements = 0;

        for (int i = 0; i < size - count_of_val; ++i) {
            if (nums[i] == val) {
                while (nums[size - count_of_val - 1] == val) {
                    ++count_of_val;
                }

                if (i >= size - count_of_val - 1) break;
                nums[i] = nums[size - count_of_val - 1];
                ++count_of_val;
            }

            ++elements;
        }

        return elements;
    }
};

class Test027Solution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(Test027Solution, t1)
{
    vector<int> input = {1,2,3,4,5};
    set<int> expect = {2,3,4,5};
    int len = sln.removeElement(input, 1);
    EXPECT_EQ(len, expect.size());
    for (int i = 0; i < len; ++i) {
        EXPECT_TRUE(expect.find(input[i]) != expect.end());
    }
}

TEST_F(Test027Solution, t2)
{
    vector<int> input = {1,1,1,1,1};
    set<int> expect;
    int len = sln.removeElement(input, 1);
    EXPECT_EQ(len, expect.size());
    for (int i = 0; i < len; ++i) {
        EXPECT_TRUE(expect.find(input[i]) != expect.end());
    }
}

TEST_F(Test027Solution, t3)
{
    vector<int> input = {1,2,3,4,5};
    set<int> expect = {1,2,3,4,5};
    int len = sln.removeElement(input, 6);
    EXPECT_EQ(len, expect.size());
    for (int i = 0; i < len; ++i) {
        EXPECT_TRUE(expect.find(input[i]) != expect.end());
    }
}

TEST_F(Test027Solution, t4)
{
    vector<int> input = {};
    set<int> expect = {};
    int len = sln.removeElement(input, 6);
    EXPECT_EQ(len, expect.size());
    for (int i = 0; i < len; ++i) {
        EXPECT_TRUE(expect.find(input[i]) != expect.end());
    }
}

TEST_F(Test027Solution, t5)
{
    vector<int> input = {0,1,2,2,3,4,2};
    set<int> expect = {0,1,3,4};
    int len = sln.removeElement(input, 2);
    EXPECT_EQ(len, expect.size());
    for (int i = 0; i < len; ++i) {
        EXPECT_TRUE(expect.find(input[i]) != expect.end());
    }
}

TEST_F(Test027Solution, t6)
{
    vector<int> input = {2,2,3};
    set<int> expect = {3};
    int len = sln.removeElement(input, 2);
    EXPECT_EQ(len, expect.size());
    for (int i = 0; i < len; ++i) {
        EXPECT_TRUE(expect.find(input[i]) != expect.end());
    }
}

GTEST_MAIN