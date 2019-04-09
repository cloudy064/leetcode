//
// Created by cloudy064 on 2018/7/20.
//

#include <vector>
#include <unordered_map>

#include "common.h"
#include <queue>

using namespace std;

/// Solution for https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		if (words.empty() || s.empty()) {
		    return {};
		}

        auto strLength = s.length();
		auto wordLength = words[0].length();

		auto needLength = wordLength * words.size();
		if (needLength > strLength) return {};

		unordered_map<string, int> wordCounts;
		for (auto word : words) {
            auto it = wordCounts.find(word);
            if (it != wordCounts.end()) {
                it->second += 1;
            } else {
                wordCounts.insert({word, 1});
            }
        }

        unordered_map<string, int> occurs;
		queue<string> temp;
		vector<int> positions;

		for (size_t i = 0; i < wordLength; i++) {
		    if (i + needLength > strLength) break;

		    while (!temp.empty()) temp.pop();

            occurs.clear();
            for (size_t j = i; j <= strLength - wordLength; j += wordLength) {
                auto sub = s.substr(j, wordLength);
                temp.push(sub);

                auto it = occurs.find(sub);
                if (it != occurs.end()) {
                    it->second += 1;
                } else {
                    occurs.insert({sub, 1});
                }

                if (temp.size() < words.size()) continue;

                if (occurs == wordCounts) {
                    positions.push_back(int(j - needLength + wordLength));
                }

                auto first = temp.front();
                temp.pop();

                it = occurs.find(first);
                if (it != occurs.end()) {
                    if (it->second == 1) {
                        occurs.erase(it);
                    } else {
                        it->second -= 1;
                    }
                }
            }
		}

		return positions;
	}
};

class Test030Solution : public ::testing::Test {
public:
	Solution sln;
};

TEST_F(Test030Solution, t1)
{
	vector<string> words = { "foo", "bar" };
	auto result = sln.findSubstring("barfoothefoobarman", words);
	ASSERT_EQ(result, vector<int>({ 0 ,9 }));
}

TEST_F(Test030Solution, t2)
{
	vector<string> words = { "word", "good" };
	auto result = sln.findSubstring("wordgoodstudentgoodword", words);
	ASSERT_EQ(result, vector<int>({ 0 ,15 }));
}

TEST_F(Test030Solution, t3)
{
	vector<string> words = { "aaa", "aaa" };
	auto result = sln.findSubstring("aaaaaa", words);
	ASSERT_EQ(result, vector<int>({ 0 }));
}

TEST_F(Test030Solution, t4)
{
	vector<string> words = { "ab", "ba", "ab", "ba" };
	auto result = sln.findSubstring("abaababbaba", words);
	ASSERT_EQ(result, vector<int>({ 1, 3 }));
}

GTEST_MAIN
