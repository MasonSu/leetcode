// Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

// Strings consists of lowercase English letters only and the length of both strings s and p 
// will not be larger than 20,100.

// The order of output does not matter.

// Example 1:

// Input:
// s: "cbaebabacd" p: "abc"

// Output:
// [0, 6]

// Explanation:
// The substring with start index = 0 is "cba", which is an anagram of "abc".
// The substring with start index = 6 is "bac", which is an anagram of "abc".
// Example 2:

// Input:
// s: "abab" p: "ab"

// Output:
// [0, 1, 2]

// Explanation:
// The substring with start index = 0 is "ab", which is an anagram of "ab".
// The substring with start index = 1 is "ba", which is an anagram of "ab".
// The substring with start index = 2 is "ab", which is an anagram of "ab".

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size())
            return {};
        int count = 0;
        unordered_map<char, int> um;
        for (auto c : p) {
            um[c]++;
            count++;
        }
        
        vector<int> result;
        int start = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (um[s[i]]-- > 0) {
                count--;
            }
            while (count == 0) {
                if (i - start + 1 == p.size())
                    result.push_back(start);
                
                if (++um[s[start]] > 0)
                    count++;
                start++;
            }
        }
        return result;
    }
};