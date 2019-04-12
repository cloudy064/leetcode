//
//  main.cpp
//  089.gray-code
//
//  Created by cloudy064 on 2019/4/12.
//  Copyright © 2019 cloudy064. All rights reserved.
//

#include "common.h"

class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 0) return {0};
        
        long limit = 1 << n;
        vector<int> result(limit, 0);
        for (int i = 0; i < limit; i++) {
            result[i] = i ^ (i >> 1);
        }
        
        return result;
    }
};

class TestSolution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(TestSolution, t1) {
    vector<int> expect = {};
    
    EXPECT_EQ(sln.grayCode(0), expect);
}

TEST_F(TestSolution, t2) {
    vector<int> expect = {0,1,3,2};
    
    EXPECT_EQ(sln.grayCode(2), expect);
}

TEST_F(TestSolution, t3) {
    vector<int> expect = { 0,1,3,2,6,7,5,4 };
    
    EXPECT_EQ(sln.grayCode(3), expect);
}

GTEST_MAIN
