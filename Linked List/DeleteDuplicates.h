
#pragma once
#include "ListNode.h"
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


