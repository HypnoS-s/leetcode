#pragma once
#include <vector>
#include <algorithm>
using std::vector;

/*
Best Time to Buy and Sell Stock with Cooldown My Submissions Question
Total Accepted: 2084 Total Submissions: 6287 Difficulty: Medium
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]
Credits:
Special thanks to @peisi for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Hide Tags Dynamic Programming
Hide Similar Problems (M) Best Time to Buy and Sell Stock (M) Best Time to Buy and Sell Stock II
*/

//8ms

//class Solution {
//public:
//	int maxProfit(vector<int>& prices) {
//		int n = prices.size();
//		if (!n) return 0;
//		vector<int> buy(n, INT_MIN);
//		vector<int> sell(n, INT_MIN);
//		for (int i = 0; i < n; i++)
//		{
//			if (i == 0)
//			{
//				buy[i] = -prices[i];
//				sell[i] = 0;
//			}
//			else if (i == 1)
//			{
//				buy[i] = std::max(buy[i - 1], -prices[i]);
//				sell[i] = sell[i] = std::max(sell[i - 1], buy[i - 1] + prices[i]);
//			}
//			else
//			{
//				buy[i] = std::max(buy[i - 1], sell[i - 2] - prices[i]);
//				sell[i] = std::max(sell[i - 1], buy[i - 1] + prices[i]);
//			}
//		}
//		return sell.back();
//	}
//};

//4ms
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if (!n) return 0;

		int buy = INT_MIN, pre_buy = buy;
		int sell = 0, pre_sell = sell;

		for (auto& x : prices)
		{
			buy = std::max(buy, pre_sell - x);
			pre_sell = sell;
			sell = std::max(sell, buy + x);
			/*
		prev_buy = buy;
		buy = max(prev_sell - price, buy);
		prev_sell = sell;
		sell = max(prev_buy + price, sell);
			*/
		}
		return sell;
	}
};


/*
https://leetcode.com/discuss/71354/share-my-thinking-process
good explanation
*/