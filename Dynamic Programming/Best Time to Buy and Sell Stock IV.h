#pragma once
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using std::vector;
using std::priority_queue;
using std::stack;
using std::pair;
/*
Best Time to Buy and Sell Stock IV My Submissions Question
Total Accepted: 18250 Total Submissions: 90104 Difficulty: Hard
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Hide Tags Dynamic Programming
Hide Similar Problems (M) Best Time to Buy and Sell Stock (M) Best Time to Buy and Sell Stock II (H) Best Time to Buy and Sell Stock III
*/



////8ms
//class Solution {
//public:
//	int maxProfit(int k, vector<int>& prices) {
//		if (!k) return 0;
//		if (k >= prices.size() / 2)
//		{
//			int sum = 0, n = prices.size();
//			for (int i = 0; i<n - 1; i++)
//				if (prices[i + 1]>prices[i])
//					sum += prices[i + 1] - prices[i];
//			return sum;
//		}
//		vector<int> buy(k, INT_MIN);
//		vector<int> sell(k, 0);
//
//		for (auto& x : prices)
//			for (int i = 0; i < k; i++)
//			{
//				buy[i] = std::max(buy[i], i ? sell[i - 1] - x : -x);
//				sell[i] = std::max(sell[i], buy[i] + x);
//			}
//		return sell.back();
//	}
//};

//12ms,from discuss
class Solution {
public:
	int maxProfit(int k, vector<int> &prices) {
		int n = (int)prices.size(), ret = 0, v, p = 0;
		priority_queue<int> profits;
		stack<pair<int, int> > vp_pairs;
		while (p < n) {
			// find next valley/peak pair
			for (v = p; v < n - 1 && prices[v] >= prices[v + 1]; v++);
			for (p = v + 1; p < n && prices[p] >= prices[p - 1]; p++);
			// save profit of 1 transaction at last v/p pair, if current v is lower than last v
			while (!vp_pairs.empty() && prices[v] < prices[vp_pairs.top().first]) {
				profits.push(prices[vp_pairs.top().second - 1] - prices[vp_pairs.top().first]);
				vp_pairs.pop();
			}
			// save profit difference between 1 transaction (last v and current p) and 2 transactions (last v/p + current v/p),
			// if current v is higher than last v and current p is higher than last p
			while (!vp_pairs.empty() && prices[p - 1] >= prices[vp_pairs.top().second - 1]) {
				profits.push(prices[vp_pairs.top().second - 1] - prices[v]);
				v = vp_pairs.top().first;
				vp_pairs.pop();
			}
			vp_pairs.push(pair<int, int>(v, p));
		}
		// save profits of the rest v/p pairs
		while (!vp_pairs.empty()) {
			profits.push(prices[vp_pairs.top().second - 1] - prices[vp_pairs.top().first]);
			vp_pairs.pop();
		}
		// sum up first k highest profits
		for (int i = 0; i < k && !profits.empty(); i++) {
			ret += profits.top();
			profits.pop();
		}
		return ret;
	}
};