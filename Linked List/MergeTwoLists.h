#pragma once
#include "ListNode.h"

class Solution {
public:
	//ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	//	////iterative
	//	//	ListNode headNode, *p = &headNode;
	//	//	while (l1 && l2)
	//	//	{
	//	//		if (l1->val < l2->val)
	//	//		{
	//	//			p->next = l1;
	//	//			p = l1;
	//	//			l1 = l1->next;
	//	//		}
	//	//		else
	//	//		{
	//	//			p->next = l2;
	//	//			p = l2;
	//	//			l2 = l2->next;
	//	//		}
	//	//	}
	//	//	if (l1)
	//	//	{
	//	//		p->next = l1;
	//	//	}
	//	//	if (l2)
	//	//	{
	//	//		p->next = l2;
	//	//	}
	//	//	return headNode.next;

	//	//recursive
	//	if (!l1) return l2;
	//	if (!l2) return l1;

	//	if (l1->val < l2->val)
	//	{
	//		l1->next = mergeTwoLists(l1->next, l2);
	//		return l1;
	//	}
	//	else
	//	{
	//		l2->next = mergeTwoLists(l2->next, l1);
	//		return l2;
	//	}

	//}

		ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		//iterative
		ListNode headNode(0), *p = &headNode,**x;
		while (l1 && l2)
		{
			x = (l1->val < l2->val) ? &l1 : &l2;
			p = p->next = *x;
			*x = (*x)->next;
		}
		if (l1)	p->next = l1;
		if (l2)	p->next = l2;
		return headNode.next;
	}
};