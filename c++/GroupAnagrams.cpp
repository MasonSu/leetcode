/**
 *
 * Given an array of strings, group anagrams together.
 *
 * For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Return:
 * [
 *   ["ate", "eat","tea"],
 *   ["nat","tan"],
 *   ["bat"]
 * ]
 *
 */

#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using std::vector;
using std::string;
using std::unordered_map;
using std::cout;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    if (strs.empty())
      return {};
    unordered_map<string, vector<string>> anagrams;
    for (const string& s : strs) {
      string key = s;
      std::sort(key.begin(), key.end());
      anagrams[key].push_back(s);
    }
    vector<vector<string>> result;
    for (auto iter = anagrams.begin(); iter != anagrams.end(); ++iter)
      result.push_back(iter->second);
    return result;
  }
};

int main(int argc, char const *argv[])
{
  Solution test;
  vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
  for (auto vec : test.groupAnagrams(strs)) {
    for (auto c : vec)
      cout << c << " ";
    cout << '\n';
  }
  return 0;
}