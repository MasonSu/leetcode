class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.empty())
            return false;
        vector<int> vec;
        vec.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
           auto iter = std::lower_bound(vec.begin(), vec.end(), nums[i]);
           if (iter == vec.end()) {
               vec.push_back(nums[i]);
               if (vec.size() == 3) 
                   return true;	
           } else {
               *iter = nums[i];
           }
        }
        return false;
    }
};

class Solution2 {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.empty())
            return false;
        int first = INT_MAX, second = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= first) {
                first = nums[i];
            } else if (nums[i] <= second) {
                second = nums[i];
            } else {
                return true;
            }
        }
        return false;
    }
};