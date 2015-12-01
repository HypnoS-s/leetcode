#pragma once
#include <vector>
#include <algorithm>
using std::vector;


/*
Best Time to Buy and Sell Stock III My Submissions Question
Total Accepted: 46476 Total Submissions: 186644 Difficulty: Hard
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Subscribe to see which companies asked this question

Hide Tags Array Dynamic Programming
Hide Similar Problems (M) Best Time to Buy and Sell Stock (M) Best Time to Buy and Sell Stock II (H) Best Time to Buy and Sell Stock IV
*/


////16ms , find the extremum to reduce de data scale
//class Solution {
//public:
//	int maxProfit(vector<int>& prices) {
//		int n = prices.size();
//		if (!n) return 0;
//		vector<int> v;
//		v.push_back(prices[0]);
//		for (int i = 1; i<n - 1; i++)
//		{
//			if ((prices[i - 1] <= prices[i] && prices[i + 1] <= prices[i]) ||
//				(prices[i - 1] >= prices[i] && prices[i + 1] >= prices[i]))
//			{
//				if(prices[i]!=v.back())
//					v.push_back(prices[i]);
//			}
//		}
//		v.push_back(prices[n - 1]);
//		int max = 0;
//		for (int i = 0; i<v.size(); i++)
//		{
//			max = std::max(max, _maxProfit(v, 0, i) + _maxProfit(v, i, v.size() - 1));
//		}
//		return max;
//	}
//	int _maxProfit(vector<int> &prices, int b, int e) {
//		int max = 0;
//		int min = INT_MAX;
//		for (int i = b; i <= e; i++)
//		{
//			if (prices[i]<min)
//				min = prices[i];
//			max = std::max(max, prices[i] - min);
//		}
//		return max;
//	}
//};


//8ms
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int states[4] = { INT_MIN,0,INT_MIN,0 };
		for (auto& x : prices)
		{
			states[0] = std::max(states[0],-x);
			states[1] = std::max(states[1], states[0]+x);
			states[2] = std::max(states[2], states[1]-x);
			states[3] = std::max(states[3], states[2]+x);
		}
		return states[3];//std::max(states[1],states[3]);
	}
};

