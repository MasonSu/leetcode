#define CATCH_CONFIG_MAIN
#include <bits/stdc++.h>

using namespace std;

#include "catch.hpp"

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *construct(vector<int> &nums) {
    ListNode *pre = new ListNode(0);
    ListNode *head = pre;
    for (int i = 0; i < nums.size(); ++i) {
        head->next = new ListNode(nums[i]);
        head = head->next;
    }
    return pre->next;
}

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (n <= 1)
            return 1;
        int length = primes.size();
        vector<int> result(length), index(length);
        result[0] = 1;
        for (int i = 1; i < n; ++i) {
            int min = INT_MAX;
            for (int j = 0; j < length; ++j) {
                min = std::min(min, primes[j] * result[index[j]]);
            }
            result[i] = min;
            for (int j = 0; j < length; ++j) {
                if (primes[j] * result[index[j]] == result[i])
                    index[j]++;
            }
        }
        return result[n - 1];
    }
};

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    Solution test;
    vector<int> vec{2,7,13,19};
    REQUIRE(test.nthSuperUglyNumber(3, vec) == 4);
}