// Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

// If possible, output any possible result.  If not possible, return the empty string.

// Example 1:

// Input: S = "aab"
// Output: "aba"
// Example 2:

// Input: S = "aaab"
// Output: ""
// Note:

// S will consist of lowercase letters and have length in range [1, 500].

#include <bits/stdc++.h>

using namespace std;

#include "catch.hpp"

/* 检查字符串能否经过重新排列使得相邻的字符不一样，
 * 如果能，返回任意满足条件的字符串，如果不能，
 * 返回空串
 */
class Solution {
public:
    string reorganizeString(string S) {
        if (S.empty())
            return "";
        unordered_map<char, int> table;
        for (char c : S)
            table[c]++;
        /* 默认对pair的first进行增序排列，对于能不能构成
         * 的判断，也需要借助堆，不能通过简单的排序来判断，
         * 参考最后一个测试用例
         */
        priority_queue<pair<int, char>> pg;
        for (auto iter = table.begin(); iter != table.end(); ++iter)
            pg.push({iter->second, iter->first});
        string result;
        pair<int, char> prev{-1, '#'}, current;
        /* 每次打印一个数之后，都将它的次数减一并弹出，
         * 检查它的前一个数，如果次数大于0的话，将前一
         * 个数插入堆中，否则选取下一个元素，以此来交
         * 错插入字符
         */
        while (pg.size()) {
            current = pg.top();
            pg.pop();
            result += current.second;
            current.first--;
            if (prev.first > 0)
                pg.push(prev);
            prev = current;
        }
        return result.size() == S.size() ? result : "";
    }
};

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    Solution test;
    REQUIRE(test.reorganizeString("aab") == "aba");
    REQUIRE(test.reorganizeString("aaab") == "");
    REQUIRE(test.reorganizeString("aaaaabbbbccccd") == "acbacbacbadcba");
}
