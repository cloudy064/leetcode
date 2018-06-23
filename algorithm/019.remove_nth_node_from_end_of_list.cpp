//
// Created by cloudy064 on 2018/6/22.
//


#include <algorithm>
#include <unordered_map>
#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> nodes;
        for (ListNode* node = head; node != nullptr; node = node->next) {
            nodes.push_back(node);
        }

        int size = nodes.size();
        if (n > size) {
            return nullptr;
        }
        
        ListNode* node = nodes[size - n];
        if (node == head) {
            return head->next;
        }

        ListNode* pre = nodes[size - n - 1];
        pre->next = node->next;
        return head;
    }
};

class Test019Solution : public ::testing::Test {
public:
	Solution sln;
};

TEST_F(Test019Solution, t1)
{
	auto l1 = newNodes({ 1,2,3,4,5 });
	auto expect = newNodes({ 1,2,3,4 });
	auto result = sln.removeNthFromEnd(l1, 1);
	ASSERT_TRUE(equalNodes(result, expect));
	deleteNodes(result);
	deleteNodes(expect);
}

TEST_F(Test019Solution, t2)
{
	auto l1 = newNodes({ 1 });
	auto expect = newNodes({ });
	auto result = sln.removeNthFromEnd(l1, 1);
	ASSERT_TRUE(equalNodes(result, expect));
	deleteNodes(result);
	deleteNodes(expect);
}

TEST_F(Test019Solution, t3)
{
	auto l1 = newNodes({ 1, 2 });
	auto expect = newNodes({2});
	auto result = sln.removeNthFromEnd(l1, 2);
	ASSERT_TRUE(equalNodes(result, expect));
	deleteNodes(result);
	deleteNodes(expect);
}

GTEST_MAIN