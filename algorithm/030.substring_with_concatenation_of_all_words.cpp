//
// Created by cloudy064 on 2018/7/20.
//

#include <iostream>
#include <vector>
#include <unordered_map>

#include "common.h"
#include <queue>

using namespace std;

/// Solution for https://leetcode-cn.com/problems/divide-two-integers/description/

class Solution {

	typedef struct TreeNode
	{
		//struct TreeNode* child[26];
		struct TreeNode* parent;
		unordered_map<char, struct TreeNode*> children;
		struct TreeNode* fail;
		bool accept;
		bool isRoot;
		int tag;
	} TreeNode;

public:
	TreeNode* createNode()
	{
		TreeNode* node = new TreeNode;
		node->isRoot = false;
		node->accept = false;
		node->parent = nullptr;
		node->fail = nullptr;
		node->tag = -1;
		return node;
	}

	void destroyNode(TreeNode* node)
	{
		delete node;
	}

	TreeNode* buildTree(TreeNode* root, const string& word, int tag)
	{
		TreeNode* current = root;
		for (auto ch : word)
		{
			auto it = current->children.find(ch);
			if (it != current->children.end())
			{
				current = it->second;
				continue;
			}

			TreeNode* node = createNode();
			node->parent = current;
			current->children[ch] = node;
			node->fail = root;

			current = node;
		}

		current->accept = true;
		current->tag = tag;
		return root;
	}

	TreeNode* buildFail(TreeNode* root)
	{
		queue<TreeNode*> nodes;
		for (auto node: root->children)
		{
			nodes.push(node.second);
		}

		while (!nodes.empty())
		{
			TreeNode* node = nodes.front();
			nodes.pop();

			for (auto child: node->children)
			{
				auto parentFail = child.second->parent->fail;
				auto it = parentFail->children.find(child.first);
				if (it != parentFail->children.end())
				{
					child.second->fail = it->second;
				}

				for (auto c : node->children)
				{
					nodes.push(c.second);
				}
			}
		}

		return root;
	}

	vector<int> findSubstring(string s, vector<string>& words) {
		TreeNode* root = createNode();
		root->isRoot = true;
		root->accept = false;
		root->fail = root;

		unordered_map<string, int> unique_word;
		for (int i = 0; i < words.size(); ++i)
		{
			auto it = unique_word.find(words[i]);
			if (it == unique_word.end())
			{
				unique_word.insert(it, { words[i], 1 });
			}
			else
			{
				it->second += 1;
			}
		}

		int tag = 0;
		unordered_map<int, int> lengths;
		unordered_map<int, int> word_counts;
		for (auto it = unique_word.begin(); it != unique_word.end(); ++it)
		{
			buildTree(root, it->first, tag);
			lengths[tag] = it->first.length();
			word_counts[tag] = it->second;
			tag += 1;
		}

		buildFail(root);

		unordered_map<int, int> occur;
		TreeNode* node = root;
		for (int i = 0; i < s.length(); ++i)
		{
			auto it = node->children.find(s[i]);
			if (it == node->children.end())
			{
				if (node == root) continue;

				node = node->fail;
				if (node->accept)
				{
					tag = node->tag;
					const auto length = lengths[tag];
					occur[i - length] = node->tag;
				}
				i -= 1;
			}
			else
			{
				node = it->second;
				if (node->accept)
				{
					tag = node->tag;
					const auto length = lengths[tag];
					occur[i - length + 1] = node->tag;
				}
			}
		}

		vector<int> result;
		unordered_map<int, int> find_occur;
		for (auto it = occur.begin(); it != occur.end(); ++it)
		{
			find_occur[it->second] += 1;
			auto temp = it;
			while (word_counts != find_occur) {
				int length = lengths[temp->second];
				auto next = occur.find(temp->first + length);
				if (next == occur.end())
				{
					find_occur.clear();
					break;
				}

				find_occur[next->second] += 1;
				if (word_counts[next->second] < find_occur[next->second])
				{
					find_occur.clear();
					break;
				}
				else
				{
					temp = next;
				}
			}

			if (!find_occur.empty())
			{
				result.push_back(it->first);
				find_occur.clear();
			}
		}

		return result;
	}
};

class Test030Solution : public ::testing::Test {
public:
	Solution sln;
};

TEST_F(Test030Solution, t1)
{
	vector<string> words = { "foo", "bar" };
	auto result = sln.findSubstring("barfoothefoobarman", words);
	ASSERT_EQ(result, vector<int>({ 0 ,9 }));
}

TEST_F(Test030Solution, t2)
{
	vector<string> words = { "word", "good" };
	auto result = sln.findSubstring("wordgoodstudentgoodword", words);
	ASSERT_EQ(result, vector<int>({ 0 ,15 }));
}

TEST_F(Test030Solution, t3)
{
	vector<string> words = { "aaa", "aaa" };
	auto result = sln.findSubstring("aaaaaa", words);
	ASSERT_EQ(result, vector<int>({ 0 }));
}

TEST_F(Test030Solution, t4)
{
	vector<string> words = { "hao", "nihao" };
	auto result = sln.findSubstring("nihaonihao", words);
	ASSERT_EQ(result, vector<int>({ 2 }));
}

TEST_F(Test030Solution, t5)
{
	vector<string> words = { "ab", "ba", "ab", "ba" };
	auto result = sln.findSubstring("abaababbaba", words);
	ASSERT_EQ(result, vector<int>({ 1, 3 }));
}
