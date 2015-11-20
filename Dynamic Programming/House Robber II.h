#pragma once
#include <vector>
#include <algorithm>
using std::max;
using std::vector;

/*
House Robber II My Submissions Question
Total Accepted: 16772 Total Submissions: 59203 Difficulty: Medium
Note: This is an extension of House Robber.

After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Hide Tags Dynamic Programming
Hide Similar Problems (E) House Robber (M) Paint House (E) Paint Fence
*/


//0ms
class Solution {
public:
	int rob(vector<int>& nums) {
		auto n = nums.size();
		if (n == 0) return 0;
		if (n == 1) return nums[0];
		if (n == 2)	return std::max(nums[0], nums[1]);
		auto b = nums.begin(), e = nums.end();
		vector<int> v1(b + 1, e), v2(b + 2, e - 1);
		return std::max(rob2(v1), rob2(v2) + nums[0]);
	}

	int rob2(vector<int>& nums) {
		int a = 0, b = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (i % 2 == 0)
				a = std::max(a + nums[i], b);
			else
				b = std::max(a, b + nums[i]);
		}
		return std::max(a, b);
	}
};