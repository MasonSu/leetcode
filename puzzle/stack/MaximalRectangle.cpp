// Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

// Example:

// Input:
// [
//   ["1","0","1","0","0"],
//   ["1","0","1","1","1"],
//   ["1","1","1","1","1"],
//   ["1","0","0","1","0"]
// ]
// Output: 6

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
        int lengthX = matrix.size(), lengthY = matrix[0].size(), result = 0;
        vector<int> vec(lengthY);
        for (int i = 0; i < lengthX; ++i) {
            if (i == 0) {
                for (int j = 0; j < lengthY; ++j)
                    vec[j] = matrix[0][j] - '0';
                maxArea(vec , result);
            } else {
                for (int j = 0; j < lengthY; ++j) {
                    if (matrix[i][j] == '1')
                        vec[j]++;
                    else
                        vec[j] = 0;
                }
                maxArea(vec, result);
            }
        }
        return result;
    }
private:
    void maxArea(vector<int>& vec, int& result) {
        int length = vec.size(), num = 0, area = 0;
        stack<int> st;
        for (int i = 0; i < length;) {
            if (st.empty() || vec[i] >= vec[st.top()]) {
                st.push(i++);
            } else {
                num = st.top();
                st.pop();
                area = vec[num] * (st.empty() ? i : i - st.top() - 1);
                result = std::max(result, area);
            }
        }
        while (st.size()) {
            num = st.top();
            st.pop();
            area = vec[num] * (st.empty() ? length : length - st.top() - 1);
            result = std::max(result, area);
        }
    }
};