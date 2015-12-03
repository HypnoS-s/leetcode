#pragma once
#include <vector>
#include <algorithm>
using std::vector;

/*
Maximum Product Subarray My Submissions Question
Total Accepted: 46253 Total Submissions: 223092 Difficulty: Medium
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.

Subscribe to see which companies asked this question

Hide Tags Array Dynamic Programming
Hide Similar Problems (M) Maximum Subarray (E) House Robber (M) Product of Array Except Self

*/

//8ms
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		if (!nums.size()) return 0;
		int maxhere = 1;
		int minhere = 1;
		int maxsofar = INT_MIN;
		int maxpre = maxhere;// , minhere = minhere;
		for (auto& x : nums)
		{
			maxhere = std::max({ maxpre*x,minhere*x,x });
			minhere = std::min({ maxpre*x,minhere*x,x });
			maxsofar = std::max(maxhere, maxsofar);
			maxpre = maxhere;
			//minhere = minhere;
		}
		return maxsofar;
	}
};