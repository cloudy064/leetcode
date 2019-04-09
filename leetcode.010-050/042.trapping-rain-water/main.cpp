//
// Created by cloudy064 on 2019/4/9.
//

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/trapping-rain-water/

class Solution {
public:
	void fillInvalidArea(vector<int>& height, int& first, int& last) {
		int size = height.size();

		first = 0;
		last = size - 1;
		while (first < last) {
			if (height[first] > height[first + 1]) break;

			first++;
		}

		for (int i = 0; i < first; i++) height[i] = height[first];

		while (last >= 1) {
			if (height[last] > height[last - 1]) break;

			last--;
		}

		for (int i = size - 1; i > last; i--) height[i] = height[last];
	}

	int trap(vector<int>& height) {
		int size = height.size();
		if (size <= 2) return 0;

		int first = 0;
		int last = height.size() - 1;
		int count = 0;
		while (true) {
			fillInvalidArea(height, first, last);

			if (first + 1 >= last)  return count;

			int i = first;

			while (i < last) {
				int prevMax = i;
				while (i < last && height[i + 1] <= height[i]) { // find down
					i++;
				}

				while (i < last && height[i + 1] > height[i]) {
					i++;
				}

				int newMax = i;

				int upper = min(height[prevMax], height[newMax]);

				for (int j = prevMax + 1; j < newMax; j++) {
					if (height[j] > upper) continue;

					count += (upper - height[j]);
					height[j] = upper; // fill this area
				}
			}
		}
	}
};

class TestSolution : public ::testing::Test {
public:
	Solution sln;
};

TEST_F(TestSolution, t1) {
	vector<int> nums = { 1,0,1 };
	EXPECT_EQ(sln.trap(nums), 1);
}

TEST_F(TestSolution, t2) {
	vector<int> nums = { 1,0,1,0,1 };
	EXPECT_EQ(sln.trap(nums), 2);
}

TEST_F(TestSolution, t3) {
	vector<int> nums = { 0,0,1,1,0,1,0,1,1,0,0 };
	EXPECT_EQ(sln.trap(nums), 2);
}

TEST_F(TestSolution, t4) {
	vector<int> nums = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	EXPECT_EQ(sln.trap(nums), 6);
}

TEST_F(TestSolution, t5) {
	vector<int> nums = { 3,2,1,0,1,2,1,0,1,2,3 };
	EXPECT_EQ(sln.trap(nums), 17);
}

TEST_F(TestSolution, t6) {
	vector<int> nums = { 5,4,1,2 };
	EXPECT_EQ(sln.trap(nums), 1);
}

GTEST_MAIN