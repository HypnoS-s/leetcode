#pragma once
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

//
////time limit 
//class Solution {
//public:
//
//	bool isUgly(int num) {
//		if (num <= 0) return false;
//		if (num % 2 == 0 && s.find(num / 2) != s.end())
//			return true;
//		if (num % 3 == 0 && s.find(num / 3) != s.end())
//			return true;
//		if (num % 5 == 0 && s.find(num / 5) != s.end())
//			return true;
//		return false;
//	}
//	int nthUglyNumber(int n) {
//		while (n > m)
//		{
//			if (isUgly(++max))
//			{
//				u.push_back(max);
//				s.insert(max);
//				m++;
//			}
//		}
//		return u[n - 1];
//
//	}
//private:
//	std::unordered_set<int> s = { 1,2,3,4,5 };
//	std::vector<int> u = { 1,2,3,4,5 };
//	int max = 5;
//	int m = 5;
//};

////52ms,48ms
//class Solution {
//public:
//	int nthUglyNumber(int n) {
//		vector<int> ugly = { 1 };
//		int i{ 0 }, j{ 0 }, k{ 0 };
//		while (ugly.size()<n)
//		{
//			ugly.push_back(std::min({ ugly[i]*2,ugly[j]*3,ugly[k]*5 }));
//			if (ugly.back() == ugly[i] * 2) ++i;
//			if (ugly.back() == ugly[j] * 3) ++j;
//			if (ugly.back() == ugly[k] * 5) ++k;
//		}
//		return ugly.back();
//	}
//};



////36ms ,std::min{a,b,c} slower than std::min(a,std::min(b,c)).
//class Solution {
//public:
//	int nthUglyNumber(int n) {
//		vector<int> ugly = { 1 };
//		int i{ 0 }, j{ 0 }, k{ 0 };
//		while (ugly.size()<n)
//		{
//			ugly.push_back(std::min( ugly[i] * 2,std::min(ugly[j] * 3,ugly[k] * 5 )));
//			if (ugly.back() == ugly[i] * 2) ++i;
//			if (ugly.back() == ugly[j] * 3) ++j;
//			if (ugly.back() == ugly[k] * 5) ++k;
//		}
//		return ugly.back();
//	}
//};


////44ms.40ms,40ms
//class Solution {
//public:
//	int nthUglyNumber(int n) {
//		while (ugly.size()<n)
//		{
//			ugly.push_back(std::min( ugly[i] * 2,std::min(ugly[j] * 3,ugly[k] * 5 )));
//			if (ugly.back() == ugly[i] * 2) ++i;
//			if (ugly.back() == ugly[j] * 3) ++j;
//			if (ugly.back() == ugly[k] * 5) ++k;
//		}
//		return ugly[n-1];
//	}
//private:
//		vector<int> ugly = { 1 };
//		int i{ 0 }, j{ 0 }, k{ 0 };
//
//};

//4ms.
class Solution {
public:
	int nthUglyNumber(int n) {
		static vector<int> ugly = { 1 };
		static int i{ 0 }, j{ 0 }, k{ 0 };
		while (ugly.size()<n)
		{
			ugly.push_back(std::min( ugly[i] * 2,std::min(ugly[j] * 3,ugly[k] * 5 )));
			if (ugly.back() == ugly[i] * 2) ++i;
			if (ugly.back() == ugly[j] * 3) ++j;
			if (ugly.back() == ugly[k] * 5) ++k;
		}
		return ugly[n-1];
	}
};