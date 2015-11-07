#pragma once
#include "ListNode.h"
#include <unordered_set>
using std::unordered_set;
/*
Intersection of Two Linked Lists My Submissions Question
Total Accepted: 50065 Total Submissions: 169454 Difficulty: Easy
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 ¡ú a2
¨K
c1 ¡ú c2 ¡ú c3
¨J
B:     b1 ¡ú b2 ¡ú b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
Credits:
Special thanks to @stellari for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Hide Tags Linked List

*/



class Solution {
public:
	////76ms
	//ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	//	unordered_set<ListNode*> s;
	//	ListNode *p = headA;
	//	ListNode *q = headB;
	//	while (p)
	//	{
	//		s.insert(p);
	//		p = p->next;
	//	}
	//	while (q)
	//	{
	//		if (s.find(q) != s.end())
	//			break;
	//		q = q->next;
	//	}
	//	return q;
	//}

	////52ms
	//ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	//	if (headA == NULL || headB == NULL)
	//		return NULL;
	//	ListNode *p = headA;
	//	ListNode *q = headB;
	//	while (p != NULL &&q != NULL && p != q)
	//	{
	//		p = p->next;
	//		q = q->next;

	//		if (p == q)
	//			return q;

	//		if (p == NULL)
	//			p = headB;
	//		if (q == NULL)
	//			q = headA;
	//	}
	//	return q;
	//}

	//48 ms
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
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