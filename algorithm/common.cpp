#include "common.h"

ListNode* newNodes(const vector<int>& nums) {
	ListNode *head = nullptr;
	ListNode *p = nullptr;

	for (auto it = nums.begin(); it != nums.end(); ++it)
	{
		ListNode* node = new ListNode(*it);
		if (head == nullptr)
		{
			head = node;
		}
		else
		{
			p->next = node;
		}

		p = node;
	}

	return head;
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