//
// Created by 常永耘 on 2018/6/17.
//

#include <iostream>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return 0;
    }
};


class TestSolution : public ::testing::Test {
public:
    Solution sln;
};


GTEST_API_ int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
