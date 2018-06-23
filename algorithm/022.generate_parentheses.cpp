//
// Created by cloudy064 on 2018/6/22.
//


#include <algorithm>
#include <unordered_map>
#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/generate-parentheses/description/

// *time exceed

class Solution {
public:
    void permutation_core(vector<int>& digits, int from, int size, set<vector<int>>& result, int count_p_1, int count_n_1) {
		if (digits.empty()) return;
		if (*(digits.begin()) == -1) return;
		if (*(digits.end() - 1) == 1) return;

		if (count_n_1 > count_p_1) return;

        if (from == size) {
            result.insert(digits);
        } else {
			for (int i = from; i < size; ++i) {
				if (i == from)
				{
					if (digits[i] == 1)
						count_p_1 += 1;
					else
						count_n_1 += 1;
					permutation_core(digits, i + 1, size, result, count_p_1, count_n_1);
				}
				else if (digits[i] != digits[from])
				{
					swap(digits[i], digits[from]);
					if (digits[i] == 1)
						count_p_1 += 1;
					else
						count_n_1 += 1;
					permutation_core(digits, from + 1, size, result, count_p_1, count_n_1);
					swap(digits[i], digits[from]);
				}
            }
        }
    }

    void permutation(vector<int>& digits, set<vector<int>>& result) {
        permutation_core(digits, 0, digits.size(), result, 0, 0);
    }

    vector<string> generateParenthesis(int n) {
		if (n <= 0) return {""};
        vector<int> digits;
        digits.reserve(2 * n);
        digits.insert(digits.end(), n, 1);
        digits.insert(digits.end(), n, -1);
        set<vector<int>> result;
        permutation(digits, result);

        vector<string> p;

        for (auto it = result.begin(); it != result.end(); ++it) {
            auto v = *it;
            int sum = 0;
            string temp;
            for (int j = 0; j < v.size(); ++j) {
                int k = v[j];
                sum  += k;
                if (sum < 0) break;
                if (k == -1) {
                    temp.push_back(')');
                } else {
                    temp.push_back('(');
                }
            }

            if (sum == 0) {
                p.push_back(temp);
            }
        }

        return p;
    }
};



class Test022Solution : public ::testing::Test {
public:
	Solution sln;
};

TEST_F(Test022Solution, t1)
{
	set<string> expect = {
		"()()()",
		"()(())",
		"(())()",
		"((()))",
		"(()())"
	};

	auto result = sln.generateParenthesis(3);
	ASSERT_EQ(expect.size(), result.size());
	set<string> result_set;
	for (auto& item : result)
	{
		result_set.insert(item);
	}

	ASSERT_EQ(expect, result_set);
}

TEST_F(Test022Solution, t2)
{
	set<string> expect = {
		"()()",
		"(())",
	};

	auto result = sln.generateParenthesis(2);
	ASSERT_EQ(expect.size(), result.size());
	set<string> result_set;
	for (auto& item : result)
	{
		result_set.insert(item);
	}

	ASSERT_EQ(expect, result_set);
}

TEST_F(Test022Solution, t3)
{
	set<string> expect = {
		"()"
	};

	auto result = sln.generateParenthesis(1);
	ASSERT_EQ(expect.size(), result.size());
	set<string> result_set;
	for (auto& item : result)
	{
		result_set.insert(item);
	}

	ASSERT_EQ(expect, result_set);
}

TEST_F(Test022Solution, t4)
{
	set<string> expect = {""};

	auto result = sln.generateParenthesis(0);
	ASSERT_EQ(expect.size(), result.size());
	set<string> result_set;
	for (auto& item : result)
	{
		result_set.insert(item);
	}

	ASSERT_EQ(expect, result_set);
}

TEST_F(Test022Solution, t5)
{
	set<string> expect = {
		"(((())))",
		"((()()))",
		"((())())",
		"((()))()",
		"(()(()))",
		"(()()())",
		"(()())()",
		"(())(())",
		"(())()()",
		"()((()))",
		"()(()())",
		"()(())()",
		"()()(())",
		"()()()()" 
	};

	auto result = sln.generateParenthesis(4);
	ASSERT_EQ(expect.size(), result.size());
	set<string> result_set;
	for (auto& item : result)
	{
		result_set.insert(item);
	}

	ASSERT_EQ(expect, result_set);
}

TEST_F(Test022Solution, t6)
{
	auto start = clock();
	sln.generateParenthesis(8);
	auto end = clock();
	ASSERT_LT(end - start, 1000);
}

GTEST_MAIN