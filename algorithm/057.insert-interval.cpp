//
// Created by ≥£”¿‘≈ on 2019/2/21.
//

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/insert-interval/

class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		if (intervals.empty()) return { newInterval };

		vector<Interval> result;
		int size = intervals.size();
		if (intervals[0].start > newInterval.end)
		{
			result.emplace_back(newInterval);
			result.insert(result.end(), intervals.begin(), intervals.end());
			return result;
		}

		if (intervals[size - 1].end < newInterval.start)
		{
			result.insert(result.end(), intervals.begin(), intervals.end());
			result.emplace_back(newInterval);
			return result;
		}

		auto it = intervals.begin();
		int start;
		int end;
		for (; it != intervals.end(); ++it)
		{
			const auto& item = *it;
			if (newInterval.start > item.end)
			{
				result.emplace_back(item);
			}
			else if (newInterval.end < item.start)
			{
				result.emplace_back(newInterval);
				result.insert(result.end(), it, intervals.end());
				return result;
			}
			else 
			{
				start = min(item.start, newInterval.start);
				end = max(item.end, newInterval.end);
				break;
			}
		}

		for (; it != intervals.end(); ++it)
		{
			const auto& item = *it;
			if (end < item.start)
			{
				result.emplace_back(Interval(start, end));
				break;
			}
			
			if (end <= item.end)
			{
				end = item.end;
			}
		}

		if (it != intervals.end())
		{
			result.insert(result.end(), it, intervals.end());
		}
		else
		{
			result.emplace_back(Interval(start, end));
		}
		return result;
	}
};

class Test057Solution : public ::testing::Test {
public:
	Solution sln;
};

TEST_F(Test057Solution, t1) {
	vector<Interval> input = {
		Interval(1, 3),
		Interval(6, 9)
	};

	const Interval newInterval(2, 5);

	vector<Interval> expect = {
		Interval(1, 5),
		Interval(6, 9),
	};

	auto result = sln.insert(input, newInterval);

	EXPECT_EQ(result, expect);
}

TEST_F(Test057Solution, t2) {
	vector<Interval> input = {
		Interval(1, 2),
		Interval(3, 5),
		Interval(6, 7),
		Interval(8, 10),
		Interval(12, 16),
	};

	const Interval newInterval(4, 8);

	vector<Interval> expect = {
		Interval(1, 2),
		Interval(3, 10),
		Interval(12, 16)
	};

	auto result = sln.insert(input, newInterval);

	EXPECT_EQ(result, expect);
}

TEST_F(Test057Solution, t3) {
	vector<Interval> input = {
		Interval(1, 2),
		Interval(3, 5),
		Interval(6, 7),
		Interval(8, 10),
		Interval(12, 16),
	};

	const Interval newInterval(16, 18);

	vector<Interval> expect = {
		Interval(1, 2),
		Interval(3, 5),
		Interval(6, 7),
		Interval(8, 10),
		Interval(12, 18),
	};

	auto result = sln.insert(input, newInterval);

	EXPECT_EQ(result, expect);
}

TEST_F(Test057Solution, t4) {
	vector<Interval> input = {
		Interval(1, 2),
		Interval(3, 5),
		Interval(6, 7),
		Interval(8, 10),
		Interval(12, 16),
	};

	const Interval newInterval(0, 1);

	vector<Interval> expect = {
		Interval(0, 2),
		Interval(3, 5),
		Interval(6, 7),
		Interval(8, 10),
		Interval(12, 16),
	};

	auto result = sln.insert(input, newInterval);

	EXPECT_EQ(result, expect);
}

TEST_F(Test057Solution, t5) {
	vector<Interval> input = {
	};

	const Interval newInterval(0, 1);

	vector<Interval> expect = {
		Interval(0, 1),
	};

	auto result = sln.insert(input, newInterval);

	EXPECT_EQ(result, expect);
}

TEST_F(Test057Solution, t6) {
	vector<Interval> input = {
		Interval(4, 5)
	};

	const Interval newInterval(0, 1);

	vector<Interval> expect = {
		Interval(0, 1),
		Interval(4, 5),
	};

	auto result = sln.insert(input, newInterval);

	EXPECT_EQ(result, expect);
}

TEST_F(Test057Solution, t7) {
	vector<Interval> input = {
		Interval(1, 3),
		Interval(4, 5)
	};

	const Interval newInterval(0, 9);

	vector<Interval> expect = {
		Interval(0, 9)
	};

	auto result = sln.insert(input, newInterval);

	EXPECT_EQ(result, expect);
}

TEST_F(Test057Solution, t8) {
	vector<Interval> input = {
		Interval(1, 3),
		Interval(4, 5)
	};

	const Interval newInterval(3, 4);

	vector<Interval> expect = {
		Interval(1, 5)
	};

	auto result = sln.insert(input, newInterval);

	EXPECT_EQ(result, expect);
}

TEST_F(Test057Solution, t9) {
	vector<Interval> input = {
		Interval(2, 3),
		Interval(4, 5)
	};

	const Interval newInterval(0, 1);

	vector<Interval> expect = {
		Interval(0, 1),
		Interval(2, 3),
		Interval(4, 5)
	};

	auto result = sln.insert(input, newInterval);

	EXPECT_EQ(result, expect);
}

TEST_F(Test057Solution, t10) {
	vector<Interval> input = {
		Interval(0, 1),
		Interval(4, 5)
	};

	const Interval newInterval(2, 3);

	vector<Interval> expect = {
		Interval(0, 1),
		Interval(2, 3),
		Interval(4, 5)
	};

	auto result = sln.insert(input, newInterval);

	EXPECT_EQ(result, expect);
}

TEST_F(Test057Solution, t11) {
	vector<Interval> input = {
		Interval(0, 1),
		Interval(2, 3)
	};

	const Interval newInterval(4, 5);

	vector<Interval> expect = {
		Interval(0, 1),
		Interval(2, 3),
		Interval(4, 5)
	};

	auto result = sln.insert(input, newInterval);

	EXPECT_EQ(result, expect);
}

GTEST_MAIN