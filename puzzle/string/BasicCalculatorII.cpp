// Implement a basic calculator to evaluate a simple expression string.

// The expression string contains only non-negative integers, +, -, *, / operators 
// and empty spaces . The integer division should truncate toward zero.

// Example 1:

// Input: "3+2*2"
// Output: 7
// Example 2:

// Input: " 3/2 "
// Output: 1
// Example 3:

// Input: " 3+5 / 2 "
// Output: 5
// Note:

// You may assume that the given expression is always valid.
// Do not use the eval built-in library function.

class Solution {
public:
    int calculate(string s) {
        if (s.empty())
            return 0;
        char oper = '+';
        int num = 0;
        stack<int> st;
        for (int i = 0; i < s.size(); ++i) {
            if (std::isdigit(s[i])) {
                num = num * 10 + s[i] - '0';
            }
            
            if (i == s.size() - 1 || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                switch (oper) {
                    case '+': {
                        st.push(num);
                        break;
                    }    
                    case '-': {
                        st.push(-num);
                        break;
                    }  
                    case '*': {
                        int n = st.top();
                        st.pop();
                        st.push(n * num);
                        break;
                    }
                    case '/': {
                        int n = st.top();
                        st.pop();
                        st.push(n / num);
                        break;
                    }
                }
                oper = s[i];
                num = 0;
            }
        }
        
        int result = 0;
        while (st.size()) {
            result += st.top();
            st.pop();
        }
        return result;
    }
};