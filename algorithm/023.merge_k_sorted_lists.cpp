//
// Created by cloudy064 on 2018/6/24.
//

#include <algorithm>
#include <unordered_map>
#include "common.h"

using namespace std;

/// https://leetcode-cn.com/problems/merge-k-sorted-lists/description/

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto compare = [](ListNode* l1, ListNode* l2) {
            return l1->val > l2->val;
        };

        vector<ListNode*> head;
        for (auto node : lists) {
            if (node == nullptr) continue;
            head.push_back(node);
        }

        make_heap(head.begin(), head.end(), compare);

        ListNode* result = nullptr;
        ListNode* p = nullptr;
        while (!head.empty()) {
            pop_heap(head.begin(), head.end(), compare);
            auto node = head.back();
            head.pop_back();
            if (result == nullptr) {
                result = node;
            } else {
                p->next = node;
            }

            p = node;

            auto next = node->next;
            if (next == nullptr) continue;
            head.push_back(next);
            push_heap(head.begin(), head.end(), compare);
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
    auto l1 = newNodes({ 1, 2, 3, 4 });
    auto l2 = newNodes({ 1, 2, 3, 4 });
    auto expect = newNodes({ 1,1,2,2,3,3,4,4 });
    vector<ListNode*> lists = {l1, l2};
    auto result = sln.mergeKLists(lists);
    ASSERT_TRUE(equalNodes(expect, result));
    deleteNodes(result);
    deleteNodes(expect);
}

TEST_F(Test023Solution, t2)
{
    auto l1 = newNodes({ 1, 2, 3, 4 });
    auto l2 = newNodes({ 1, 2, 3, 4 });
    auto l3 = newNodes({ 1, 2 });
    auto expect = newNodes({ 1,1,1,2,2,2,3,3,4,4 });
    vector<ListNode*> lists = {l1, l2, l3};
    auto result = sln.mergeKLists(lists);
    ASSERT_TRUE(equalNodes(expect, result));
    deleteNodes(result);
    deleteNodes(expect);
}

TEST_F(Test023Solution, t3)
{
    auto l1 = newNodes({ 9 });
    auto l2 = newNodes({ 1, 2, 3, 4 });
    auto l3 = newNodes({ 1, 5, 7 });
    auto expect = newNodes({ 1,1,2,3,4,5,7,9 });
    vector<ListNode*> lists = {l1, l2, l3};
    auto result = sln.mergeKLists(lists);
    ASSERT_TRUE(equalNodes(expect, result));
    deleteNodes(result);
    deleteNodes(expect);
}

GTEST_MAIN