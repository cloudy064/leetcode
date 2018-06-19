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

    string preparse(const string& p, string& pre_chars, vector<int>& pre_pattern) {
        char prev_c = '*';

        int length = 0;
        for (char c : p) {
            assert(prev_c != '*' || c != '*'); // valid pattern for this problem

            if (c == '*') {
                assert(!pre_chars.empty());
                assert(!pre_pattern.empty());
                pre_pattern.back() = P_REPEAT;
                if (length >= 2) {
                    if (pre_pattern[length - 2] == P_REPEAT) {
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
                }
            } else {
                pre_chars.push_back(c);
                pre_pattern.push_back(P_SINGLE);
                ++length;
            }

            prev_c = c;
        }

        string result;
        for (int i = 0; i < length; ++i) {
            result.push_back(pre_chars[i]);
            if (pre_pattern[i] == P_REPEAT) {
                result.push_back('*');
            }
        }

        return result;
    }

    bool isMatch(string s, string p) {
        assert(p.compare("*") != 0);

        string pre_chars;
        vector<int> pre_pattern;
        preparse(p, pre_chars, pre_pattern);
        
    }
};

class Test010Solution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(Test010Solution, negative) {
    string pre_chars;
    vector<int> pre_pattern;
    string result = sln.preparse(".*a*abc", pre_chars, pre_pattern);
    ASSERT_TRUE(result.compare(".*abc") == 0);

    pre_chars.clear();
    pre_pattern.clear();
    result = sln.preparse("a*a*abc", pre_chars, pre_pattern);
    ASSERT_TRUE(result.compare("a*abc") == 0);

    pre_chars.clear();
    pre_pattern.clear();
    result = sln.preparse("a*.*abc", pre_chars, pre_pattern);
    ASSERT_TRUE(result.compare(".*abc") == 0);
}

GTEST_MAIN