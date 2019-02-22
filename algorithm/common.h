#pragma once


#ifndef COMMON_H
#define COMMON_H

#include "gtest/gtest.h"
#include <vector>
#include <algorithm>

using namespace std;

#ifdef WIN32

#define GTEST_MAIN

#else

#define GTEST_MAIN     \
    int main(int argc, char *argv[]) {\
        testing::InitGoogleTest(&argc, argv);\
        return RUN_ALL_TESTS();\
    }

#endif

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}

	bool operator==(const Interval& rhs) const {
		return start == rhs.start && end == rhs.end;
	}
};

ListNode* newNodes(const vector<int>& nums);

void deleteNodes(ListNode* node);

bool equalNodes(ListNode* node1, ListNode* node2);

#endif //COMMON_H