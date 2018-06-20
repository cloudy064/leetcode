//
// Created by cloudy064 on 2018/6/17.
//

#include <iostream>

#include "common.h"

using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

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

ListNode* newNodes(const int* nums, int count) {
	if (count <= 0) return nullptr;
	ListNode* node = new ListNode(nums[0]);
	node->next = newNodes(nums + 1, count - 1);
	return node;
}

void deleteNodes(ListNode* node) {
	if (node == nullptr) return;
	ListNode* next = node->next;
	delete node;
	deleteNodes(next);
}

bool equalNodes(ListNode* node1, ListNode* node2) {
	if (node1 == nullptr && node2 == nullptr) return true;
	if (node1 == nullptr || node2 == nullptr) return false;

	if (node1->val != node2->val) return false;

	return equalNodes(node1->next, node2->next);
}

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

#define COUNT_OF(arr) sizeof(arr) / sizeof((arr)[0])

TEST_F(Test002Solution, t1) {
	int nums1[] = { 1,2,3 };
	node1 = newNodes(nums1, COUNT_OF(nums1));
	node2 = newNodes(nums1, COUNT_OF(nums1));
	result = sln.addTwoNumbers(node1, node2);

	int expectNums[] = { 2,4,6 };
	expect = newNodes(expectNums, COUNT_OF(expectNums));
	ASSERT_TRUE(equalNodes(result, expect));
}

TEST_F(Test002Solution, t2) {
	int nums1[] = { 1,5,7 };
	node1 = newNodes(nums1, COUNT_OF(nums1));
	node2 = newNodes(nums1, COUNT_OF(nums1));
	result = sln.addTwoNumbers(node1, node2);

	int expectNums[] = { 2,0,5,1 };
	expect = newNodes(expectNums, COUNT_OF(expectNums));
	ASSERT_TRUE(equalNodes(result, expect));
}

TEST_F(Test002Solution, t3) {
	int nums1[] = { 1,8 };
	node1 = newNodes(nums1, COUNT_OF(nums1));
	int nums2[] = { 0 };
	node2 = newNodes(nums2, COUNT_OF(nums2));
	result = sln.addTwoNumbers(node1, node2);

	int expectNums[] = { 1,8 };
	expect = newNodes(expectNums, COUNT_OF(expectNums));
	ASSERT_TRUE(equalNodes(result, expect));
}

GTEST_MAIN
