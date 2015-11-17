#pragma once
#include "ListNode.h"

/*
Reverse Linked List II My Submissions Question
Total Accepted: 56091 Total Submissions: 211986 Difficulty: Medium
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ¡Ü m ¡Ü n ¡Ü length of list.

Subscribe to see which companies asked this question

Hide Tags Linked List
Hide Similar Problems (E) Reverse Linked List

*/

class Solution {
public:
	//4ms
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (m >= n) return head;

		int i = 1;
		auto pp = &head;
		while (i++<m)
			pp = &(*pp)->next;
		auto pq = &(*pp)->next;

		do
		{
			auto x = (*pq);
			*pq = x->next;
			x->next = *pp;
			*pp = x;
		} while (i++<n);
		return head;
	}
};