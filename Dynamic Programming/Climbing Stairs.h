#pragma once
#include <unordered_map>
/*
Climbing Stairs My Submissions Question
Total Accepted: 80379 Total Submissions: 228150 Difficulty: Easy
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Subscribe to see which companies asked this question

Hide Tags Dynamic Programming
*/
////0ms
//class Solution {
//public:
//	std::unordered_map<int, int> m = { {0,1},{1,1} };
//	int climbStairs(int n) {
//		if (m.find(n)==m.end())
//		{
//			m[n] = climbStairs(n - 1) + climbStairs(n - 2);
//		}
//		return m[n];
//	}
//};



//0ms
class Solution {
public:

	int climbStairs(int n) {
		if (n < 2) return 1;
		int one_past = 1, two_past = 1;
		int curr = 0;
		for (int i = 2; i <= n; i++)
		{
			curr = one_past + two_past;
			two_past = one_past;
			one_past = curr;
		}
		return curr;
	}
};