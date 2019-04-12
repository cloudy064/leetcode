//
//  main.cpp
//  091.decode-ways
//
//  Created by 常永耘 on 2019/4/12.
//  Copyright © 2019 cloudy064. All rights reserved.
//

#include "common.h"

class Solution {
public:
    int numDecodingsImpl(const string& s, const int length, int index) {
        if (index > length) return 0;
        if (index == length) return 1;
        if (s[index] == '0') return 0;
        
        if (s[index] == '1') {
            return numDecodingsImpl(s, length, index + 1) + numDecodingsImpl(s, length, index + 2);
        }
        
        if (s[index] == '2') {
            if (index + 1 >= length) {
                return 1; // no more characters
            }
            
            if (s[index + 1] <= '6') {
                return numDecodingsImpl(s, length, index + 1) + numDecodingsImpl(s, length, index + 2);
            }
        }
        
        return numDecodingsImpl(s, length, index + 1);
    }
    
    int numDecodings(string s) {
        if (s.empty()) return 0;
        
        return numDecodingsImpl(s, s.length(), 0);
    }
};

class TestSolution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(TestSolution, t1) {
    EXPECT_EQ(sln.numDecodings(""), 0);
    EXPECT_EQ(sln.numDecodings("12"), 2);
    EXPECT_EQ(sln.numDecodings("226"), 3);
    EXPECT_EQ(sln.numDecodings("0"), 0);
}

GTEST_MAIN
