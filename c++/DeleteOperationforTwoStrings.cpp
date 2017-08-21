/** 
 * Given two words word1 and word2, find the minimum 
 * number of steps required to make word1 and word2 
 * the same, where in each step you can delete one 
 * character in either string.
 *
 * Example 1:
 *
 * Input: "sea", "eat"
 * Output: 2
 * Explanation: You need one step to make "sea" to "ea" 
 * and another step to make "eat" to "ea".
 * 
 * Note:
 * The length of given words won't exceed 500.
 * Characters in given words can only be lower-case letters.
 */

/* Failed */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

class Solution {
public:
  int minDistance(string word1, string word2) {
    int length = longestCommonSubsequence(word1, word2);

    return word1.length() + word2.length() - 2 * length;
  }

private:
  int longestCommonSubsequence(const string& word1, const string& word2) {
    int m = word1.length(), n = word2.length();
    vector<vector<int>> vec(m + 1, vector<int>(n + 1));

    for (int i = 1; i < m + 1; ++i) {
      for (int j = 1; j < n + 1; ++j) {
        if (word1[i - 1] == word2[j - 1])
          vec[i][j] = vec[i - 1][j - 1] + 1;
        else
          vec[i][j] = std::max(vec[i - 1][j], vec[i][j - 1]); 
      }
    }

    return vec[m][n];
  }
};