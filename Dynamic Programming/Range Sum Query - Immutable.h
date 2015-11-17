#pragma once
#include <vector>
using std::vector;
/*
Range Sum Query - Immutable My Submissions Question
Total Accepted: 4873 Total Submissions: 19581 Difficulty: Easy
Given an integer array nums, find the sum of the elements between indices i and j (i ¡Ü j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.
Subscribe to see which companies asked this question

Hide Tags Dynamic Programming
Hide Similar Problems (M) Range Sum Query 2D - Immutable
*/
//time limit exceeded
//class NumArray {
//public:
//	vector<vector<int>> sums;
//	vector<vector<bool>> flags;
//	//NumArray(vector<int> &nums) {
//	//	auto n = nums.size();
//	//	for (size_t i = 0; i < n; i++)
//	//	{
//	//		sums.push_back(vector<int>(n - i));
//	//		sums[i][0] = nums[i];
//	//		flags.push_back(vector<bool>(n-i));
//	//		flags[i][0] = true;
//	//	}
//	//}
//	NumArray(vector<int> &nums) {
//		auto n = nums.size();
//		for (size_t i = 0; i < n; i++)
//		{
//			sums.push_back(vector<int>(n - i));
//			sums[i][0] = nums[i];
//			flags.push_back(vector<bool>(n - i));
//			flags[i][0] = true;
//		}
//	}
//	int sumRange(int i, int j) {
//		if (!flags[i][j-i])
//		{
//			sums[i][j-i] = sumRange(i, (i + j) / 2) + sumRange((i + j) / 2 + 1, j);
//			flags[i][j-i] = true;
//
//		}
//		return sums[i][j-i];
//	}
//};
//

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);

//588ms
class NumArray {
public:
	vector<int> sums;
	NumArray(vector<int> &nums) {
		auto x = 0;
		for (auto &num : nums)
			sums.push_back(x+=num);
	}
	int sumRange(int i, int j) {
		return i?sums[j]-sums[i-1]:sums[j];
	}
};