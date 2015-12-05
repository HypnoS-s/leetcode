#pragma once

/*
Ugly Number My Submissions Question
Total Accepted: 30875 Total Submissions: 89400 Difficulty: Easy
Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

Note that 1 is typically treated as an ugly number.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Hide Tags Math
Hide Similar Problems (E) Happy Number (E) Count Primes (M) Ugly Number II
*/


//8ms
class Solution {
public:
	bool isUgly(int num) {
		if (num <= 0) return false;
		while (num % 2 == 0) num /= 2;
		while (num % 3 == 0) num /= 3;
		while (num % 5 == 0) num /= 5;
		return num == 1;
	}
};

//8ms
class Solution {
public:
    int primes[3] = {2,3,5};


    bool isUgly(int num) {
        if(num==0) return false;
        if(num==1) return true;
        for(auto &p:primes)
        {
            if(num%p==0)
                return isUgly(num/p);
        }
        return false;
    }
};
