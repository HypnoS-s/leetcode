#pragma once
#include <vector>
#include <algorithm>
using std::vector;
using std::min;


/*Minimum Path Sum My Submissions Question
Total Accepted: 55350 Total Submissions: 167006 Difficulty: Medium
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Subscribe to see which companies asked this question

Hide Tags Array Dynamic Programming
Hide Similar Problems (M) Unique Paths (H) Dungeon Game
*/

class Solution {
public:
	vector<vector<int>> M;
	int m, n;
	int minPathSum(vector<vector<int>>& grid) {
		m = grid.size();
		n = m ? grid[0].size() : 0;
		M.resize(m,vector<int>(n));

		int i = 0, j = 1;
		M[0][0] = grid[0][0];
		while (true)
		{
			M[i][j] = min((j ? M[i][j - 1] : INT_MAX), (i ? M[i - 1][j] : INT_MAX)) + grid[i][j];
			if (j==0)
			{
				j = i + 1;
				i = 0;
			}
			if (i == m-1)
			{
				j=
			}

		}
		for (int k = 0; k < m+n-1; k++)
		{
			for (int i = 0,int j=k-i; i < m && j; i++)
			{
			//	j = k - i;
				if (i==0&&j==0)
				{
					M[i][j] = grid[i][j];
				}
				else
				{
					M[i][j] = min((j ? M[i][j - 1] : INT_MAX), (i ? M[i - 1][j] : INT_MAX)) + grid[i][j];
				}
			}
		}
		return M[m - 1][n - 1];
	}

};