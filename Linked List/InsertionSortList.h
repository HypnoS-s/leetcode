#pragma once
#include "ListNode.h"

//84ms

class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (!head || !head->next) return head;
		for (ListNode** pq = &head->next; *pq;)
		{
			ListNode** pp = &head;
			while (pq != pp && (*pq)->val > (*pp)->val)
				pp = &(*pp)->next;
			if (pq == pp)
			{
				pq = &(*pq)->next;
				continue;
			}

			auto node = *pq;
			*pq = (*pq)->next;
			auto tmp = *pp;
			*pp = node;
			(*pp)->next = tmp;
		}
		return head;
	}
};