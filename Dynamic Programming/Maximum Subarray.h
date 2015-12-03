#pragma once
#include <vector>
#include <algorithm>
using std::vector;

/*
Maximum Subarray My Submissions Question
Total Accepted: 86961 Total Submissions: 245907 Difficulty: Medium
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [?2,1,?3,4,?1,2,1,?5,4],
the contiguous subarray [4,?1,2,1] has the largest sum = 6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

Subscribe to see which companies asked this question

Hide Tags Divide and Conquer Array Dynamic Programming
Hide Similar Problems (M) Best Time to Buy and Sell Stock (M) Maximum Product Subarray
*/

////12ms
//class Solution {
//public:
//	int maxSubArray(vector<int>& nums) {
//		int n = nums.size();
//		vector<int> M(n);
//		int max = M[0] = nums[0];
//		for (int i = 1; i < n; i++)
//		{
//			M[i] = (M[i - 1]>0 ? M[i - 1] : 0) + nums[i];
//			max = std::max(max, M[i]);
//		}
//		return max;
//	}
//};


//8ms,12ms
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int max = INT_MIN;
		int sum = 0;
		for (auto&x : nums)
		{
			sum = (sum > 0 ? sum : 0) + x;
			max = std::max(max, sum);
		}
		return max;
	}
};