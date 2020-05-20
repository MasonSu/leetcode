// Given two strings text1 and text2, return the length of their longest common subsequence.

// A subsequence of a string is a new string generated from the original string with some 
// characters(can be none) deleted without changing the relative order of the remaining 
// characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). A common subsequence 
// of two strings is a subsequence that is common to both strings. 

// If there is no common subsequence, return 0.

// Example 1:

// Input: text1 = "abcde", text2 = "ace" 
// Output: 3  
// Explanation: The longest common subsequence is "ace" and its length is 3.
// Example 2:

// Input: text1 = "abc", text2 = "abc"
// Output: 3
// Explanation: The longest common subsequence is "abc" and its length is 3.
// Example 3:

// Input: text1 = "abc", text2 = "def"
// Output: 0
// Explanation: There is no such common subsequence, so the result is 0.
//  

// Constraints:

// 1 <= text1.length <= 1000
// 1 <= text2.length <= 1000
// The input strings consist of lowercase English characters only.

class Solution {
public:
   string longestCommonSeqence(string& s1, string& s2) {
       if (s1.empty() || s2.empty())
           return "";
       int lengthX = s1.size(), lengthY = s2.size();
       vector<vector<int>> vec(lengthX + 1, vector<int>(lengthY + 1));
       for (int i = 1; i <= lengthX; ++i) {
           for (int j = 1; j <= lengthY; ++j) {
               if (s1[i - 1] == s2[j - 1])
                   vec[i][j] = vec[i - 1][j - 1] + 1;
               else
                   vec[i][j] = std::max(vec[i - 1][j], vec[i][j - 1]);
           }
       }
       int pos = vec[lengthX][lengthY];
       string result;
       result.resize(pos);
       for (int i = lengthX - 1, j = lengthY - 1; i >= 0 && j >= 0;) {
           if (s1[i] == s2[j]) {
               result[--pos] = s1[i];
               i--;
               j--;
           } else {
               if (vec[i + 1][j + 1] == vec[i][j + 1])
                   i--;
               else if (vec[i + 1][j + 1] == vec[i + 1][j])
                   j--;
           }
       }
       return result;
   }
};