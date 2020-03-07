// Given a non-empty array containing only positive integers, find if the array 
// can be partitioned into two subsets such that the sum of elements in both 
// subsets is equal.

// Note:

// Each of the array element will not exceed 100.
// The array size will not exceed 200.
//  

// Example 1:

// Input: [1, 5, 11, 5]

// Output: true

// Explanation: The array can be partitioned as [1, 5, 5] and [11].
//  

// Example 2:

// Input: [1, 2, 3, 5]

// Output: false

// Explanation: The array cannot be partitioned into equal sum subsets.

/* 0-1 Knapsack */
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.empty())
            return false;
        int sum = 0;
        for (int i : nums)
            sum += i;
        if (sum & 1)
            return false;
        int target = sum / 2;
        int lengthX = nums.size(), lengthY = target;
        vector<vector<int>> vec(lengthX + 1, vector<int>(lengthY + 1));
        /* 当target为0时，将这一列全都置为1 */
        for (int i = 0; i <= lengthX; ++i)
            vec[i][0] = 1;
        for (int i = 1; i <= lengthX; ++i) {
            for (int j = 1; j <= lengthY; ++j) {
                if (nums[i - 1] <= j)
                    vec[i][j] = vec[i - 1][j] || vec[i - 1][j - nums[i - 1]];
                else
                    vec[i][j] = vec[i - 1][j];
            }
        }
        return vec[lengthX][lengthY] == 1;
    }
};