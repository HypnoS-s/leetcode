#pragma once
#include "ListNode.h"

/*
Remove Duplicates from Sorted List II My Submissions Question
Total Accepted: 57010 Total Submissions: 223095 Difficulty: Medium
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

Subscribe to see which companies asked this question

Hide Tags Linked List

*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	//12ms
	ListNode* deleteDuplicates(ListNode* head) {
		auto pp = &head;
		while (*pp)
		{
			if (!(*pp)->next || (*pp)->val != (*pp)->next->val)
				pp = &(*pp)->next;
			else
			{
				auto q = (*pp)->next;
				while (q && q->val == (*pp)->val)
					q = q->next;
				*pp = q;

			}
		}
		return head;
	}
	//8ms
	ListNode *deleteDuplicates(ListNode *head) {
		ListNode **runner = &head;

		if (!head || !head->next)return head;

		while (*runner)
		{
			if ((*runner)->next && (*runner)->next->val == (*runner)->val)
			{
				ListNode *temp = *runner;
				while (temp && (*runner)->val == temp->val)
					temp = temp->next;

				*runner = temp;
			}
			else
				runner = &((*runner)->next);
		}

		return head;
	}


};