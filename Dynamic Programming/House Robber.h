#pragma once
#include <vector>
#include <algorithm>
using std::vector;
/*
House Robber My Submissions Question
Total Accepted: 42061 Total Submissions: 133554 Difficulty: Easy
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Credits:
Special thanks to @ifanchu for adding this problem and creating all test cases. Also thanks to @ts for adding additional test cases.

Subscribe to see which companies asked this question

Hide Tags Dynamic Programming
Hide Similar Problems (M) Maximum Product Subarray (M) House Robber II (M) Paint House (E) Paint Fence
*/


//0ms
//class Solution {
//public:
//	vector<vector<int>> m;
//	vector<int> *pnums;
//	int rob(vector<int>& nums) {
//		m.resize(nums.size(), vector<int>(nums.size(), -1));
//		pnums = &nums;
//		return getM(0, nums.size() - 1);
//	}
//	int getM(int i, int j) {
//		if (i > j)
//			return 0;
//		if (m[i][j] == -1)
//		{
//			if (i == j) 
//				m[i][j] = (*pnums)[i];
//			else
//				m[i][j] = std::max((*pnums)[i] + getM(i + 2, j), getM(i + 1, j));
//		}
//
//		return m[i][j];
//
//	}
//
//};

////time limit
//class Solution {
//public:
//	vector<int> *pnums;
//	int rob(vector<int>& nums) {
//		pnums = &nums;
//		return getM(0, nums.size() - 1);
//	}
//	int getM(int i, int j) {
//		if (i > j)
//			return 0;
//		if (i == j)
//			return (*pnums)[i];
//		else
//			return  std::max((*pnums)[i] + getM(i + 2, j), getM(i + 1, j));
//	}
//
//};


//elegant
class Solution {
public:
	int rob(vector<int>& nums) {
		int a = 0;
		int b = 0;

		for (int i = 0; i < nums.size(); i++)
		{
			if (i % 2 == 0)
			{
				a = std::max(a + nums[i], b);
			}
			else
			{
				b = std::max(a, b + nums[i]);
			}
		}
		return std::max(a, b);
	}
};