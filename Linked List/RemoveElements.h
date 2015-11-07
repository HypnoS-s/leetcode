#pragma once
#include "ListNode.h"

/*
Remove Linked List Elements My Submissions Question
Total Accepted: 39305 Total Submissions: 148408 Difficulty: Easy
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems

*/

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		//iterative 36ms
		ListNode** pp = &head;
		while (*pp)
		{
			if ((*pp)->val == val)
			{
				*pp = (*pp)->next;
			}
			else
			{
				pp = &(*pp)->next;
			}
		}
		return head;
	}

	//ListNode* removeElements(ListNode* head, int val) {
	//	//recursive 36ms
	//	if (!head) return NULL;
	//	head->next = removeElements(head->next, val);
	//	return head->val == val ? head->next:head;
	//}
};