class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       if (nums.empty())
           return {};
       /* 存放数的下标 */
       deque<int> dq;
       vector<int> result;
       for (int i = 0; i < nums.size(); ++i) {
           /* 去除队列开头范围之外的数 */
           if (dq.size() && dq.front() <= i - k)
               dq.pop_front();
           /* 队列中存放下标指向的数按降序排列 */
           while (dq.size() && nums[dq.back()] < nums[i])
               dq.pop_back();
           dq.push_back(i);
           if (i >= k - 1)
               result.push_back(nums[dq.front()]);
       }
       return result;
    }
};
