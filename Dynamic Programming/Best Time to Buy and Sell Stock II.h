#pragma once
#include <vector>
using std::vector;

/*
Best Time to Buy and Sell Stock II My Submissions Question
Total Accepted: 68553 Total Submissions: 171021 Difficulty: Medium
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Subscribe to see which companies asked this question

Hide Tags Array Greedy
Hide Similar Problems (M) Best Time to Buy and Sell Stock (H) Best Time to Buy and Sell Stock III (H) Best Time to Buy and Sell Stock IV (M) Best Time to Buy and Sell Stock with Cooldown
*/

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int sum = 0, n = prices.size();
		for (int i = 0; i<n - 1; i++)
			if (prices[i + 1]>prices[i])
				sum += prices[i + 1] - prices[i];
		return sum;
	}
};

