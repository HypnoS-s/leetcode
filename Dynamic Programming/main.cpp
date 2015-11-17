#include "Climbing Stairs.h"
#include <iostream>
#include <chrono>
using std::cout;
using std::endl;

int main()
{
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	
	Solution s;
	cout << s.climbStairs(44) << endl;
	
	end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;

	cout << "time: " << elapsed_seconds.count() << "s" << endl;

	return 0;
}