//
//  main.cpp
//  leetcode.050-100
//
//  Created by 常永耘 on 2019/4/12.
//  Copyright © 2019 cloudy064. All rights reserved.
//

#include "common.h"

class Solution {
public:
    bool isValidNumber(const string& str) {
        if (str.empty()) return false;
        
        int len = str.length();
        if (len == 1) return true;
        if (len > 3) return false;
        
        if (str[0] == '0') return false;
        
        if (len == 2) return true;

        if (str[0] > '2') return false;
        if (str[0] == '1') return true;
        
        if (str[1] > '5') return false;
        if (str[1] < '5') return true;
            
        return str[2] <= '5';
    }
    
    void restoreIpAddressesImpl(const string& s, int length, string& prefix, int skip, int index, vector<string>& result) {
        if (index >= length) return;
        if (skip >= 4) return;
        if (skip == 3) {
            string temp = s.substr(index);
            if (!isValidNumber(temp)) return;
            
            prefix += '.';
            prefix.append(temp);
            result.push_back(prefix);
            
            return;
        }
        
        int left = length - index;
        if (left < 4 - skip) return;
        if (left > (4 - skip) * 3) return;
        
        int prefixSize = prefix.size();
        if (left == 4 - skip) {
            if (skip != 0) prefix += '.';
            
            for (int i = 0; i < 4 - skip; i++) {
                if (i != 0) prefix += '.';
                prefix += s[index + i];
            }
            
            result.push_back(prefix);
            prefix.resize(prefixSize);
            return;
        }
        
        if (left == (4 - skip) * 3) {
            if (skip != 0) prefix += '.';
            for (int i = 0; i < 4 - skip; i++) {
                if (i != 0) prefix += '.';
                
                string sub = s.substr(index + i * 3, 3);
                if (!isValidNumber(sub)) return;
                prefix += sub;
            }
            
            result.push_back(prefix);
            prefix.resize(prefixSize);
            return;
        }
        
        if (skip != 0) prefix += '.';
        prefix += s[index];
        restoreIpAddressesImpl(s, length, prefix, skip + 1, index + 1, result);
        
        if (index + 1 >= length) return;
        if (s[index] == '0') return;
        
        prefix.resize(prefixSize);
        
        if (skip != 0) prefix += '.';
        prefix += s[index];
        prefix += s[index + 1];
        restoreIpAddressesImpl(s, length, prefix, skip + 1, index + 2, result);
        
        if (index + 2 >= length) return;
        if (s[index] > '2') return;
        if (s[index] == '2') {
            if (s[index + 1] > '5') return;
            if (s[index + 1] == '5' && s[index + 2] > '5') return;
        }
        
        prefix.resize(prefixSize);
        
        if (skip != 0) prefix += '.';
        prefix += s[index];
        prefix += s[index + 1];
        prefix += s[index + 2];
        restoreIpAddressesImpl(s, length, prefix, skip + 1, index + 3, result);
    }
    
    vector<string> restoreIpAddresses(string s) {
        int length = s.length();
        
        if (length < 4 || length > 12) return {};
        vector<string> result;
        string prefix;
        restoreIpAddressesImpl(s, length, prefix, 0, 0, result);
        
        return result;
    }
};

class TestSolution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(TestSolution, t1) {
    auto result = sln.restoreIpAddresses("0000");
    vector<string> expect = {"0.0.0.0"};
    sort(result.begin(), result.end());
    sort(expect.begin(), expect.end());
    EXPECT_EQ(result, expect);
}

TEST_F(TestSolution, t2) {
    auto result = sln.restoreIpAddresses("00000");
    vector<string> expect;
    sort(result.begin(), result.end());
    sort(expect.begin(), expect.end());
    EXPECT_EQ(result, expect);
}

TEST_F(TestSolution, t3) {
    auto result = sln.restoreIpAddresses("255255255255");
    vector<string> expect = {"255.255.255.255"};
    sort(result.begin(), result.end());
    sort(expect.begin(), expect.end());
    EXPECT_EQ(result, expect);
}

TEST_F(TestSolution, t4) {
    auto result = sln.restoreIpAddresses("25525511135");
    vector<string> expect = {"255.255.11.135", "255.255.111.35"};
    sort(result.begin(), result.end());
    sort(expect.begin(), expect.end());
    EXPECT_EQ(result, expect);
}

TEST_F(TestSolution, t5) {
    auto result = sln.restoreIpAddresses("010010");
    vector<string> expect = {"0.10.0.10","0.100.1.0"};
    sort(result.begin(), result.end());
    sort(expect.begin(), expect.end());
    EXPECT_EQ(result, expect);
}

GTEST_MAIN

