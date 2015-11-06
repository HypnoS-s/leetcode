#pragma once
#include "ListNode.h"
ListNode* removeElements(ListNode* head, int val) {
	ListNode** pp = &head;
	while (*pp)
	{
		if ((*pp)->val == val)
		{
			*pp = (*pp)->next;
		}
		else
		{
			pp = &(*pp)->next;
		}
	}
	return head;
}