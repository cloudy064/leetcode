//
// Created by cloudy064 on 2019/4/9.
//

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/partition-list/


class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		if (head == nullptr || head->next == nullptr) return head;

		ListNode* prev = head;
		ListNode* node = head;

		if (head->val >= x) {
			while (node != nullptr) {
				if (node->val < x) break;

				prev = node;
				node = node->next;
			}

			if (node == nullptr) return head;

			prev->next = node->next;
			node->next = head;
			head = node;
		}

		node = prev->next;
		ListNode* lastLower = head;

		while (node != nullptr) {
			if (node->val < x) {
				if (lastLower->next == node) {
					lastLower = node;
				}
				else {
					prev->next = node->next;
					node->next = lastLower->next;
					lastLower->next = node;
					node = prev->next;
					lastLower = lastLower->next;
					continue;
				}
			}

			prev = node;
			node = node->next;
		}

		return head;
	}
};

class TestSolution : public ::testing::Test {
public:
	Solution sln;
};

TEST_F(TestSolution, t1) {
	auto expect = newNodes(vector<int>({ 1,2,2,4,3,5 }));
	ListNode* nodes = newNodes(vector<int>({ 1,4,3,2,5,2 }));
	auto head = sln.partition(nodes, 3);
	ASSERT_TRUE(equalNodes(head, expect));
	deleteNodes(head);
	deleteNodes(expect);
}

TEST_F(TestSolution, t2) {
	auto expect = newNodes(vector<int>({}));
	ListNode* nodes = newNodes(vector<int>({ }));
	auto head = sln.partition(nodes, 1);
	ASSERT_TRUE(equalNodes(head, expect));
	deleteNodes(head);
	deleteNodes(expect);
}

TEST_F(TestSolution, t3) {
	auto expect = newNodes(vector<int>({ 0,1,2,3 }));
	ListNode* nodes = newNodes(vector<int>({ 0,1,2,3 }));
	auto head = sln.partition(nodes, 4);
	ASSERT_TRUE(equalNodes(head, expect));
	deleteNodes(head);
	deleteNodes(expect);
}

TEST_F(TestSolution, t4) {
	auto expect = newNodes(vector<int>({ 0,1,2,3 }));
	ListNode* nodes = newNodes(vector<int>({ 0,1,2,3 }));
	auto head = sln.partition(nodes, -1);
	ASSERT_TRUE(equalNodes(head, expect));
	deleteNodes(head);
	deleteNodes(expect);
}

TEST_F(TestSolution, t5) {
	auto expect = newNodes(vector<int>({ 1,-1,2,1,3,5 }));
	ListNode* nodes = newNodes(vector<int>({ 1,3,-1,5,2,1 }));
	auto head = sln.partition(nodes, 3);
	ASSERT_TRUE(equalNodes(head, expect));
	deleteNodes(head);
	deleteNodes(expect);
}

GTEST_MAIN
