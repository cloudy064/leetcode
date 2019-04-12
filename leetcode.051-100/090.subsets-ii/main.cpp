//
//  main.cpp
//  leetcode.050-100
//
//  Created by 常永耘 on 2019/4/12.
//  Copyright © 2019 cloudy064. All rights reserved.
//

#include "common.h"

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.empty()) return {};
        
        sort(nums.begin(), nums.end());
        
        vector<pair<int, int>> limits;
        vector<pair<int, int>> appear;
        int last = nums[0];
        limits.push_back({nums[0], 1});
        appear.push_back({nums[0], 0});
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != last) {
                limits.push_back({nums[i], 1});
                appear.push_back({nums[i], 0});
                last = nums[i];
            } else {
                limits.back().second += 1;
            }
        }
        
        vector<vector<int>> result;
        vector<int> temp;
        while (true) {
            for (int i = 0; i <= limits[0].second; i++) {
                appear[0].second = i;
                
                temp.clear();
                for (int j = 0; j < appear.size(); j++) {
                    if (appear[j].second == 0) continue;
                    
                    temp.insert(temp.end(), appear[j].second, appear[j].first);
                }
                
                result.push_back(temp);
            }
            
            int k = 0;
            for (; k < appear.size(); k++) {
                if (appear[k].second < limits[k].second) {
                    appear[k].second++;
                    break;
                }
                
                appear[k].second = 0;
            }
            
            if (k == appear.size()) break;
        }
        
        return result;
    }
};

class TestSolution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(TestSolution, t1) {
    vector<int> nums = {1,2,2,1};
    vector<vector<int>> expect = {
        {},
        {1},
        {1,1},
        {2},
        {1,2},
        {1,1,2},
        {2,2},
        {1,2,2},
        {1,1,2,2}
    };
    
    auto result = sln.subsetsWithDup(nums);
    sort(expect.begin(), expect.end());
    sort(result.begin(), result.end());
    
    EXPECT_EQ(expect, result);
}

TEST_F(TestSolution, t2) {
    vector<int> nums;
    vector<vector<int>> expect = {
    };
    
    auto result = sln.subsetsWithDup(nums);
    sort(expect.begin(), expect.end());
    sort(result.begin(), result.end());
    
    EXPECT_EQ(expect, result);
}

TEST_F(TestSolution, t3) {
    vector<int> nums = {1};
    vector<vector<int>> expect = {
        {},
        {1}
    };
    
    auto result = sln.subsetsWithDup(nums);
    sort(expect.begin(), expect.end());
    sort(result.begin(), result.end());
    
    EXPECT_EQ(expect, result);
}

GTEST_MAIN
