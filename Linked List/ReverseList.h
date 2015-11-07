#pragma once
#include "ListNode.h"
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		//if (!head || !head->next)
		//{
		//	return head;
		//}
		//ListNode * p = head;
		//ListNode * q = head->next;

		//auto x = reverseList(q);
		//   p->next->next = p;
		//p->next = NULL;
		//return x;

		ListNode * p = NULL;
		ListNode * q = head;
		while (q)
		{
			auto t = q->next;
			q->next = p;
			p = q;
			q = t;
		}
		return p;
	}
};