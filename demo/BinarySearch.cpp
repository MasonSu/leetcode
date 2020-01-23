#define CATCH_CONFIG_MAIN
#include <bits/stdc++.h>

using namespace std;

#include "catch.hpp"

class Solution {
public:
	int binarySearch(vector<int>& vec, int target) {
		int pos = bisect(vec, vec.size(), target);
		std::cout << "pos is " << pos << "\n";
		if (pos < vec.size() && vec[pos] == target)
			return pos;
		return -1;
	};

private:
	// 这里返回的位置为第一个大于等于target的position
	int bisect(vector<int>& vec, int length, int target) {
		int start = 0, end = length;
		while (start < end) {
			int middle = start + (end - start) / 2;
			if (vec[middle] < target) {
				start = middle + 1;
			} else {
				end = middle;
			}
		}
		return end;
	}
};

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    Solution test;
    vector<int> v1{1,2,3,4,5}, v2{1,1,2,3,5}, v3{1,3,4,5};
    REQUIRE(test.binarySearch(v1, 2) == 1);
    REQUIRE(test.binarySearch(v2, 1) == 0);
    REQUIRE(test.binarySearch(v3, 2) == -1);
}