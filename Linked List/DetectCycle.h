#pragma once
#include "ListNode.h"
#include <unordered_set>
/*
Linked List Cycle II My Submissions Question
Total Accepted: 58867 Total Submissions: 187264 Difficulty: Medium
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?

Subscribe to see which companies asked this question

Hide Tags Linked List Two Pointers
Hide Similar Problems (M) Linked List Cycle (H) Find the Duplicate Number

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
	ListNode *detectCycle(ListNode *head) {
		ListNode* step1 = head;
		ListNode* step2 = head;
		while (step2 &&step2->next&&step1)
		{
			step1 = step1->next;
			step2 = step2->next->next;
			if (step1 == step2) //find cycle only,can not find first node where cycle begins
			{
				step1 = head;
				while (step1 != step2)
				{
					step1 = step1->next;
					step2 = step2->next;
				}
				return step1;
			}
		}
		return NULL;
	}

	////32ms
	//ListNode *detectCycle(ListNode *head) {
	//	std::unordered_set<ListNode*> s;
	//	while (head)
	//	{
	//		if (s.find(head) != s.end())
	//			break;
	//		else
	//		{
	//			s.insert(head);
	//			head = head->next;
	//		}
	//	}
	//	return head;
	//}
};