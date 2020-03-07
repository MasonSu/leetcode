// Given an array nums of n integers and an integer target, find 
// three integers in nums such that the sum is closest to target.
// Return the sum of the three integers. You may assume that each 
// input would have exactly one solution.

// Example:

// Given array nums = [-1, 2, 1, -4], and target = 1.

// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
  		if (nums.empty())
  			return 0;
  		std::sort(nums.begin(), nums.end());
  		int result = 0, diff = INT_MAX;
  		for (int i = 0; i < nums.size(); ++i) {
  			if (i > 0 && nums[i] == nums[i - 1])
  				continue;
  			int start = i + 1, end = nums.size() - 1;
  			while (start < end) {
  				int sum = nums[i] + nums[start] + nums[end];
  				if (sum == target) {
  					return target;
  				} 

  				if (std::abs(sum - target) < diff) {
  					diff = std::abs(sum - target);
  					result = sum;
  				}

  				if (sum > target) {
  					end--;
  				} else {
  					start++;
  				}
  			}
  		}  
  		return result;    
    }
};