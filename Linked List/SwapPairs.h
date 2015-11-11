#pragma once
#include "ListNode.h"

/*
Swap Nodes in Pairs My Submissions Question
Total Accepted: 70588 Total Submissions: 212517 Difficulty: Medium
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

Subscribe to see which companies asked this question

Hide Tags Linked List
Hide Similar Problems (H) Reverse Nodes in k-Group
*/

class Solution {
public:
	//4ms
	ListNode* swapPairs(ListNode* head) {
		auto pp = &head;
		while (*pp && (*pp)->next)
		{
			auto x = *pp;
			*pp = x->next;
			x->next = (*pp)->next;
			(*pp)->next = x;

			pp = &(x->next);
		}
		return head;
	}
};