#pragma once
#include <unordered_map>
#include <algorithm>
#include <vector>;
/*
Perfect Squares  
Total Accepted: 16644 Total Submissions: 56576 Difficulty: Medium
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Hide Tags Dynamic Programming Breadth-first Search Math
Hide Similar Problems (E) Count Primes (M) Ugly Number II
*/
////time limit
//class Solution {
//public:
//	std::unordered_map<int,int> M;
//	int numSquares(int n) {
//		if (M.find(n)==M.end())
//		{
//			int i = 1;
//			while (true)
//			{
//				if (n== i*i)
//				{
//					M[n] = 1;
//					break;
//				}
//				else if (n < i*i)
//				{
//					M[n] = 1 + numSquares(n - (i-1)*(i-1));
//					for (int  j = i-2; j > 0; j--)
//						M[n] = std::min(M[n], 1 + numSquares(n - j*j));
//					break;
//				}
//				++i;
//			}
//		}
//		return M[n];
//	}
//};

////444 ms  dynamic programming
//class Solution
//{
//public:
//	int numSquares(int n)
//	{
//		std::vector<int> M(n + 1, INT_MAX);
//		M[0] = 0;
//		for (int i = 1; i <= n; i++)
//			for (int j = 1; j*j <= i; j++)
//				M[i] = std::min(M[i], M[i - j*j] + 1);
//		return M[n];
//	}
//};


////12 ms  dynamic programming,with static vector
//class Solution
//{
//public:
//	int numSquares(int n)
//	{
//		static std::vector<int> M({ 0 });
//		while (n >= M.size())
//		{
//			int m = M.size();
//			int x = INT_MAX;
//			for (int i = 1; i*i <= m; i++)
//				x = std::min(x, M[m - i*i] + 1);
//			M.push_back(x);
//		}
//		return M[n];
//	}
//};


/*
The magic 4^k(8m+7) can be derived from Lagrange's Four Square theorem and Legendre's three-square theorem.
Based on Lagrange's Four Square theorem, there are only 4 possible results: 1, 2, 3, 4.
Based on Legendre's three-square theorem, if n can be written as 4^k(8m+7), it can't be represented as the sum of 1 or 2 or 3 integers.
*/
//4ms ,Lagrange's Four Square theorem
class Solution
{
private:
	int is_square(int n)
	{
		int sqrt_n = (int)(sqrt(n));
		return (sqrt_n*sqrt_n == n);
	}

public:
	// Based on Lagrange's Four Square theorem, there 
	// are only 4 possible results: 1, 2, 3, 4.
	int numSquares(int n)
	{
		// If n is a perfect square, return 1.
		if (is_square(n))
		{
			return 1;
		}

		// The result is 4 if n can be written in the 
		// form of 4^k*(8*m + 7). Please refer to 
		// Legendre's three-square theorem.
		while ((n & 3) == 0) // n%4 == 0  
		{
			n >>= 2;
		}
		if ((n & 7) == 7) // n%8 == 7
		{
			return 4;
		}

		// Check whether 2 is the result.
		int sqrt_n = (int)(sqrt(n));
		for (int i = 1; i <= sqrt_n; i++)
		{
			if (is_square(n - i*i))
			{
				return 2;
			}
		}

		return 3;
	}
};

//Breadth-First Search: 80ms
class Solution
{
public:
	int numSquares(int n)
	{
		if (n <= 0)
		{
			return 0;
		}

		// perfectSquares contain all perfect square numbers which 
		// are smaller than or equal to n.
		std::vector<int> perfectSquares;
		// cntPerfectSquares[i - 1] = the least number of perfect 
		// square numbers which sum to i.
		std::vector<int> cntPerfectSquares(n);

		// Get all the perfect square numbers which are smaller than 
		// or equal to n.
		for (int i = 1; i*i <= n; i++)
		{
			perfectSquares.push_back(i*i);
			cntPerfectSquares[i*i - 1] = 1;
		}

		// If n is a perfect square number, return 1 immediately.
		if (perfectSquares.back() == n)
		{
			return 1;
		}

		// Consider a graph which consists of number 0, 1,...,n as
		// its nodes. Node j is connected to node i via an edge if  
		// and only if either j = i + (a perfect square number) or 
		// i = j + (a perfect square number). Starting from node 0, 
		// do the breadth-first search. If we reach node n at step 
		// m, then the least number of perfect square numbers which 
		// sum to n is m. Here since we have already obtained the 
		// perfect square numbers, we have actually finished the 
		// search at step 1.
		queue<int> searchQ;
		for (auto& i : perfectSquares)
		{
			searchQ.push(i);
		}

		int currCntPerfectSquares = 1;
		while (!searchQ.empty())
		{
			currCntPerfectSquares++;

			int searchQSize = searchQ.size();
			for (int i = 0; i < searchQSize; i++)
			{
				int tmp = searchQ.front();
				// Check the neighbors of node tmp which are the sum 
				// of tmp and a perfect square number.
				for (auto& j : perfectSquares)
				{
					if (tmp + j == n)
					{
						// We have reached node n.
						return currCntPerfectSquares;
					}
					else if ((tmp + j < n) && (cntPerfectSquares[tmp + j - 1] == 0))
					{
						// If cntPerfectSquares[tmp + j - 1] > 0, this is not 
						// the first time that we visit this node and we should 
						// skip the node (tmp + j).
						cntPerfectSquares[tmp + j - 1] = currCntPerfectSquares;
						searchQ.push(tmp + j);
					}
					else if (tmp + j > n)
					{
						// We don't need to consider the nodes which are greater ]
						// than n.
						break;
					}
				}

				searchQ.pop();
			}
		}

		return 0;
	}
};