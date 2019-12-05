// Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks. Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

// However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

// You need to return the least number of intervals the CPU will take to finish all the given tasks.

//  

// Example:

// Input: tasks = ["A","A","A","B","B","B"], n = 2
// Output: 8
// Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
//  

// Note:

// The number of tasks is in the range [1, 10000].
// The integer n is in the range [0, 100].

#include <bits/stdc++.h>

using namespace std;

#include "catch.hpp"

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (tasks.empty())
            return 0;
        unordered_map<char, int> table;
        for (char c : tasks)
            table[c]++;
        priority_queue<int> pg;
        for (auto iter = table.begin(); iter != table.end(); ++iter)
            pg.push(iter->second);
        int count = 0;
        while (pg.size()) {
            vector<int> vec;
            /* 间隔为n，需要执行n+1个任务 */
            for (int i = 0; i < n + 1; ++i) {
                if (pg.empty()) {
                    /* 没有下一个执行周期 */
                    if (vec.empty())
                        break;
                    count++;
                } else {
                    int num = pg.top();
                    pg.pop();
                    count++;
                    if (--num)
                        vec.push_back(num);
                }
            }
            for (int i : vec)
                pg.push(i);
        }
        return count;
    }
};

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    Solution test;
    vector<char> v1{'A','A','A','B','B','B'};
    REQUIRE(test.leastInterval(v1, 2) == 8);
}
