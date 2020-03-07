// Given n, how many structurally unique BST's 
// (binary search trees) that store values 1 ... n?

// Example:

// Input: 3
// Output: 5
// Explanation:
// Given n = 3, there are a total of 5 unique BST's:

//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3

// 对于n，其他所有比它小的节点只可能出现在左上或者左下，这里需要用到数学表达式
// v[i] = (v[i - 1] * v[0]) + (v[i - 2] * v[1]) + ... + (v[0] * v[i - 1])
// O(n^2)
class Solution {
public:
    int numTrees(int n) {
        vector<int> vec(n + 1, 1);
        for (int i = 2; i <= n; ++i) {
            vec[i] = cal(vec, i - 1);
        }
        return vec[n];
    }
    
private:
    int cal(vector<int>& nums, int end) {
        int start = 0, result = 0;
        while (start < end) {
            result += 2 * nums[start] * nums[end];
            start++;
            end--;
        }
        if (start == end)
            result += nums[start] * nums[start];
        return result;
    }
};