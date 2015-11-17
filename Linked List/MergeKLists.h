#pragma once
#include "ListNode.h"
#include <vector>
using std::vector;
/*
Merge k Sorted Lists My Submissions Question
Total Accepted: 64600 Total Submissions: 296553 Difficulty: Hard
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Subscribe to see which companies asked this question

Hide Tags Divide and Conquer Linked List Heap
Hide Similar Problems (E) Merge Two Sorted Lists (M) Ugly Number II
*/

//412ms,404ms,408ms
class Solution {
public:
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
	
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.size()==0) return NULL;
		for (int step = 1; step < lists.size(); step <<= 1)
		{
			int x = step << 1;
			for (int i = 0; i < lists.size() - step; i += x)
				lists[i] = mergeTwoLists(lists[i], lists[i + step]);
		}
		return lists[0];
	}
};
//
////408ms
//class Solution {
//public:
//
//	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//		//iterative
//		ListNode headNode(0), *p = &headNode;
//		while (l1 && l2)
//		{
//			if (l1->val < l2->val)
//			{
//				p->next = l1;
//				p = l1;
//				l1 = l1->next;
//			}
//			else
//			{
//				p->next = l2;
//				p = l2;
//				l2 = l2->next;
//			}
//		}
//		if (l1)
//			p->next = l1;
//		if (l2)
//			p->next = l2;
//		return headNode.next;
//	}
//
//
//	ListNode* mergeKLists(vector<ListNode*>& lists) {
//		if (lists.size() == 0)
//		{
//			return NULL;
//		}
//		for (int step = 1; step < lists.size(); step <<= 1)
//		{
//			int x = step << 1;
//			for (int i = 0; i < lists.size() - step; i += x)
//			{
//				lists[i] = mergeTwoLists(lists[i], lists[i + step]);
//			}
//
//		}
//		return lists[0];
//	}
//};