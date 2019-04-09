//
// Created by cloudy064 on 2019/4/9.
//

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/


class Solution {
public:
	int skipDuplicates(ListNode*& node) {
		if (node == nullptr) return 1;

		ListNode* first = node;
		int currVal = node->val;
		int count = 1;

		node = node->next;
		while (node != nullptr && first->val == node->val) {
			count++;
			node = node->next;
		}

		return count;
	}

	ListNode* nextNode(ListNode*& curr) {
		if (curr == nullptr) return curr;

		int count = 0;
		ListNode* node = nullptr;

		do {
			node = curr;
			count = skipDuplicates(curr);
		} while (count > 1);
		
		return node;
	}

	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return head;

		ListNode* first = nextNode(head);
		ListNode* node = first;
		while (node != nullptr) {
			node->next = nextNode(head);
			node = node->next;
		}

		return first;
	}
};

class TestSolution : public ::testing::Test {
public:
	Solution sln;
};

TEST_F(TestSolution, t1) {
	auto expect = newNodes(vector<int>({2}));
	ListNode* nodes = newNodes(vector<int>({0,0,1,1,1,1,2,3,3}));
	auto head = sln.deleteDuplicates(nodes);
	ASSERT_TRUE(equalNodes(head, expect));
	deleteNodes(head);
	deleteNodes(expect);
}

TEST_F(TestSolution, t2) {
	auto expect = newNodes(vector<int>({}));
	ListNode* nodes = newNodes(vector<int>({ }));
	auto head = sln.deleteDuplicates(nodes);
	ASSERT_TRUE(equalNodes(head, expect));
	deleteNodes(head);
	deleteNodes(expect);
}

TEST_F(TestSolution, t3) {
	auto expect = newNodes(vector<int>({ 0,1,2,3 }));
	ListNode* nodes = newNodes(vector<int>({ 0,1,2,3 }));
	auto head = sln.deleteDuplicates(nodes);
	ASSERT_TRUE(equalNodes(head, expect));
	deleteNodes(head);
	deleteNodes(expect);
}

TEST_F(TestSolution, t4) {
	auto expect = newNodes(vector<int>({ 2,3 }));
	ListNode* nodes = newNodes(vector<int>({ 1,1,1,2,3 }));
	auto head = sln.deleteDuplicates(nodes);
	ASSERT_TRUE(equalNodes(head, expect));
	deleteNodes(head);
	deleteNodes(expect);
}

GTEST_MAIN
