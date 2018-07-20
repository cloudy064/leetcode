//
// Created by cloudy064 on 2018/6/22.
//


#include <algorithm>
#include <unordered_map>
#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/valid-parentheses/description/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;

        ListNode* l3 = nullptr;
        ListNode* p3 = nullptr;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        while (p1 != nullptr || p2 != nullptr) {
            if (p1 == nullptr) {
                p3->next = p2;
                p3 = p2;
                p2 = p2->next;
                continue;
            }

            if (p2 == nullptr) {
                p3->next = p1;
                p3 = p1;
                p1 = p1->next;
                continue;
            }

            if (p1->val >= p2->val) {
                if (p3 == nullptr) {
                    p3 = p2;
                    l3 = p3;
                } else {
                    p3->next = p2;
                    p3 = p2;
                }

                p2 = p2->next;
            } else {
                if (p3 == nullptr) {
                    p3 = p1;
                    l3 = p3;
                } else {
                    p3->next = p1;
                    p3 = p1;
                }

                p1 = p1->next;
            }
        }

        return l3;
    }
};

class Test021Solution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(Test021Solution, t1)
{
    auto l1 = newNodes({ 1, 2, 3, 4 });
    auto l2 = newNodes({ 1, 2, 3, 4 });
    auto expect = newNodes({ 1,1,2,2,3,3,4,4 });
    auto result = sln.mergeTwoLists(l1, l2);
    ASSERT_TRUE(equalNodes(expect, result));
    deleteNodes(result);
    deleteNodes(expect);
}

TEST_F(Test021Solution, t2)
{
    auto l1 = newNodes({ 1, 2, 3, 4 });
    auto l2 = newNodes({ });
    auto expect = newNodes({ 1,2,3,4 });
    auto result = sln.mergeTwoLists(l1, l2);
    ASSERT_TRUE(equalNodes(expect, result));
    deleteNodes(result);
    deleteNodes(expect);
}

TEST_F(Test021Solution, t3)
{
    auto l1 = newNodes({ 1, 2, 3, 4 });
    auto l2 = newNodes({ 1, 2, 3 });
    auto expect = newNodes({ 1,1,2,2,3,3,4 });
    auto result = sln.mergeTwoLists(l1, l2);
    ASSERT_TRUE(equalNodes(expect, result));
    deleteNodes(result);
    deleteNodes(expect);
}


GTEST_MAIN