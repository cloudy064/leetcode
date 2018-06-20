//
// Created by cloudy064 on 2018/6/21.
//


#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/container-with-most-water/description/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int first = 0;
        int second = static_cast<int>(height.size() - 1);
        int max = 0;
        do {
            bool first_smaller = (height[first] < height[second]);
            int area = (first_smaller ? height[first] : height[second]) * (second - first);
            if (area > max) max = area;

            first_smaller ? ++first : --second;
        } while(first < second);

        return max;
    }
};

class Test011Solution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(Test011Solution, t1)
{
    vector<int> height = {1,1,1,1,1};
    ASSERT_EQ(sln.maxArea(height), 4);
}

TEST_F(Test011Solution, t2)
{
    vector<int> height = {1,1,3,1,1};
    ASSERT_EQ(sln.maxArea(height), 4);
}

TEST_F(Test011Solution, t3)
{
    vector<int> height = {3,1,3,1,1};
    ASSERT_EQ(sln.maxArea(height), 6);
}

TEST_F(Test011Solution, t4)
{
    vector<int> height = {3,1};
    ASSERT_EQ(sln.maxArea(height), 1);
}

TEST_F(Test011Solution, t5)
{
    vector<int> height = {2,3,4,5,18,17,6};
    ASSERT_EQ(sln.maxArea(height), 17);
}

GTEST_MAIN