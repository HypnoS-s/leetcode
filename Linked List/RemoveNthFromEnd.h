#pragma once
#include "ListNode.h"


int fuck(ListNode* p, int n) {
	if (!p)	return 0;
	auto x = fuck(p->next, n);
	if (x == n)
		p->next = p->next->next;
	return x + 1;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
	//ListNode x;
	//x.next = head;
	//fuck(&x,n);
	//return x.next;

	if (!head) return head;

	ListNode **pp = &head;
	ListNode *q = head;
	for (size_t i = 0; i < n; i++)
		q = q->next;
	while (q)
	{
		q = q->next;
		pp = &(*pp)->next;
	}
	if (*pp)
	{
		*pp = (*pp)->next;
	}
	return head;

}


