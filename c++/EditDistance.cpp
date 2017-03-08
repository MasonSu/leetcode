/**
 *
 * Given two words word1 and word2, find the minimum number of steps
 * required to convert word1 to word2. (each operation is counted as 1 step.)
 *
 * You have the following 3 operations permitted on a word:
 *
 * a) Insert a character
 * b) Delete a character
 * c) Replace a character
 *
 */

/* Failed */
#include <string>
#include <algorithm>

using std::string;

class Solution {
public:
  int minDistance(string word1, string word2) {
    if (word1.empty())
      return word2.size();
    if (word2.empty())
      return word1.size();
    int length1 = word1.size(), length2 = word2.size();
    int arr[length1 + 1][length2 + 1];
    for (int i = 0; i <= length1; ++i)
      arr[i][0] = i;
    for (int j = 0; j <= length2; ++j)
      arr[0][j] = j;
    for (int i = 1; i <= length1; ++i) {
      for (int j = 1; j <= length2; ++j) {
        if (word1[i - 1] == word2[j - 1])
          arr[i][j] = arr[i - 1][j - 1];
        else
          arr[i][j] = std::min(arr[i - 1][j - 1], std::min(arr[i][j - 1], arr[i - 1][j])) + 1;
      }
    }
    return arr[length1][length2];
  }
};