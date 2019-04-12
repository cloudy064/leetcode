//
//  main.cpp
//  092.reverse-linked-list-ii
//
//  Created by 常永耘 on 2019/4/12.
//  Copyright © 2019 cloudy064. All rights reserved.
//

#include "common.h"

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) return head;
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = head->next;
        
        int i = 1;
        while (i < m) {
            prev = curr;
            curr = curr->next;
            next = curr->next;
            ++i;
        }
        
        ListNode* listPrev = prev;
        ListNode* listHead = curr;
        
        while (true) {
            curr->next = prev;
            prev = curr;
            if (i == n) break;
            
            curr = next;
            next = (next == nullptr) ? next : next->next;
            ++i;
        }
        
        ListNode* listNext = next;
        listHead->next = next;
        if (listPrev == nullptr) {// m == 0
            head = curr;
        } else {
            listPrev->next = curr;
        }
        
        return head;
    }
};

class TestSolution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(TestSolution, t1) {
    auto head = newNodes({1,2,3});
    auto expect = newNodes({3,2,1});
    
    head = sln.reverseBetween(head, 1, 3);
    
    EXPECT_TRUE(equalNodes(head, expect));

    deleteNodes(expect);
    deleteNodes(head);
}

TEST_F(TestSolution, t2) {
    auto head = newNodes({1,2,3});
    auto expect = newNodes({2,1,3});
    
    head = sln.reverseBetween(head, 1, 2);
    
    EXPECT_TRUE(equalNodes(head, expect));
    
    deleteNodes(expect);
    deleteNodes(head);
}

TEST_F(TestSolution, t3) {
    auto head = newNodes({1,2,3,4,5,6});
    auto expect = newNodes({1,5,4,3,2,6});
    
    head = sln.reverseBetween(head, 2, 5);
    
    EXPECT_TRUE(equalNodes(head, expect));
    
    deleteNodes(expect);
    deleteNodes(head);
}

GTEST_MAIN
