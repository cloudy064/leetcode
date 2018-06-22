//
// Created by cloudy064 on 2018/6/22.
//


#include <algorithm>
#include <unordered_map>
#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/generate-parentheses/description/

class Solution {
public:
    void permutation_core(vector<int>& digits, vector<int>::iterator begin, vector<int>::iterator end, vector<vector<int>>& result) {
        if (begin == end) {
            result.push_back(digits);
        } else {
            for (auto it = begin; it != end; ++it) {
                swap(*it, *begin);
                permutation_core(digits, it, end, result);
                swap(*it, *begin);
            }
        }
    }

    void permutation(vector<int>& digits, vector<vector<int>>& result) {
        permutation_core(digits, digits.begin(), digits.end(), result);
    }

    vector<string> generateParenthesis(int n) {
        vector<int> digits;
        digits.reserve(2 * n);
        digits.insert(digits.end(), n, 1);
        digits.insert(digits.end(), n, -1);
        vector<vector<int>> result;
        permutation(digits, result);

        vector<string> p;

        for (int i = 0; i < result.size(); ++i) {
            auto v = result[i];
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

}


GTEST_MAIN