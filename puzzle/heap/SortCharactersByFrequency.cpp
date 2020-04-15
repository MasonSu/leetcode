// Given a string, sort it in decreasing order based on the frequency of characters.

// Example 1:

// Input:
// "tree"

// Output:
// "eert"

// Explanation:
// 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
// Example 2:

// Input:
// "cccaaa"

// Output:
// "cccaaa"

// Explanation:
// Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
// Note that "cacaca" is incorrect, as the same characters must be together.
// Example 3:

// Input:
// "Aabb"

// Output:
// "bbAa"

// Explanation:
// "bbaA" is also a valid answer, but "Aabb" is incorrect.
// Note that 'A' and 'a' are treated as two different characters.

class Solution {
public:
    string frequencySort(string s) {
        if (s.empty())
            return "";
        unordered_map<char, int> um;
        for (auto c : s)
            um[c]++;
        priority_queue<pair<int, char>> q;
        for (auto iter = um.begin(); iter != um.end(); ++iter) {
            q.push({iter->second, iter->first});
        }
        string result;
        while (q.size()) {
            auto p = q.top();
            q.pop();
            int num = p.first;
            while (num--) {
                result += p.second;
            }
        }
        return result;
    }
};