// Find the kth largest element in an unsorted array. Note that 
// it is the kth largest element in the sorted order, not the kth 
// distinct element.

// Example 1:

// Input: [3,2,1,5,6,4] and k = 2
// Output: 5
// Example 2:

// Input: [3,2,3,1,2,4,5,5,6] and k = 4
// Output: 4
// Note:
// You may assume k is always valid, 1 ≤ k ≤ array's length.

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, vector<int>, std::greater<int>> pg;
        int length = nums.size();
        for(int i = 0; i < length; ++i) {
            pg.push(nums[i]);
            if (pg.size() > k)
                pg.pop();
        }
        return pg.top();
    }
};

class Solution2 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int start = 0, end = nums.size() - 1;
        int target = nums.size() - k;
        while (start < end) {
            int pos = partion(nums, start, end);
            if (pos < target) {
                start = pos + 1;
            } else if (pos > target) {
                end = pos - 1;
            } else {
                break;
            }
        }
        return nums[target];
    }
    
private:
    int partion(vector<int>& nums, int start, int end) {
        int pivot = nums[end], index = start;
        for (int i = start; i < end; ++i) {
            if (nums[i] < pivot) {
                std::swap(nums[i], nums[index]);
                index++;
            }
        }
        std::swap(nums[end], nums[index]);
        return index;
    }
};