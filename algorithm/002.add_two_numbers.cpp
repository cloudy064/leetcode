//
// Created by cloudy064 on 2018/6/17.
//

#include <iostream>

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/add-two-numbers/description/

class Solution {
public:
	ListNode * addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* res = nullptr;
		ListNode* res_cur = res;
		ListNode* p1 = l1;
		ListNode* p2 = l2;
		int carry = 0;
		while (p1 != nullptr && p2 != nullptr) {
			int sum = p1->val + p2->val + carry;
			ListNode* node = new ListNode(sum % 10);
			if (res_cur == nullptr) { // first element
				res_cur = node;
				res = res_cur;
			}
			else {
				res_cur->next = node;
				res_cur = node;
			}

			carry = sum / 10;
			p1 = p1->next;
			p2 = p2->next;
		}

		ListNode* p = nullptr;
		if (p1 != nullptr) {
			p = p1;
		}
		else if (p2 != nullptr) {
			p = p2;
		}

		while (p != nullptr) {
			int sum = p->val + carry;
			res_cur->next = new ListNode(sum % 10);
			res_cur = res_cur->next;
			carry = sum / 10;
			p = p->next;
		}

		if (carry != 0) {
			res_cur->next = new ListNode(carry);
		}

		return res;
	}
};

class Test002Solution : public ::testing::Test {
public:
	virtual void SetUp() {
		node1 = nullptr;
		node2 = nullptr;
		result = nullptr;
		expect = nullptr;
	}

	virtual void TearDown() {
		deleteNodes(node1);
		deleteNodes(node2);
		deleteNodes(result);
		deleteNodes(expect);
	}

	Solution sln;
	ListNode* node1;
	ListNode* node2;
	ListNode* result;
	ListNode* expect;
};

TEST_F(Test002Solution, t1) {
	node1 = newNodes({ 1,2,3 });
	node2 = newNodes({ 1,2,3 });
	result = sln.addTwoNumbers(node1, node2);

	expect = newNodes({ 2,4,6 });
	ASSERT_TRUE(equalNodes(result, expect));
}

TEST_F(Test002Solution, t2) {
	node1 = newNodes({ 1,5,7 });
	node2 = newNodes({ 1,5,7 });
	result = sln.addTwoNumbers(node1, node2);

	expect = newNodes({ 2,0,5,1 });
	ASSERT_TRUE(equalNodes(result, expect));
}

TEST_F(Test002Solution, t3) {
	node1 = newNodes({ 1,8 });
	node2 = newNodes({ 0 });
	result = sln.addTwoNumbers(node1, node2);

	expect = newNodes({ 1,8 });
	ASSERT_TRUE(equalNodes(result, expect));
}

GTEST_MAIN
