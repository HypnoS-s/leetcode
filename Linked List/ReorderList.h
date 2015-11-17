#pragma once
#include "ListNode.h"

/*
Reorder List My Submissions Question
Total Accepted: 53369 Total Submissions: 247615 Difficulty: Medium
Given a singly linked list L: L0¡úL1¡ú¡­¡úLn-1¡úLn,
reorder it to: L0¡úLn¡úL1¡úLn-1¡úL2¡úLn-2¡ú¡­

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.

Subscribe to see which companies asked this question

Hide Tags Linked List

*/

class Solution {
public:
	//68ms
	void reorderList(ListNode* head) {
		if (!head) return;
		auto fast = head;
		auto slow = &head;

		while (fast && fast->next)
		{
			fast = fast->next->next;
			slow = &(*slow)->next;
		}
		fast = (*slow)->next;
		fast = reverseList(fast);
		(*slow)->next = NULL;
		slow = &head;
		while (fast)
		{
			auto x = fast;
			fast = fast->next;
			x->next = (*slow)->next;
			(*slow)->next = x;
			slow = &x->next;
		}
	}

	ListNode* reverseList(ListNode* head) {
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



	//void reorderList(ListNode* head) {
	//	if (!head ||!head->next) return;
	//	auto slow= head;
	//	auto fast  = head->next;

	//	while (fast && fast->next)
	//	{
	//		fast = fast->next->next;
	//		slow = slow->next;
	//	}

	//	fast = reverseList(slow->next);
	//	slow->next = NULL;
	//	slow = head;
	//	while (fast)
	//	{
	//		auto x = slow->next;
	//		slow->next = fast;
	//		fast->next = x;
	//		fast = fast->next;
	//		slow = x;
	//	}
	//}
};


/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
//60ms,not mine
class Solution {
public:
	void reorderList(ListNode *head) {
		if (!head || !head->next) return;

		// find the middle node: O(n)
		ListNode *p1 = head, *p2 = head->next;
		while (p2 && p2->next) {
			p1 = p1->next;
			p2 = p2->next->next;
		}

		// cut from the middle and reverse the second half: O(n)
		ListNode *head2 = p1->next;
		p1->next = NULL;

		p2 = head2->next;
		head2->next = NULL;
		while (p2) {
			p1 = p2->next;
			p2->next = head2;
			head2 = p2;
			p2 = p1;
		}

		// merge two lists: O(n)
		for (p1 = head, p2 = head2; p1; ) {
			auto t = p1->next;
			p1 = p1->next = p2;
			p2 = t;
		}
	}
};