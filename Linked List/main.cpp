#include "DetectCycle.h"

#include <iostream>
using std::cout;
using std::endl;

int main()
{

	ListNode d(4);
	ListNode c(3);
	ListNode b(2);
	ListNode a(1);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &b;


	//ListNode *p = &a;
	//while (p)
	//{
	//	cout << p->val << ' ';
	//	p = p->next;
	//}
	//cout << endl;
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
	cout << s.detectCycle(&a)->val << endl;
	//p = s.insertionSortList(&a);
	//while (p)
	//{
	//	cout << p->val << ' ';
	//	p = p->next;
	//}
	//cout << endl;
}
