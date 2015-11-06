#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(ListNode*n = NULL, int x = 0) : val(x), next(n) {}
};

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		//unordered_set<ListNode*> s;
		//ListNode *p = headA;
		//ListNode *q = headB;
		//while (p)
		//{
		//	s.insert(p);
		//	p = p->next;
		//}
		//while (q)
		//{
		//	if (s.find(q) != s.end())
		//		break;
		//	q = q->next;
		//}
		//return q;

		ListNode *p = headA;
		ListNode *q = headB;
		while (p && q)
		{
			if (p == q) return p;
			p = p->next;
			q = q->next;

			if (!q) q = headA;
			if (!p)p = headB;
		}
		return NULL;
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

	int fuck(ListNode* p, int n) {
		if (!p)	return 0;
		auto x = fuck(p->next, n);
		if (x == n)
			p->next = p->next->next;
		return x + 1;
	}

	ListNode* removeNthFromEnd(ListNode* head, int n) {
		//ListNode x;
		//x.next = head;
		//fuck(&x,n);
		//return x.next;

		if (!head) return head;

		ListNode **pp = &head;
		ListNode *q = head;
		for (size_t i = 0; i < n; i++)
			q = q->next;
		while (q)
		{
			q = q->next;
			pp = &(*pp)->next;
		}
		if (*pp)
		{
			*pp = (*pp)->next;
		}
		return head;

	}

	void deleteNode(ListNode* node) {
		std::swap(*node, *node->next);
	}

	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		////iterative
		//	ListNode headNode, *p = &headNode;
		//	while (l1 && l2)
		//	{
		//		if (l1->val < l2->val)
		//		{
		//			p->next = l1;
		//			p = l1;
		//			l1 = l1->next;
		//		}
		//		else
		//		{
		//			p->next = l2;
		//			p = l2;
		//			l2 = l2->next;
		//		}
		//	}
		//	if (l1)
		//	{
		//		p->next = l1;
		//	}
		//	if (l2)
		//	{
		//		p->next = l2;
		//	}
		//	return headNode.next;

		//recursive
		if (!l1) return l2;
		if (!l2) return l1;

		if (l1->val < l2->val)
		{
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}
		else
		{
			l2->next = mergeTwoLists(l2->next, l1);
			return l2;
		}

	}

	/*
	Palindrome Linked List My Submissions Question
	Total Accepted: 26053 Total Submissions: 106837 Difficulty: Easy
	Given a singly linked list, determine if it is a palindrome.

	Follow up:
	Could you do it in O(n) time and O(1) space?
	*/
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

	ListNode* deleteDuplicates(ListNode* head)
	{
		auto p = head;
		while (p)
		{
			auto q = p->next;
			while (q && q->val == p->val)
				q = q->next;
			p->next = q;
			p = q;
		}
		return head;
	}

	ListNode* removeElements(ListNode* head, int val) {
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

	ListNode* insertionSortList(ListNode* head) {
		if (!head || !head->next) return head;
		for (ListNode** pq = &head->next; *pq; pq = &(*pq)->next)
		{
			ListNode** pp = &head;
			while (pq != pp && (*pq)->val > (*pp)->val)
				pp = &(*pp)->next;
			if (pq == pp)
				continue;

			auto node = *pq;
			*pq = (*pq)->next;
			auto tmp = *pp;
			*pp = node;
			(*pp)->next = tmp;
		}
		return head;
	}
};

int main()
{
	ListNode* x = NULL;
	ListNode** xx = &x;
	cout << "xx:" << xx << endl;
	ListNode d(NULL, 5);
	ListNode c(&d, 4);
	ListNode b(&c, 2);
	ListNode a(&b, 7);
	ListNode *p = &a;
	while (p)
	{
		cout << p->val << ' ';
		p = p->next;
	}
	cout << endl;
	//ListNode d2(NULL, 44);
	//ListNode c2(&d2, 32);
	//ListNode b2(&c2, 24);
	//ListNode a2(&b, 11);
	//p = &a2;
	//while (p)
	//{
	//	cout << p->val << ' ';
	//	p = p->next;
	//}
	//cout << endl;
	Solution s;
	p = s.insertionSortList(&a);
	while (p)
	{
		cout << p->val << ' ';
		p = p->next;
	}
	cout << endl;
}
