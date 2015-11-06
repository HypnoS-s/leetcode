#include "ListNode.h"
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	ListNode* x = NULL;
	ListNode** xx = &x;
	cout << "xx:" << xx << endl;
	ListNode d(5);
	ListNode c(42);
	ListNode b(222);
	ListNode a(1111);
	a.next = b;
	b.next = c;
	c.next = d;


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
