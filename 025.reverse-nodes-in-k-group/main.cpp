//
// Created by cloudy064 on 2018/6/24.
//

#include <algorithm>
#include <unordered_map>
#include "common.h"

using namespace std;

/// https://leetcode-cn.com/problems/reverse-nodes-in-k-group/description/

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) return head;

        auto p1 = head;
        auto p2 = p1->next;
        auto p3 = head;
        ListNode* result = p1;
        ListNode* prev_begin = nullptr;
        ListNode* prev_end = nullptr;
        ListNode* cur_begin = nullptr;
        ListNode* cur_end = nullptr;

        while (true) {
            cur_begin = p3;
            int i = 0;
            for (; i < k; ++i) {
                if (p3 == nullptr) break;
                cur_end = p3;
                p3 = p3->next;
            }

            if (i != k) {
                break;
            }

            if (prev_begin != nullptr) {
                prev_begin->next = cur_end;
            }

            p1 = cur_begin->next;
            p2 = p1->next;
            cur_begin->next = cur_end->next;
            p1->next = cur_begin;
            prev_begin = cur_begin;
            prev_end = cur_end;

            ListNode* p4 = nullptr;
            while (p2 != p3) {
                p4 = p2->next;
                p2->next = p1;
                p1 = p2;
                p2 = p4;
            }

            if (result == head) {
                result = prev_end;
            }
        }

        return result;
    }
};

class Test025Solution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(Test025Solution, t1)
{
    auto nodes = newNodes({1,2,3,4});
    auto expect = newNodes({2,1,4,3});
    auto result = sln.reverseKGroup(nodes, 2);
    EXPECT_TRUE(equalNodes(expect, result));
}

TEST_F(Test025Solution, t2)
{
    auto nodes = newNodes({1,2,3,4});
    auto expect = newNodes({3,2,1,4});
    auto result = sln.reverseKGroup(nodes, 3);
    EXPECT_TRUE(equalNodes(expect, result));
}

TEST_F(Test025Solution, t3)
{
    auto nodes = newNodes({1,2,3,4});
    auto expect = newNodes({4,3,2,1});
    auto result = sln.reverseKGroup(nodes, 4);
    EXPECT_TRUE(equalNodes(expect, result));
}

TEST_F(Test025Solution, t4)
{
    auto nodes = newNodes({1,2,3,4,5,6,7,8});
    auto expect = newNodes({4,3,2,1,8,7,6,5});
    auto result = sln.reverseKGroup(nodes, 4);
    EXPECT_TRUE(equalNodes(expect, result));
}

TEST_F(Test025Solution, t5)
{
    auto nodes = newNodes({1,2,3,4,5,6,7,8,9,10});
    auto expect = newNodes({4,3,2,1,8,7,6,5,9,10});
    auto result = sln.reverseKGroup(nodes, 4);
    EXPECT_TRUE(equalNodes(expect, result));
}

TEST_F(Test025Solution, t6)
{
    auto nodes = newNodes({1,2,3,4});
    auto expect = newNodes({1,2,3,4});
    auto result = sln.reverseKGroup(nodes, 10);
    EXPECT_TRUE(equalNodes(expect, result));
}

TEST_F(Test025Solution, t7)
{
    auto nodes = newNodes({1,2,3,4});
    auto expect = newNodes({1,2,3,4});
    auto result = sln.reverseKGroup(nodes, 1);
    EXPECT_TRUE(equalNodes(expect, result));
}

GTEST_MAIN