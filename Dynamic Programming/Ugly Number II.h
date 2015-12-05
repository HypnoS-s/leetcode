#pragma once
#include <unordered_set>
#include <vector>
using namespace std;


//time limit 
class Solution {
public:

	bool isUgly(int num) {
		if (num <= 0) return false;
		if (num % 2 == 0 && s.find(num / 2) != s.end())
			return true;
		if (num % 3 == 0 && s.find(num / 3) != s.end())
			return true;
		if (num % 5 == 0 && s.find(num / 5) != s.end())
			return true;
		return false;
	}
	int nthUglyNumber(int n) {
		while (n > m)
		{
			if (isUgly(++max))
			{
				u.push_back(max);
				s.insert(max);
				m++;
			}
		}
		return u[n - 1];

	}
private:
	std::unordered_set<int> s = { 1,2,3,4,5 };
	std::vector<int> u = { 1,2,3,4,5 };
	int max = 5;
	int m = 5;
};
