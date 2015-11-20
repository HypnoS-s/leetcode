#pragma once

/*
Unique Binary Search Trees My Submissions Question
Total Accepted: 67207 Total Submissions: 186320 Difficulty: Medium
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

1         3     3      2      1
\       /     /      / \      \
3     2     1      1   3      2
/     /       \                 \
2     1         2                 3
Subscribe to see which companies asked this question

Hide Tags Tree Dynamic Programming
Hide Similar Problems (M) Unique Binary Search Trees II
*/


//0ms
class Solution {
public:
	int numTrees(int n) {
		int* M = new int[n+1] {1};
		for (int i = 0; i <= n; i++)
			for (int j = 0; j < i; j++)
				M[i] += M[j] * M[i - 1 - j];
		return M[n];
	}
};