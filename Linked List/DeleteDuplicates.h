#pragma once
#include "ListNode.h"

/*
Remove Duplicates from Sorted List My Submissions Question
Total Accepted: 85175 Total Submissions: 242488 Difficulty: Easy
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

Subscribe to see which companies asked this question

Hide Tags Linked List

12ms
*/

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head)
	{
		auto p = head;
		while (p)
		{
			auto q = p->next;
			while (q && q->val == p->val)
				q = q->next;
			p->next = q;
			p = q;
		}
		return head;
	}

};
