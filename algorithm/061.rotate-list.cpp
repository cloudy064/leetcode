//
// Created by 常永耘 on 2019/2/24.
//

#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/rotate-list/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0) return head;

        vector<ListNode*> nodes;

        int len = 0;
        auto node = head;
        while (node != nullptr) {
            ++len;
            nodes.push_back(node);
            node = node->next;
        }

        k %= len;
        if (k == 0) return head;

        head = nodes[len - k];
        nodes[len - 1]->next = nodes[0];
        nodes[len - k - 1]->next = nullptr;
        return head;
    }
};

class Test061Solution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(Test061Solution, t1) {
    auto nodes = newNodes({});
    auto expect = newNodes({});
    EXPECT_TRUE(equalNodes(sln.rotateRight(nodes, 0), expect));
    EXPECT_TRUE(equalNodes(sln.rotateRight(nodes, 1), expect));
    deleteNodes(expect);
    deleteNodes(nodes);
}

TEST_F(Test061Solution, t2) {
    auto nodes = newNodes({1});
    auto expect = newNodes({1});
    EXPECT_TRUE(equalNodes(sln.rotateRight(nodes, 0), expect));
    EXPECT_TRUE(equalNodes(sln.rotateRight(nodes, 1), expect));
    EXPECT_TRUE(equalNodes(sln.rotateRight(nodes, 2), expect));
    deleteNodes(expect);
    deleteNodes(nodes);
}

TEST_F(Test061Solution, t3) {
    auto nodes = newNodes({1,2,3,4,5});
    auto expect = newNodes({3,4,5,1,2});
    EXPECT_TRUE(equalNodes(sln.rotateRight(nodes, 3), expect));
    deleteNodes(expect);
    deleteNodes(nodes);
}

TEST_F(Test061Solution, t4) {
    auto nodes = newNodes({0,1,2});
    auto expect = newNodes({2,0,1});
    EXPECT_TRUE(equalNodes(sln.rotateRight(nodes, 4), expect));
    deleteNodes(expect);
    deleteNodes(nodes);
}

GTEST_MAIN