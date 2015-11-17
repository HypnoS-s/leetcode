#pragma once
#include "ListNode.h"

/*
Rotate List My Submissions Question
Total Accepted: 53528 Total Submissions: 243443 Difficulty: Medium
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

Subscribe to see which companies asked this question

Hide Tags Linked List Two Pointers
Hide Similar Problems (E) Rotate Array

*/
//8ms
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head ||!head->next) return head;
		int len = 1;
		auto p = head;
		auto pp = &head;
		while (p->next)
		{
			p = p->next;
			++len;
		}
		if (k %= len)
		{
			p->next = head;
			k = len - k;
			while (k--)
			{
				pp = &(*pp)->next;
			}
			auto new_head = *pp;
			*pp = NULL;
			return new_head;

		}
		else
		{
			return head;
		}
	}
};