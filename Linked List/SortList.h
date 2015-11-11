#pragma once
#include "ListNode.h"
#include <utility>

/*
Sort List My Submissions Question
Total Accepted: 57371 Total Submissions: 247761 Difficulty: Medium
Sort a linked list in O(n log n) time using constant space complexity.

Subscribe to see which companies asked this question

Hide Tags Linked List Sort
Hide Similar Problems (E) Merge Two Sorted Lists (M) Sort Colors (M) Insertion Sort List

*/

 
class Solution {
public:
	/*
	//qiucksort :stack overflow
	void QUICKSORT(ListNode* p, ListNode* r)
	{
		if (p == r || p->next == r)
			return;

		auto q = PARTITION(p, r);
		QUICKSORT(p, q);
		QUICKSORT(q->next, r);
	}
	ListNode* PARTITION(ListNode* b, ListNode* e)
	{
		auto x = b->val;
		auto p = b, q = b->next;
		while (q!=e)
		{
			if (q->val<=x)
			{
				p = p->next;
				std::swap(p->val,q->val);
			}
			q = q->next;
		}
		std::swap(p->val, b->val);
		return p;
	}
	*/

	size_t count_nodes(ListNode* head)
	{
		size_t n = 0;
		while (head)
		{
			++n;
			head = head->next;
		}
		return n;
	}

	ListNode* MERGE(ListNode* l1, ListNode* l2) {
		//iterative
		ListNode headNode(0), *p = &headNode;
		while (l1 && l2)
		{
			if (l1->val < l2->val)
			{
				p->next = l1;
				p = l1;
				l1 = l1->next;
			}
			else
			{
				p->next = l2;
				p = l2;
				l2 = l2->next;
			}
		}
		if (l1)
		{
			p->next = l1;
		}
		if (l2)
		{
			p->next = l2;
		}
		return headNode.next;
	}
	////64ms
	//ListNode* MERGE_SORT(ListNode* head)
	//{
	//	auto N = count_nodes(head);
	//	if (N <= 1) return head;

	//	auto q = head;
	//	for (decltype(N) i = 1;i<N / 2;++i)
	//		q = q->next;

	//	auto l2 = q->next;
	//	q->next = NULL;

	//	head = MERGE_SORT(head);
	//	l2 = MERGE_SORT(l2);

	//	return MERGE(head, l2);
	//}


	//56ms
	ListNode* MERGE_SORT(ListNode* head)
	{
 
		if (!head || !head->next) return head;

		auto fast = head, slow = head;
		while (fast->next && fast->next->next)
		{
			fast = fast->next->next;
			slow = slow->next;
		}

		fast = slow->next;
		slow->next = NULL;
 
		return MERGE(MERGE_SORT(head), MERGE_SORT(fast));
	}


	ListNode* sortList(ListNode* head) {
		return MERGE_SORT(head);
	}
};