// Given two binary strings, return their sum (also a binary string).

// The input strings are both non-empty and contains only characters 1 or 0.

// Example 1:

// Input: a = "11", b = "1"
// Output: "100"
// Example 2:

// Input: a = "1010", b = "1011"
// Output: "10101"

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.empty() || b.empty())
            return a.empty() ? b : a;
        int lengthA = a.size(), lengthB = b.size();
        int num = 0;
        string result(std::max(lengthA, lengthB) + 1, '0');
        for (int i = lengthA - 1, j = lengthB - 1; i >= 0 || j >= 0; --i, --j) {
            if (i >= 0)
                num += (a[i] - '0');
            if (j >= 0)
                num += (b[j] - '0');
            result[std::max(i, j) + 1] = '0' + num % 2;
            num /= 2;
        }
        if (num == 1) {
            result[0] = '1';
            return result;
        } else {
            return result.substr(1);
        }
    }
};