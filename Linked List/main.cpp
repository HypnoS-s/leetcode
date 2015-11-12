#include "Partition.h"
#include <iostream>
#include <vector>
using std::cout;
using std::endl;

int main()
{
	std::vector<int> vi = {1,4,3,2,5,2};


	size_t N = vi.size();
	std::vector<ListNode> v(N,0);
 
	for (size_t i = 0; i < N; i++)
	{
		v[i].val = vi[i];
		v[i].next = (i == N - 1) ? NULL : &v[i + 1];
	}


	//std::vector<int> vi2 = {5,6,4,9,9,9};
	//size_t N2 = vi2.size();
	//std::vector<ListNode> v2(N2, 0);

	//for (size_t i = 0; i < N2; i++)
	//{
	//	v2[i].val = vi2[i];
	//	v2[i].next = (i == N2 - 1) ? NULL : &v2[i + 1];
	//}


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

	p = s.partition(p, 3);

//	auto p = &a;
	while (p)
	{
		cout << p->val << ' ';
		p = p->next;
	}
	cout << endl;

}
