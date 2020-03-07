// Given an input string, reverse the string word by word.

// Example 1:
// Input: "the sky is blue"
// Output: "blue is sky the"

// Example 2:
// Input: "  hello world!  "
// Output: "world! hello"
// Explanation: Your reversed string should not contain leading or trailing spaces.

// Example 3:
// Input: "a good   example"
// Output: "example good a"
// Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

// 分3步，有很多边界条件需要考虑
class Solution {
public:
    string reverseWords(string s) {
        if (s.empty())
            return s;
        int length = s.size();
        // 反转整个字符串
        reverse(s, 0, length - 1);
     	
     	// 反转每个word
        int start = 0;
        for (int i = 0; i < length; ++i) {
            if (s[i] != ' ') {
                if (i == 0 || (i > 0 && s[i - 1] == ' '))
                    start = i;
            } else {
                if (i > 0 && s[i - 1] != ' ')
                    reverse(s, start, i - 1);
            }
        }
        if (s[length - 1] != ' ')
            reverse(s, start, length - 1);

        // 消除多余的空格
        int index = 0;
        for (int i = 0; i < length; ++i) {
            if (s[i] == ' ') {
                if (i == 0 || (i > 0 && s[i - 1] == ' '))
                    continue;
                s[index++] = s[i];
            } else {
                s[index++] = s[i];
            }
        }
        if (s[index - 1] == ' ')
            index--;
        return s.substr(0, index);
    }
    
private:
    void reverse(string &s, int begin, int end) {
        while (begin < end) {
            std::swap(s[begin], s[end]);
            begin++;
            end--;
        }
    }
};