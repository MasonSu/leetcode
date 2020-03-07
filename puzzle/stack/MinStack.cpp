// Design a stack that supports push, pop, top, and retrieving 
// the minimum element in constant time.

// push(x) -- Push element x onto stack.
// pop() -- Removes the element on top of the stack.
// top() -- Get the top element.
// getMin() -- Retrieve the minimum element in the stack.

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        st1.push(x);
        if (st2.empty() || x <= st2.top())
            st2.push(x);
    }
    
    void pop() {
        if (st1.top() == st2.top())
            st2.pop();
        st1.pop();
    }
    
    int top() {
        return st1.top();
    }
    
    int getMin() {
        return st2.top();
    }
    
private:
    stack<int> st1, st2;
};