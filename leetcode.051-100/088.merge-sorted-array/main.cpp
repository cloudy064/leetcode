//
// Created by cloudy064 on 2019/4/9.
//

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/partition-list/


class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i = m - 1;
		int j = n - 1;
		int k = m + n - 1;

		while (i >= 0 || j >= 0) {
			if (i < 0) {
				nums1[k--] = nums2[j--];
				continue;
			}

			if (j < 0) {
				nums1[k--] = nums1[i--];
				continue;
			}

			if (nums1[i] > nums2[j]) {
				nums1[k--] = nums1[i--];
			}
			else {
				nums1[k--] = nums2[j--];
			}
		}
	}
};

class TestSolution : public ::testing::Test {
public:
	Solution sln;
};

TEST_F(TestSolution, t1) {
	vector<int> nums1 = { 1,2,3,0,0,0 };
	vector<int> nums2 = { 2,5,6 };
	vector<int> expect = { 1,2,2,3,5,6 };
	sln.merge(nums1, 3, nums2, 3);
	EXPECT_EQ(nums1, expect);
}

TEST_F(TestSolution, t2) {
	vector<int> nums1 = { 1,2,3 };
	vector<int> nums2 = { };
	vector<int> expect = { 1,2,3};
	sln.merge(nums1, 3, nums2, 0);
	EXPECT_EQ(nums1, expect);
}

TEST_F(TestSolution, t3) {
	vector<int> nums1 = { 1,2,3,0,0,0 };
	vector<int> nums2 = { 4,5,6 };
	vector<int> expect = { 1,2,3,4,5,6 };
	sln.merge(nums1, 3, nums2, 3);
	EXPECT_EQ(nums1, expect);
}

GTEST_MAIN
