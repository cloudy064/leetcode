//
// Created by 常永耘 on 2019/2/15.
//

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/jump-game-ii/

class Solution {
public:
    bool jumpImpl(vector<int>& nums, int target, int step, int& maxStep) {
        if (target == 0) {
            maxStep = step;
            return true;
        }

        step += 1;
        if (step >= maxStep) return false;

        vector<int> poss;
        for (int i = 0; i < target; i++) {
            int diff = target - i;
            if (nums[i] >= diff) {
                if (jumpImpl(nums, i, step, maxStep)) return true;
            }
        }

        return false;
    }

    int jump(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return 0;
        int reach = 0;
        int nextreach = nums[0];
        int step = 0;
        for(int i = 0;i<len;i++){
            nextreach = max(i+nums[i],nextreach);
            if(nextreach >= len-1) return (step+1);
            if(i == reach){
                step++;
                reach = nextreach;
            }
        }
        return step;
    }
};

class Test045Solution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(Test045Solution, t1) {
    vector<int> nums = {4,1,5,3,1,1,4};
    ASSERT_EQ(sln.jump(nums), 2);
}

TEST_F(Test045Solution, t2) {
    vector<int> nums = {10,3,1,1,4};
    ASSERT_EQ(sln.jump(nums), 1);
}

TEST_F(Test045Solution, t3) {
    vector<int> nums = {10};
    ASSERT_EQ(sln.jump(nums), 0);
}

TEST_F(Test045Solution, t4) {
    vector<int> nums = {8,2,4,4,4,9,5,2,5,8,8,0,8,6,9,1,1,6,3,5,1,2,6,6,0,4,8,6,0,3,2,8,7,6,5,1,7,0,3,4,8,3,5,9,0,4,0,1,0,5,9,2,0,7,0,2,1,0,8,2,5,1,2,3,9,7,4,7,0,0,1,8,5,6,7,5,1,9,9,3,5,0,7,5};
    ASSERT_EQ(sln.jump(nums), 13);
}

GTEST_MAIN