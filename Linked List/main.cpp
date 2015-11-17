#include "ReverseKGroup.h"
#include <iostream>
#include <vector>
using std::cout;
using std::endl;

int main()
{
	std::vector<int> vi = {1,2,3,4,5};
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

	Solution s;
	ListNode* p = v.size()?&v[0]:NULL;

	auto q = p;
	q = s.reverseKGroup(q, 5);

//	auto p = &a;
	while (q)
	{
		cout << q->val << ' ';
		q = q->next;
	}
	cout << endl;

	//std::vector<RandomListNode> v = {1,2,3,4,5};
	//v[0].next = &v[1];
	//v[1].next = &v[2];
	//v[2].next = &v[3];
	//v[3].next = &v[4];
	//v[4].next = NULL;

	//v[0].random = NULL;
	//v[1].random = &v[3];
	//v[2].random = &v[3];
	//v[3].random = &v[3];
	//v[4].random = &v[3];

	//Solution s;
	//auto x = s.copyRandomList(&v[0]);

	return 0;
}
