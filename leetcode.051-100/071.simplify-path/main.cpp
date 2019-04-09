//
// Created by cloudy064 on 2019/4/8.
//

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/simplify-path/


class Solution {
public:
	void movePath(vector<string>& files, string& file) {
		if (file.empty()) return;

		if (file == "..") {
			if (!files.empty()) files.pop_back();
		}
		else if (file != ".") {
			files.push_back(file);
		}

		file.clear();
	}

	string simplifyPath(string path) {
		vector<string> files;
		string file;

		for (auto c : path) {
			if (c == '/') {
				movePath(files, file);
				continue;
			}

			file += c;
		}

		movePath(files, file);

		string result;
		for (auto s : files) {
			result += "/";
			result += s;
		}

		if (result.empty()) result = "/";

		return result;
	}
};

class Test071Solution : public ::testing::Test {
public:
	Solution sln;
};

TEST_F(Test071Solution, t1) {
	EXPECT_EQ(sln.simplifyPath("/home/"), "/home");
	EXPECT_EQ(sln.simplifyPath("/../"), "/");
	EXPECT_EQ(sln.simplifyPath("/home//foo/"), "/home/foo");
	EXPECT_EQ(sln.simplifyPath("/a/./b/../../c/"), "/c");
	EXPECT_EQ(sln.simplifyPath("/a//b////c/d//././/.."), "/a/b/c");
}

GTEST_MAIN