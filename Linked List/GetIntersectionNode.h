#pragma once
#include "ListNode.h"

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		//unordered_set<ListNode*> s;
		//ListNode *p = headA;
		//ListNode *q = headB;
		//while (p)
		//{
		//	s.insert(p);
		//	p = p->next;
		//}
		//while (q)
		//{
		//	if (s.find(q) != s.end())
		//		break;
		//	q = q->next;
		//}
		//return q;

		ListNode *p = headA;
		ListNode *q = headB;
		while (p && q)
		{
			if (p == q) return p;
			p = p->next;
			q = q->next;

			if (!q) q = headA;
			if (!p)p = headB;
		}
		return NULL;
	}



};