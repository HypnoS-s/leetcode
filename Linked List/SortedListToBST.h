#pragma once
#include "ListNode.h"
#include "TreeNode.h"

/*
Convert Sorted List to Binary Search Tree My Submissions Question
Total Accepted: 55861 Total Submissions: 194105 Difficulty: Medium
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

Subscribe to see which companies asked this question

Hide Tags Depth-first Search Linked List
Hide Similar Problems (M) Convert Sorted Array to Binary Search Tree
*/



class Solution {
public:
	//28ms
	TreeNode* sortedListToBST(ListNode* head) {
		if (!head) return NULL;
		//if (!head) return new TreeNode(head->val);//no need ,becase the while loop while handle it
		auto fast = head;
		auto slow = &head;

		while (fast && fast->next)
		{
			fast = fast->next->next;
			slow = &(*slow)->next;
		}

		auto root = new TreeNode((*slow)->val);
		root->right = sortedListToBST((*slow)->next);
		*slow = NULL;
		root->left = sortedListToBST(head);
		return root;
	}
};