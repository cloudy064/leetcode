//
//  main.cpp
//  094.binary-tree-inorder-traversal
//
//  Created by 常永耘 on 2019/4/12.
//  Copyright © 2019 cloudy064. All rights reserved.
//

#include <stack>
#include "common.h"

class Solution {
public:
    void pushLeftNodes(TreeNode* root, stack<TreeNode*>& nodes) {
        auto node = root;
        while (node != nullptr) {
            nodes.push(node);
            node = node->left;
        }
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        
        stack<TreeNode*> nodes;
        pushLeftNodes(root, nodes);
        
        vector<int> result;
        while (!nodes.empty()) {
            auto node = nodes.top();
            result.push_back(node->val);
            nodes.pop();
            
            pushLeftNodes(node->right, nodes);
        }
        
        return result;
    }
};


class TestSolution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(TestSolution, t1) {
    vector<int> nums = {1, INT_MIN, 2, INT_MIN, INT_MIN, 3, INT_MIN};
    auto root = buildTree(nums);
    auto result = sln.inorderTraversal(root);
    deleteTree(root);
    
    vector<int> expect = {1,3,2};
    EXPECT_EQ(result, expect);
}

GTEST_MAIN

