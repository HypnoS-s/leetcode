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

//28ms
class Solution {
public:
	vector<vector<int>> M;
	int m, n;
	int minPathSum(vector<vector<int>>& grid) {
		m = grid.size();
		n = m ? grid[0].size() : 0;
		if (!m||!n)
		{
			return 0;
		}
		M.resize(m,vector<int>(n));

		M[0][0] = grid[0][0];
		for (int j = 1; j < n; j++)
		{
			M[0][j] = M[0][j - 1] + grid[0][j];
		}
		for (int i = 1; i < m; i++)
		{
			M[i][0] = M[i - 1][0] + grid[i][0];
		}
		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				M[i][j] = min(M[i-1][j],M[i][j-1]) + grid[i][j];
			}
		}
		return M[m - 1][n - 1];
	}

};