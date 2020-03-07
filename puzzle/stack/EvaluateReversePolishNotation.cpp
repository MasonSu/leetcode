// Evaluate the value of an arithmetic expression in Reverse 
// Polish Notation.

// Valid operators are +, -, *, /. Each operand may be an
// integer or another expression.

// Note:

// Division between two integers should truncate toward zero.
// The given RPN expression is always valid. That means the expression would always 
// evaluate to a result and there won't be any divide by zero operation.
// Example 1:

// Input: ["2", "1", "+", "3", "*"]
// Output: 9
// Explanation: ((2 + 1) * 3) = 9
// Example 2:

// Input: ["4", "13", "5", "/", "+"]
// Output: 6
// Explanation: (4 + (13 / 5)) = 6

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.empty())
            return 0;
        stack<int> st;
        for (string& s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                if (s == "+") {
                    st.push(num1 + num2);
                } else if (s == "-") {
                    st.push(num2 - num1);
                } else if (s == "*") {
                    st.push(num1 * num2);
                } else if (s == "/") {
                    st.push(num2 / num1);
                }
            } else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};