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