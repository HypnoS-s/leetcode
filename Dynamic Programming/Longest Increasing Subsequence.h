#pragma once
#include <vector>
#include <algorithm>
#include <map>
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

//
////96ms , O(n*n)
//class Solution {
//public:
//
//	int lengthOfLIS(vector<int>& nums) {
//		int n = nums.size();
//		vector<int> M(n, 0);//M[i] :the LIS end with nums[i]
//		int ret = 0;
//		for (int i = 0; i < n; i++)
//		{
//			int z = 0;
//			for (int j = 0; j < i; j++)
//				if (nums[j] < nums[i])
//					z = std::max(z, M[j]);
//			M[i] = z + 1;
//			ret = std::max(M[i], ret);
//		}
//		return ret;
//	}
//};

////24ms , O(n*k),k:LIS
//class Solution {
//public:
//
//	int lengthOfLIS(vector<int>& nums) {
//		int n = nums.size();
//		vector<int> M(n,INT_MAX);//M[i] :the LIS is i,and end with M[i]
//		int len=0;
//		for (int i = 0; i < n; i++)
//		{
//			int j = 0;
//			while (M[j]<nums[i])
//			{
//				j++;
//			}
//			if (M[j] == INT_MAX) len++;
//			M[j] = nums[i];
//		}
//		return len;
//	}
//};


////64ms , O(n*k),k:LIS
//class Solution {
//public:
//	int lengthOfLIS(vector<int>& nums) {
// 
//		vector<int> M;
//		for (auto &num:nums)
//		{
//			auto b = M.begin();
//			while (b != M.end()&&*b < num)
//				++b;
//			if (b == M.end())
//				M.push_back(num);
//			else
//				*b = num;
//		}
//		return M.size();
//	}
//};


