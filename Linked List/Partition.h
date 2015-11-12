#pragma once
#include "ListNode.h"

/*
Partition List My Submissions Question
Total Accepted: 51914 Total Submissions: 185325 Difficulty: Medium
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

Subscribe to see which companies asked this question

Hide Tags Linked List Two Pointers

*/

class Solution {
public:
	////8ms
	//ListNode* partition(ListNode* head, int x) {
	//	//auto pp = &head;
	//	auto big = ListNode(0);
	//	auto small = ListNode(0);
	//	auto p = &big, q = &small;
	//	while (head)
	//	{
	//		if (head->val<x)
	//		{
	//			q->next = head;
	//			q = head;
	//		}
	//		else
	//		{
	//			p->next = head;
	//			p = head;
	//		}
	//		head = head->next;
	//	}
	//	p->next = NULL;

	//	q->next = big.next;
	//	return small.next;
	//}

	////8ms
	//ListNode* partition(ListNode* head, int x) {
	//	//auto pp = &head;
	//	ListNode* big,**pBig=&big;
	//	ListNode* small, **pSmall=&small;
	//	while (head)
	//	{
	//		if (head->val<x)
	//		{
	//			*pSmall = head;;
	//			pSmall = &head->next;
	//		}
	//		else
	//		{
	//			*pBig = head;;
	//			pBig = &head->next;
	//		}
	//		head = head->next;
	//	}
	//	*pBig = NULL;
	//	*pSmall = big;
	//	return small;
	//}

	//8ms
	ListNode* partition(ListNode* head, int x) {
		//auto pp = &head;
		ListNode* big, **pBig = &big;
		ListNode* small, **pSmall = &small;
		while (head)
		{
			auto pp = (head->val < x) ? &pSmall : &pBig;
			**pp = head;;
			*pp = &head->next;
			head = head->next;
		}
		*pBig = NULL;
		*pSmall = big;
		return small;
	}

};