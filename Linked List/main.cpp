#include "SwapPairs.h"

#include <iostream>
#include <vector>
using std::cout;
using std::endl;

int main()
{
	std::vector<int> vi = {};

	size_t N = vi.size();
	std::vector<ListNode> v(N,0);
 
	for (size_t i = 0; i < N; i++)
	{
		v[i].val = vi[i];
		v[i].next = (i == N - 1) ? NULL : &v[i + 1];
	}

	//ListNode d(4);
	//ListNode c(1);
	//ListNode b(5);
	//ListNode a(3);
	//a.next = &a;
	//b.next = &c;
	//c.next = &d;
	//d.next = &b;


	//ListNode *p = x;
	//while (p)
	//{
	//	cout << p->val << ' ';
	//	p = p->next;
	//}
	//cout << endl;
	//cout << endl;
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
	ListNode* p = v.size()?&v[0]:NULL;

	  p = s.swapPairs(p);

//	auto p = &a;
	while (p)
	{
		cout << p->val << ' ';
		p = p->next;
	}
	cout << endl;

}
