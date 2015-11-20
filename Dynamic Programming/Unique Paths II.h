#pragma once
#include <vector>
using std::vector;

/*

Unique Paths II My Submissions Question
Total Accepted: 51281 Total Submissions: 180703 Difficulty: Medium
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
[0,0,0],
[0,1,0],
[0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.

Subscribe to see which companies asked this question

Hide Tags Array Dynamic Programming
Hide Similar Problems (M) Unique Paths
*/

//4ms
class Solution {
public:
	vector<vector<int>> M;
	int m, n;
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		m = obstacleGrid.size();
		n = m ? obstacleGrid[0].size() : 0;
		if (!m || !n) return 0;

		M.resize(m, vector<int>(n));
		M[0][0] = obstacleGrid[0][0] ? 0 : 1;
		for (int j = 1; j < n; j++)
		{
			M[0][j] = obstacleGrid[0][j] ? 0 : M[0][j - 1];
		}
		for (int i = 1; i < m; i++)
		{
			M[i][0] = obstacleGrid[i][0] ? 0 : M[i - 1][0];
		}
		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				M[i][j] = obstacleGrid[i][j] ? 0 : M[i - 1][j] + M[i][j - 1];
			}
		}
		return M[m - 1][n - 1];
	}
};