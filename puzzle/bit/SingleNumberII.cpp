// Given a non-empty array of integers, every element appears three 
// times except for one, which appears exactly once. Find that single one.

// Note:

// Your algorithm should have a linear runtime complexity. Could you 
// implement it without using extra memory?

// Example 1:

// Input: [2,2,3,2]
// Output: 3
// Example 2:

// Input: [0,1,0,1,0,1,99]
// Output: 99

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0, common = 0;
        for (int num : nums) {
        	// 两次的数出现在two
            two = two | (one & num);
            // 奇数次的数出现在one
            one = one ^ num;
            // 三次的数出现在common
            common = one & two;
            one = one & (~common);
            two = two & (~common);
        }
        return one;
    }
};

class Solution2 {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int result = 0;
        for (int i = 0; i < 32; ++i) {
            int sum = 0;
            for (int j = 0; j < nums.size(); ++j) {
                sum += (nums[j] >> i & 1);
                sum %= 3;
            }
            result |= (sum << i);
        }
        return result;
    }
};