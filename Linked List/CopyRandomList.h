#pragma once
#include "RandomListNode.h"
#include <unordered_map>
#include <memory>
/*
Copy List with Random Pointer My Submissions Question
Total Accepted: 52476 Total Submissions: 204466 Difficulty: Hard
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

Subscribe to see which companies asked this question

Hide Tags Hash Table Linked List
Hide Similar Problems (M) Clone Graph

*/

/**
* Definition for singly-linked list with a random pointer.
* struct RandomListNode {
*     int label;
*     RandomListNode *next, *random;
*     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
* };
*/
//204ms
//class Solution {
//public:
//	size_t len = 0;
//	std::vector<RandomListNode*> v;
//
//	int find_pos(RandomListNode* p)
//	{
//		if (!p) return -1;
//		for (size_t i = 0; i < len; i++)
//		{
//			if (v[i]==p)
//			{
//				return i;
//			}
//		}
//		return -1;
//	}
//	RandomListNode *copyRandomList(RandomListNode *head) {
//		if (!head)return NULL;
//		while (head)
//		{
//			len++;
//			v.push_back(head);
//			head = head->next;
//		}
//		int x,i=0;
//		std::vector<RandomListNode> *v2 = new std::vector < RandomListNode>(len,0);
//		for (; i < len-1; i++)
//		{
//			(*v2)[i].label = v[i]->label;
//			(*v2)[i].next = &(*v2)[i + 1];
//			x = find_pos(v[i]->random);
//			(*v2)[i].random = x == -1 ? NULL : &(*v2)[x];
//		}
//		(*v2)[i].label = v[i]->label;
//		x = find_pos(v[i]->random);
//		(*v2)[i].random = x == -1 ? NULL : &(*v2)[x];
//
//		return &(*v2)[0];
//	}
//};


////120 ms
//class Solution {
//public:
//	size_t length = 0;
//	std::unordered_map<RandomListNode*, int> m;
//	int find_pos(RandomListNode* p)
//	{
//		//if (!p) return -1;
//		if (m.find(p)!=m.end())
//		{
//			return m[p];
//		}
//		return -1;
//	}
//	RandomListNode *copyRandomList(RandomListNode *head) {
//		if (!head)return NULL;
//		auto p = head;
//		while (p)
//		{
//			m[p] = length;
//			p = p->next;
//			length++;
//		}
//		int x, i = 0;
//		std::vector<RandomListNode> *v2 = new std::vector < RandomListNode>(length, 0);
//		for (p = head; i < length - 1; i++, p = p->next)
//		{
//			(*v2)[i].label = p->label;
//			(*v2)[i].next = &(*v2)[i + 1];
//			x = find_pos(p->random);
//			(*v2)[i].random = x == -1 ? NULL : &(*v2)[x];
//		}
//		(*v2)[i].label = p->label;
//		x = find_pos(p->random);
//		(*v2)[i].random = x == -1 ? NULL : &(*v2)[x];
//
//		return &(*v2)[0];
//	}
//};


// 120 ms
class Solution {
public:
	int x, i, length = 0;
	std::unordered_map<RandomListNode*, int> m;
	std::allocator<RandomListNode> alloc;
	int find_pos(RandomListNode* p)
	{
		if (m.find(p) != m.end())
			return m[p];
		return -1;
	}
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (!head)return NULL;
		auto p = head;
		while (p)
		{
			m[p] = length;
			p = p->next;
			length++;
		}
		auto v2 = alloc.allocate(length);
		for (i = 0, p = head; i < length ; i++, p = p->next)
		{
			alloc.construct(v2 + i,p->label);
			(v2 + i)->next = v2 + i + 1;
			x = find_pos(p->random);
			(v2+i)->random = x == -1 ? NULL : v2+x;
		}
		(v2 + i-1)->next = NULL;

		return v2;
	}
};

//108ms,from discuss, very smart.
//first,duplicate the list ,each node insert after its origin node;
//second round,modify the random pointer,just walk node by node;
//third,split list into two.
class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (!head) return NULL;
		RandomListNode* run = head;
		/* Insert the copy of each node after it. */
		while (run) {
			RandomListNode* copy = new RandomListNode(run->label);
			copy->next = run->next;
			run->next = copy;
			run = run->next->next;
		}
		/* Set the random pointer for each copy. */
		run = head;
		while (run) {
			if (run->random)
				run->next->random = run->random->next;
			run = run->next->next;
		}
		/* Extract the copy list. */
		RandomListNode* new_head = new RandomListNode(0);
		RandomListNode* new_run;
		run = head;
		new_head->next = head->next;
		while (run) {
			new_run = run->next;
			run->next = new_run->next;
			if (run->next)
				new_run->next = new_run->next->next;
			run = run->next;
		}
		return new_head->next;
	}
};