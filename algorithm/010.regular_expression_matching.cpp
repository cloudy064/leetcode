//
// Created by cloudy064 on 2018/6/19.
//

#include <list>
#include "common.h"

using namespace std;

class Solution {
public:
    const int P_SINGLE = 0;
    const int P_REPEAT = 1;

    void preparse(const string& p, string& pre_chars, vector<int>& pre_pattern, vector<int>& anchor) {
        char prev_c = '*';

        int length = 0;
        for (char c : p) {
            assert(prev_c != '*' || c != '*'); // valid pattern for this problem

            if (c == '*') {
                assert(!pre_chars.empty());
                assert(!pre_pattern.empty());
                pre_pattern.back() = P_REPEAT;
                if (length >= 2 && pre_pattern[length - 2] == P_REPEAT) {
                    if (pre_chars[length - 2] == '.'
                            || pre_chars[length - 2] == pre_chars[length - 1]) {
                        pre_chars.pop_back();
                        pre_pattern.pop_back();

                        --length;
                    } else if (pre_chars[length - 1] == '.') {
                        pre_chars.pop_back();
                        pre_pattern.pop_back();
                        pre_chars.back() = '.';

                        --length;
                    }
                }
            } else {
                pre_chars.push_back(c);
                pre_pattern.push_back(P_SINGLE);
                ++length;
				if (length >= 2 && pre_pattern[length - 2] == P_REPEAT)
				{
					if (pre_chars[length - 2] == pre_chars[length - 1])
					{
						pre_pattern[length - 2] = P_SINGLE;
						pre_pattern[length - 1] = P_REPEAT;
					}
				}
            }

            prev_c = c;
        }

		prev_c = pre_chars[0];
		int i = -1;
		while (++i < length && pre_chars[i] == '.' && pre_pattern[i] != P_REPEAT);
		if (i >= length) return;

		prev_c = pre_chars[i++];
		for (; i < length; ++i)
		{
			if (pre_chars[i] == prev_c) continue;
			if (pre_pattern[i] == P_REPEAT) continue;

			prev_c = pre_chars[i];
			anchor.push_back(i);
		}
    }

    bool isMatch(string s, string p) {
        assert(p.compare("*") != 0);

        string pre_chars;
        vector<int> pre_pattern;
		vector<int> anchor;
        preparse(p, pre_chars, pre_pattern, anchor);
		int s_idx = 0;
		int p_idx = 0;
		for (int i = 0; i < anchor.size(); ++i)
		{
			p_idx = anchor[i];
			char anchor_ch = pre_chars[p_idx];
			if (anchor_ch == '.')
			{
				++s_idx;
				continue;
			}

			for (; s_idx < s.length(); ++s_idx)
			{
				if (pre_pattern[p_idx] == P_REPEAT) break;

				if (s[s_idx] != pre_chars[p_idx])
				{
					if (p_idx == 0) return false;
					if (pre_chars[p_idx - 1] != '.') return false;
					continue;
				}
			}
		}
    }
};

class Test010Solution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(Test010Solution, negative) {

}

GTEST_MAIN