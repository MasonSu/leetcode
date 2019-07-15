class Solution {
public:
   string longestCommonString(string& s1, string& s2) {
       if (s1.empty() || s2.empty())
           return "";
       int lengthX = s1.size(), lengthY = s2.size();
       vector<vector<int>> vec(lengthX + 1, vector<int>(lengthY + 1));
       int length = 0, pos = 0;
       for (int i = 1; i <= lengthX; ++i) {
           for (int j = 1; j <= lengthY; ++j) {
               if (s1[i - 1] == s2[j - 1]) {
                   vec[i][j] = vec[i - 1][j - 1] + 1;
                   if (vec[i][j] > length) {
                       length = vec[i][j];
                       pos = i;
                   }
               }
           }
       }
       return s1.substr(pos - length, length);
   }
};