#pragma once
#include "ListNode.h"

/*
Reverse Nodes in k-Group My Submissions Question
Total Accepted: 47099 Total Submissions: 181021 Difficulty: Hard
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Subscribe to see which companies asked this question

Hide Tags Linked List
Hide Similar Problems (M) Swap Nodes in Pairs
*/

class Solution {
public:
	//28ms
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (k <= 1)return head;
		ListNode *p = head, *q = head, *t, *r, **pre = &head;
		int x = 1;
		while (q && q->next)
		{
			q = q->next;
			++x;
			if (!(x%k))
			{
				*pre = q;
				pre = &p->next;
				r = q->next;
				while (p != q)
				{
					t = p;
					p = p->next;
					t->next = q->next;
					q->next = t;
				}
				p = q = r;
				++x;
			}
		}
		return head;
	}
};
