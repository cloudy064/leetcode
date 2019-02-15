//
// Created by 常永耘 on 2019/2/15.
//

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/count-and-say/

class Solution {
public:
    string count(string& str) {
        char prev = '\0';
        int count = 0;
        string result = "";
        for (auto c : str) {
            if (c == prev) {
                ++count;
            } else {
                if (count != 0) {
                    result += ('0' + count);
                    result += prev;
                }

                count = 1;
            }

            prev = c;
        }

        result += ('0' + count);
        result += prev;

        return result;
    }

    string countAndSay(int n) {
        string str = "1";
        for (int i = 1; i < n; ++i) {
            str = count(str);
        }

        return str;
    }
};

class Test038Solution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(Test038Solution, t1) {
    ASSERT_EQ(sln.countAndSay(1), "1");
    ASSERT_EQ(sln.countAndSay(2), "11");
    ASSERT_EQ(sln.countAndSay(3), "21");
    ASSERT_EQ(sln.countAndSay(4), "1211");
    ASSERT_EQ(sln.countAndSay(5), "111221");
    ASSERT_EQ(sln.countAndSay(6), "312211");
    ASSERT_EQ(sln.countAndSay(7), "13112221");
    ASSERT_EQ(sln.countAndSay(8), "1113213211");
    ASSERT_EQ(sln.countAndSay(9), "31131211131221");
    ASSERT_EQ(sln.countAndSay(10), "13211311123113112211");
}

GTEST_MAIN