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