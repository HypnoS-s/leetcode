#pragma once
#include <string>

using std::string;

/*
Decode Ways My Submissions Question
Total Accepted: 54356 Total Submissions: 325996 Difficulty: Medium
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.

Subscribe to see which companies asked this question

Hide Tags Dynamic Programming String
*/

//4ms
class Solution {
public:

	int numDecodings(string s) {
		int n = s.size();
		if (n == 0) return 0;
		
		int twoBefore = 1;
		int oneBefore = isNum(s[0]);
		
		//if (n == 1) return twoBefore;
		//if (n == 2) return oneBefore;
		int curr=oneBefore;
		for (int i = 1; i < n; i++)
		{
			curr = isNum(s[i])*oneBefore + isNum(s[i - 1], s[i])*twoBefore;
			twoBefore = oneBefore;
			oneBefore = curr;
		}
		return curr;
	}
private:
	int isNum(char c)
	{
		return c == '0' ? 0 : 1;
	}
	int isNum(char a, char b)
	{
		if (a == '0' || (((a - '0') * 10 + (b - '0')) > 26))
			return 0;
		else
			return 1;
	}
};