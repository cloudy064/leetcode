//
// Created by cloudy064 on 2019/2/19.
//

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/powx-n/

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) return x;
        if (n == 0) return 1;

        bool pos = n > 0 ? true : false;
        double result = 1;
        if (n == INT_MIN) {
            n = INT_MAX;
            result = x;
        }
        
        int abs = (n > 0 ? n : -n);
        if (abs % 2 == 0) {
            double res = myPow(x, abs / 2);
            result = res * res * result;
        } else {
            double res = myPow(x, (abs - 1) / 2);
            result = res * res * x * result;
        }
        
        return (pos ? result : 1 / result);
    }
};

class Test050Solution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(Test050Solution, t1) {
    EXPECT_EQ(sln.myPow(2,-2), 0.25);
    EXPECT_EQ(sln.myPow(2,2), 4);
}

GTEST_MAIN