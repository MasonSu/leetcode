// Given a non-negative integer num represented as a string, remove k digits 
// from the number so that the new number is the smallest possible.

// Note:
// The length of num is less than 10002 and will be ≥ k.
// The given num does not contain any leading zero.
// Example 1:

// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 
// 1219 which is the smallest.
// Example 2:

// Input: num = "10200", k = 1
// Output: "200"
// Explanation: Remove the leading 1 and the number is 200. Note that the 
// output must not contain leading zeroes.
// Example 3:

// Input: num = "10", k = 2
// Output: "0"
// Explanation: Remove all the digits from the number and it is left with 
// nothing which is 0.

class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.size() == k)
            return "0";
        deque<char> q;
        for (char c : num) {
        	// 如果队列中的最后一个元素比c大，则弹出
            while (!q.empty() && q.back() > c && k > 0) {
                q.pop_back();
                k--;
            }
            q.push_back(c);
        }
        
        // "11111"或"12345"
        while (k > 0) {
            q.pop_back();
            k--;
        }
        
        // 去除前置0
        string result;
        while (q.size()) {
        	if (result.empty() && q.front() == '0') {
        		q.pop_front();
        		continue;
        	}
        	result += q.front();
            q.pop_front();
        }

        return result.empty() ? "0" : result;
    }
};