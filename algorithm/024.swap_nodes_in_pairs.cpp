//
// Created by cloudy064 on 2018/6/24.
//

#include <algorithm>
#include <unordered_map>
#include "common.h"

using namespace std;

/// https://leetcode-cn.com/problems/swap-nodes-in-pairs/description/

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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* p1 = head;
        ListNode* p2 = p1->next;
        ListNode* result = p2;
        while (p1 != nullptr) {
            if (p2 == nullptr) break;

            auto p3 = p2->next;
            p1->next->next = p1;
            if (p3 == nullptr) {
                p1->next = nullptr;
            } else if (p3->next == nullptr) {
                p1->next = p3;
            } else {
                p1->next = p3->next;
            }

            if (p3 == nullptr) break;

            p1 = p3;
            p2 = p3->next;
        }

        return result;
    }
};

class Test023Solution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(Test023Solution, t1)
{
    auto nodes = newNodes({1,2,3,4});
    auto expect = newNodes({2,1,4,3});
    auto result = sln.swapPairs(nodes);
    EXPECT_TRUE(equalNodes(expect, result));
}

TEST_F(Test023Solution, t2)
{
    auto nodes = newNodes({1});
    auto expect = newNodes({1});
    auto result = sln.swapPairs(nodes);
    EXPECT_TRUE(equalNodes(expect, result));
}

TEST_F(Test023Solution, t3)
{
    auto nodes = newNodes({1,2,3});
    auto expect = newNodes({2,1,3});
    auto result = sln.swapPairs(nodes);
    EXPECT_TRUE(equalNodes(expect, result));
}

TEST_F(Test023Solution, t4)
{
    auto nodes = newNodes({1,2,3,4,5,6});
    auto expect = newNodes({2,1,4,3,6,5});
    auto result = sln.swapPairs(nodes);
    EXPECT_TRUE(equalNodes(expect, result));
}

TEST_F(Test023Solution, t5)
{
    auto nodes = newNodes({1,2,3,4,5,6,7});
    auto expect = newNodes({2,1,4,3,6,5,7});
    auto result = sln.swapPairs(nodes);
    EXPECT_TRUE(equalNodes(expect, result));
}

GTEST_MAIN