//
// Created by ≥£”¿‘≈ on 2019/2/21.
//

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/merge-intervals/


class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		if (intervals.empty()) return {};
		if (intervals.size() == 1) return intervals;

		sort(intervals.begin(), intervals.end(), [](Interval lhs, Interval rhs)
		{
			return lhs.start < rhs.start;
		});

		vector<Interval> result;
		int start = intervals[0].start;
		int end = intervals[0].end;
		for (const auto item : intervals)
		{
			if (item.start <= end)
			{
				end = max(end, item.end);
			}
			else
			{
				result.emplace_back(Interval(start, end));
				start = item.start;
				end = item.end;
			}
		}

		result.emplace_back(Interval(start, end));

		return result;
	}
};

class Test056Solution : public ::testing::Test {
public:
	Solution sln;
};

TEST_F(Test056Solution, t1) {
	vector<Interval> input = {
		Interval(1, 3),
		Interval(2, 6),
		Interval(8, 10),
		Interval(15, 18)
	};

	vector<Interval> expect = {
		Interval(1, 6),
		Interval(8, 10),
		Interval(15, 18)
	};

	auto result = sln.merge(input);

	EXPECT_EQ(result, expect);
}

TEST_F(Test056Solution, t2) {
	vector<Interval> input = {
		Interval(1, 4),
		Interval(4, 5),
	};

	vector<Interval> expect = {
		Interval(1, 5),
	};

	auto result = sln.merge(input);

	EXPECT_EQ(result, expect);
}

TEST_F(Test056Solution, t3) {
	vector<Interval> input = {
		
	};

	vector<Interval> expect = {
	
	};

	auto result = sln.merge(input);

	EXPECT_EQ(result, expect);
}

TEST_F(Test056Solution, t4) {
	vector<Interval> input = {
		Interval(1, 9),
		Interval(4, 5),
	};

	vector<Interval> expect = {
		Interval(1, 9),
	};

	auto result = sln.merge(input);

	EXPECT_EQ(result, expect);
}

TEST_F(Test056Solution, t5) {
	vector<Interval> input = {
		Interval(1, 9)
	};

	vector<Interval> expect = {
		Interval(1, 9),
	};

	auto result = sln.merge(input);

	EXPECT_EQ(result, expect);
}

GTEST_MAIN