#pragma once
#include <vector>
using std::vector;

/*
Unique Binary Search Trees II My Submissions Question
Total Accepted: 44140 Total Submissions: 151980 Difficulty: Medium
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

1         3     3      2      1
\       /     /      / \      \
3     2     1      1   3      2
/     /       \                 \
2     1         2                 3
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

Subscribe to see which companies asked this question

Hide Tags Tree Dynamic Programming
Hide Similar Problems (M) Unique Binary Search Trees (M) Different Ways to Add Parentheses
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//32ms
class Solution {
public:
	vector<TreeNode*> generateTrees(int n) {
		return n ? subTree(1, n) : vector<TreeNode*>();
	}

	vector<TreeNode*> subTree(int i, int j) {
		vector<TreeNode*> Tree;
		if (i == j)
			Tree.push_back(new TreeNode(i));
		else if (i>j)
			Tree.push_back(NULL);
		else
		{
			for (int k = i; k <= j; k++)
			{
				auto left = subTree(i, k - 1);
				auto right = subTree(k + 1, j);
				for (auto l : left)
					for (auto r : right)
					{
						auto root = new TreeNode(k);
						root->left = l;
						root->right = r;
						Tree.push_back(root);
					}
			}
		}
		return Tree;
	}
};


//24ms
class Solution {
public:
	vector<TreeNode*> generateTrees(int n) {
		return n ? subTree(1, n) : vector<TreeNode*>();
	}

	vector<TreeNode*> subTree(int i, int j) {
		vector<TreeNode*> Tree;
		if (i == j)
			Tree.push_back(new TreeNode(i));
		else if (i>j)
			Tree.push_back(NULL);
		else
		{
			for (int k = i; k <= j; k++)
			{
				auto left = subTree(i, k - 1);
				auto right = subTree(k + 1, j);
				for (auto &l : left)			//& 30ms => 24ms
					for (auto &r : right)		//&
					{
						auto root = new TreeNode(k);
						root->left = l;
						root->right = r;
						Tree.push_back(root);
					}
			}
		}
		return Tree;
	}

};