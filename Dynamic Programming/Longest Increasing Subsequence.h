#pragma once
#include <vector>
#include <algorithm>
using std::vector;
/*Longest Increasing Subsequence My Submissions Question
Total Accepted: 7356 Total Submissions: 23679 Difficulty: Medium
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?

Credits:
Special thanks to @pbrother for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Hide Tags Dynamic Programming Binary Search

*/

class Solution {
public:
	vector<vector<int>> M;
	vector<vector<int>> E;
	int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
		M.resize(n, vector<int>(n,1));
		E.resize(n, vector<int>(n));

	}
};