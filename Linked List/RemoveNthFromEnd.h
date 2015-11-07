#pragma once
#include "ListNode.h"

class Solution {
public:
	int fuck(ListNode* p, int n) {
		if (!p)	return 0;
		auto x = fuck(p->next, n);
		if (x == n)
			p->next = p->next->next;
		return x + 1;
	}

	ListNode* removeNthFromEnd(ListNode* head, int n) {
		//recursive
		ListNode x(1);
		x.next = head;
		fuck(&x,n);
		return x.next;
	}
	//ListNode* removeNthFromEnd(ListNode* head, int n) {
	//	if (!head) return head;

	//	ListNode **pp = &head;
	//	ListNode *q = head;
	//	for (size_t i = 0; i < n; i++)
	//		q = q->next;
	//	while (q)
	//	{
	//		q = q->next;
	//		pp = &(*pp)->next;
	//	}
	//	if (*pp)
	//	{
	//		*pp = (*pp)->next;
	//	}
	//	return head;
	//}


};