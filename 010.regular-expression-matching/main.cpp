//
// Created by cloudy064 on 2018/6/19.
//

#include <list>
#include "common.h"

using namespace std;

class Solution {
public:
    bool isMatchCore(string s, string p, int s_index, int p_index)
    {
        if (p_index >= p.length())
        {
            return s_index >= s.length();
        }

        if (s_index >= s.length())
        {
            if ((p.length() - p_index) % 2 != 0) return false;

            for (int i = p_index; i < p.length(); i += 2)
            {
                if (i + 1 >= p.length()) return false;

                if (p[i + 1] != '*') return false;
            }

            return true;
        }

        if (p_index + 1 < p.length() && p[p_index + 1] == '*')
        {
            if (isMatchCore(s, p, s_index, p_index + 2)) return true;

            if (p[p_index] == s[s_index] || p[p_index] == '.')
            {
                return isMatchCore(s, p, s_index + 1, p_index);
            }

            return false;
        }
        else
        {
            if (p[p_index] == s[s_index] || p[p_index] == '.')
            {
                return isMatchCore(s, p, s_index + 1, p_index + 1);
            }

            return false;
        }
    }

    bool isMatch(string s, string p) {
        assert(p.compare("*") != 0);

        return isMatchCore(s, p, 0, 0);
    }
};

class Test010Solution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(Test010Solution, t1) {
    ASSERT_FALSE(sln.isMatch("aa", "a"));
}

TEST_F(Test010Solution, t2) {
    ASSERT_TRUE(sln.isMatch("aa", "a*"));
}

TEST_F(Test010Solution, t3) {
    ASSERT_TRUE(sln.isMatch("ab", ".*"));
}

TEST_F(Test010Solution, t4) {
    ASSERT_TRUE(sln.isMatch("aab", "c*a*b"));
}

TEST_F(Test010Solution, t5) {
    ASSERT_FALSE(sln.isMatch("acaabbaccbbacaabbbb", "a*.*b*.*a*aa*a*"));
}

TEST_F(Test010Solution, t6) {
    ASSERT_TRUE(sln.isMatch("", "c*c*"));
}

TEST_F(Test010Solution, t7) {
    ASSERT_TRUE(sln.isMatch("", ".*"));
}

TEST_F(Test010Solution, t8) {
    ASSERT_TRUE(sln.isMatch("", ""));
}

GTEST_MAIN