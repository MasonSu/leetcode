// You are given an integer array nums and you have to return a new counts 
// array. The counts array has the property where counts[i] is the number 
// of smaller elements to the right of nums[i].

// Example:

// Input: [5,2,6,1]
// Output: [2,1,1,0] 
// Explanation:
// To the right of 5 there are 2 smaller elements (2 and 1).
// To the right of 2 there is only 1 smaller element (1).
// To the right of 6 there is 1 smaller element (1).
// To the right of 1 there is 0 smaller element.

// 因为这里涉及到在数组中进行插入，最坏情况为O(N^2)
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty())
            return {};
        int length = nums.size();
        vector<int> result(length), vec;
        for (int i = length - 1; i >= 0; --i) {
            if (vec.empty() || nums[i] > vec.back()) {
                result[i] = vec.size();
                vec.push_back(nums[i]);
            } else {
                int pos = binarySearch(vec, nums[i]);
                result[i] = pos;
                vec.insert(vec.begin() + pos, nums[i]);
            }
        }
        return result;
    }
    
private:
    int binarySearch(vector<int>& nums, int target) {
        int start = 0, end = nums.size();
        while (start < end) {
            int middle = start + (end - start) / 2;
            if (nums[middle] < target) {
                start = middle + 1;
            } else {
                end = middle;
            }
        }
        return end;
    }
};