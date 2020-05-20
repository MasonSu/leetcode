// Given two non-negative integers num1 and num2 represented as 
// string, return the sum of num1 and num2.

// Note:

// The length of both num1 and num2 is < 5100.
// Both num1 and num2 contains only digits 0-9.
// Both num1 and num2 does not contain any leading zero.
// You must not use any built-in BigInteger library or convert 
// the inputs to integer directly.

class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1.empty() || num2.empty())
            return num1.empty() ? num2 : num1;
        int length1 = num1.size(), length2 = num2.size();
        string result(std::max(length1, length2) + 1, '0');
        int count = 0;
        for (int i = length1 - 1, j = length2 - 1; i >= 0 || j >= 0; --i, --j) {
            if (i >= 0) {
                count += num1[i] - '0';
            }
            if (j >= 0) {
                count += num2[j] - '0';
            }
            result[std::max(i, j) + 1] = '0' + count % 10;
            count /= 10;
        }
        if (count == 1) {
            result[0] = '1';
            return result;
        }
        return result.substr(1);
    }
};