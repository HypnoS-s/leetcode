#pragma once
#include "ListNode.h"

/*
Linked List Cycle My Submissions Question
Total Accepted: 81905 Total Submissions: 223828 Difficulty: Medium
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?

Subscribe to see which companies asked this question

Hide Tags Linked List Two Pointers
Hide Similar Problems (M) Linked List Cycle II

*/


class Solution {
public:
	//16ms
	bool hasCycle(ListNode *head) {
		auto fast = head, slow = head;
		while (fast && fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow) return true;
		}
		return false;
	}

	//12ms
	bool hasCycle(ListNode *head) {
		auto fast = head;
		while (fast && fast->next)
		{
			fast = fast->next->next;
			head = head->next;
			if (fast == head) return true;
		}
		return false;

	}


};