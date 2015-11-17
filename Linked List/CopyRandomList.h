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



//108ms
// Here's how the 2nd algorithm goes.
// Consider l1 as a node on the 1st list and l2 as the corresponding node on 2nd list.
// Step 1:
// Build the 2nd list by creating a new node for each node in 1st list. 
// While doing so, set the next pointer of the new node to the random pointer 
// of the corresponding node in the 1st list.  And set the random pointer of the 
// 1st list's node to the newly created node.
// Step 2:
// The new head is the node pointed to by the random pointer of the 1st list.
// Step 3:
// Fix the random pointers in the 2nd list: (Remember that l1->random is l2)
// l2->random will be the node in 2nd list that corresponds to the node in the 
// 1st list that is pointed to by l2->next, 
// Step 4:
// Restore the random pointers of the 1st list and fix the next pointers of the 
// 2nd list. random pointer of the node in 1st list is the next pointer of the 
// corresponding node in the 2nd list.  This is what we had done in the 
// 1st step and now we are reverting back. next pointer of the node in 
// 2nd list is the random pointer of the node in 1st list that is pointed to 
// by the next pointer of the corresponding node in the 1st list.
// Return the new head that we saved in step 2.
//
class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		RandomListNode *newHead, *l1, *l2;
		if (head == NULL) return NULL;

		for (l1 = head; l1 != NULL; l1 = l1->next) {
			l2 = new RandomListNode(l1->label);
			l2->next = l1->random;
			l1->random = l2;
		}

		newHead = head->random;
		for (l1 = head; l1 != NULL; l1 = l1->next) {
			l2 = l1->random;
			l2->random = l2->next ? l2->next->random : NULL;
		}

		for (l1 = head; l1 != NULL; l1 = l1->next) {
			l2 = l1->random;
			l1->random = l2->next;
			l2->next = l1->next ? l1->next->random : NULL;
		}

		return newHead;
	}
};