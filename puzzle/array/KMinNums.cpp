/* 找到无序数组中最小的k个数 */
#include <bits/stdc++.h>

using namespace std;

#include "catch.hpp"

class Solution {
public:
   vector<int> getKMinNums(vector<int>& vec, int k) {
       if (vec.empty())
           return {};
       vector<int> result;
       priority_queue<int> maxHeap;
       for (size_t i = 0; i < vec.size(); ++i) {
          maxHeap.push(vec[i]);
          if (maxHeap.size() == k + 1)
              maxHeap.pop();
       }
       while (maxHeap.size()) {
           result.push_back(maxHeap.top());
           maxHeap.pop();
       }
       return result;
   }
};

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    Solution test;
    vector<int> v1{3,2,5,1,4};
    REQUIRE(test.getKMinNums(v1, 3) == vector<int>{3,2,1});
    vector<int> v2{8,2,5,1,6,4};
    REQUIRE(test.getKMinNums(v2, 3) == vector<int>{4,2,1});
    vector<int> v3{8,3,5,6,2};
    REQUIRE(test.getKMinNums(v3, 3) == vector<int>{5,3,2});
}
