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
