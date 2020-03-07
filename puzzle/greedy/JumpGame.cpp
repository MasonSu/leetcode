// Given an array of non-negative integers, you are initially positioned at the first index of the array.

// Each element in the array represents your maximum jump length at that position.

// Determine if you are able to reach the last index.

// Example 1:

// Input: [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Example 2:

// Input: [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what. Its maximum
//              jump length is 0, which makes it impossible to reach the last index.

class Solution1 {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty())
            return false;
        int length = nums.size();
        vector<int> vec(length, 0);
        vec[0] = 1;
        for (int i = 0; i < length; ++i) {
            if (vec[i] == 0)
                break;
            for (int j = i + 1; j <= i + nums[i] && j < length; ++j)
                vec[j] = 1;
            if (vec[length - 1])
                return true;
        }
        return false;
    }
};

class Solution2 {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty())
            return false;
        int length = nums.size(), last = 0;
        for (int i = 0; i < length; ++i) {
            if (i > last)
                break;
            last = std::max(i + nums[i], last);
            if (last >= length - 1)
                return true;
        }
        return false;
    }
};