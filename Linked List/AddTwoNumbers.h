#pragma once
#include "ListNode.h"

/*
Add Two Numbers My Submissions Question
Total Accepted: 101172 Total Submissions: 478694 Difficulty: Medium
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

Subscribe to see which companies asked this question

Hide Tags Linked List Math
Hide Similar Problems (M) Multiply Strings (E) Add Binary
*/



////40ms
//class Solution {
//public:
//	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//		int x = 0, t = 0;
//		ListNode *head=NULL, **pp=&head;
//		while (l1 && l2)
//		{
//			x = l1->val + l2->val + t;
//			t = x / 10;
//			x %= 10;
//			auto node = new ListNode(x);
//			*pp = node;
//			l1 = l1->next;
//			l2 = l2->next;
//			pp = &node->next;
//		}
//		while (l1)
//		{
//			x = l1->val + t;
//			t = x / 10;
//			x %= 10;
//			auto node = new ListNode(x);
//			*pp = node;
//			l1 = l1->next;
//			pp = &node->next;
//		}
//		while (l2)
//		{
//			x = l2->val + t;
//			t = x / 10;
//			x %= 10;
//			auto node = new ListNode(x);
//			*pp = node;
//			l2 = l2->next;
//			pp = &node->next;
//		}
//		if (t)
//		{
//			auto node = new ListNode(1);
//			*pp = node;
//		}
//		return head;
//	}
//};


////40ms
//class Solution {
//public:
//	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//		int x = 0, t = 0;
//		ListNode *head = NULL, **pp = &head;
//		while (l1 || l2)
//		{
//			x = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + t;
//			t = x / 10;
//			x %= 10;
//			auto node = new ListNode(x);
//			*pp = node;
//			l1 = l1 ? l1->next : NULL;
//			l2 = l2 ? l2->next : NULL;
//			pp = &node->next;
//		}
//
//		if (t)
//		{
//			auto node = new ListNode(1);
//			*pp = node;
//		}
//		return head;
//	}
//};


//40ms
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int x = 0, t = 0;
		ListNode *head = NULL, **pp = &head;
		while (l1 || l2 || t)
		{
			x = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + t;
			t = x / 10;
			x %= 10;
			*pp = new ListNode(x);
			l1 = l1 ? l1->next : NULL;
			l2 = l2 ? l2->next : NULL;
			pp = &(*pp)->next;
		}

		return head;
	}
};