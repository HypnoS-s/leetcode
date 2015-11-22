#include "Unique Binary Search Trees II.h"
#include <iostream>
#include <chrono>
using std::cout;
using std::endl;

int main()
{
	//vector<vector<int>> v = {
	//	//{1,2,3,4,5},
	//	//{2,2,1,5,6},
	//	//{1,2,3,4,1}
	//};
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();

	Solution s;
	s.generateTrees(3);


	end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;

	cout << "time: " << elapsed_seconds.count() << "s" << endl;

	return 0;
}