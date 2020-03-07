// Given a list of daily temperatures T, return a list such that, 
// for each day in the input, tells you how many days you would 
// have to wait until a warmer temperature. If there is no future 
// day for which this is possible, put 0 instead.

// For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], 
// your output should be [1, 1, 4, 2, 1, 1, 0, 0].

// 构造递减队列
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        if (T.empty())
            return {};
        int length = T.size();
        vector<int> result(length, 0);
        stack<int> st;
        for (int i = 0; i < length; ++i) {
            while (st.size() && T[i] > T[st.top()]) {
                result[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
};