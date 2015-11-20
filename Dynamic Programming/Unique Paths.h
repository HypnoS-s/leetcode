#pragma once
#include <vector>
using std::vector;
/*
Unique Paths My Submissions Question
Total Accepted: 67496 Total Submissions: 197262 Difficulty: Medium
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

Subscribe to see which companies asked this question

Hide Tags Array Dynamic Programming
Hide Similar Problems (M) Unique Paths II (M) Minimum Path Sum (H) Dungeon Game
*/

//0ms
//class Solution {
//public:
//	vector<vector<int>> M;
//	int uniquePaths(int m, int n) {
//		if (!m || !n) return 0;
//		M.resize(m, vector<int>(n));
//		M[0][0] = 1;
//		for (int j = 1; j < n; j++)
//		{
//			M[0][j] = M[0][j - 1];
//		}
//		for (int i = 1; i < m; i++)
//		{
//			M[i][0] = M[i - 1][0];
//		}
//		for (int i = 1; i < m; i++)
//		{
//			for (int j = 1; j < n; j++)
//			{
//				M[i][j] = M[i - 1][j] + M[i][j - 1];
//			}
//		}
//		return M[m - 1][n - 1];
//	}
//};



//0ms
class Solution {
public:
	int uniquePaths(int m, int n) {
		if (!m || !n) return 0;
		vector<vector<int>> M(m, vector<int>(n, 1));
		for (int i = 1; i < m; i++)
			for (int j = 1; j < n; j++)
				M[i][j] = M[i - 1][j] + M[i][j - 1];
		return M[m - 1][n - 1];
	}
};