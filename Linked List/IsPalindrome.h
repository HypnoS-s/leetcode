#pragma once
#include "ListNode.h"

/*
Palindrome Linked List My Submissions Question
Total Accepted: 26053 Total Submissions: 106837 Difficulty: Easy
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
*/
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		//if (!head)
		//{
		//	return true;
		//}
		//ListNode* p = head, *q = head, *pre = NULL;
		//while (p->next && p->next->next)
		//{
		//	p = p->next->next;
		//	auto t = q->next;
		//	q->next = pre;
		//	pre = q;
		//	q = t;
		//}
		//if (p->next)
		//{
		//	p = q->next;
		//}
		//else
		//{
		//	p = q;
		//}
		//if (p->val != q->val) return false;
		//p = p->next;
		//while (p)
		//{
		//	if (p->val != pre->val) return false;
		//	p = p->next;
		//	pre = pre->next;
		//}
		//return true;
		if (!head) return true;
		ListNode* p = head, *q = head;
		while (p->next && p->next->next)
		{
			p = p->next->next;
			q = q->next;
		}
		//p = p->next ? q->next : q;
		if (p->next)
		{
			p = q->next;
		}
		else
		{
			ListNode node = *q;
			p = &node;
		}
		q->next = NULL;
		q = reverseList(head);

		while (p)
		{
			if (p->val != q->val) return false;
			p = p->next;
			q = q->next;
		}
		return true;
	}
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

