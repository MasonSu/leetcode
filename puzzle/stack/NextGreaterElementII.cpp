// Given a circular array (the next element of the last element is the first 
// element of the array), print the Next Greater Number for every element. 
// The Next Greater Number of a number x is the first greater number to its 
// traversing-order next in the array, which means you could search circularly 
// to find its next greater number. If it doesn't exist, output -1 for this number.

// Example 1:
// Input: [1,2,1]
// Output: [2,-1,2]
// Explanation: The first 1's next greater number is 2; 
// The number 2 can't find next greater number; 
// The second 1's next greater number needs to search circularly, which is also 2.

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if (nums.empty())
            return {};
        // st存放的是数组下标
        stack<int> st;
        int length = nums.size();
        // 这里可以提前初始化结果
        vector<int> result(length, -1);
        for (int i = 0; i < nums.size(); ++i) {
            while (st.size()) {
                if (nums[i] <= nums[st.top()])
                    break;
                result[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }

        // 因为循环，再遍历一遍数组，有些条件可以提前终止
        for (int i = 0; i < nums.size(); ++i) {
            if (st.empty() || i >= st.top())
                break;
            while (st.size() && nums[i] > nums[st.top()]) {
                result[st.top()] = nums[i];
                st.pop();
            }
        }
        
        return result;
    }
};