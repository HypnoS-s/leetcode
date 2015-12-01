#pragma once
#include <vector>
#include <algorithm>
using std::vector;

/*
Best Time to Buy and Sell Stock My Submissions Question
Total Accepted: 75813 Total Submissions: 221469 Difficulty: Medium
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Subscribe to see which companies asked this question

Hide Tags Array Dynamic Programming
Hide Similar Problems (M) Maximum Subarray (M) Best Time to Buy and Sell Stock II (H) Best Time to Buy and Sell Stock III (H) Best Time to Buy and Sell Stock IV (M) Best Time to Buy and Sell Stock with Cooldown
*/


class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		//if(n<=1) return 0;
		int max = 0;
		int min = INT_MAX;
		for (int i = 0; i<n; i++)
		{
			if (prices[i]<min)
				min = prices[i];
			max = std::max(max, prices[i] - min);
		}
		return max;
	}
};