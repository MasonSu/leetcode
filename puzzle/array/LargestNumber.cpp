// Given a list of non negative integers, arrange them such that they form the largest number.

// Example 1:

// Input: [10,2]
// Output: "210"
// Example 2:

// Input: [3,30,34,5,9]
// Output: "9534330"
// Note: The result may be very large, so you need to return a string instead of an integer.

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if (nums.empty())
            return "";
        list<string> ls{std::to_string(nums[0])};
        for (int i = 1; i < nums.size(); ++i) {
            insert(ls, nums[i]);
        }
        string result;
        for (auto iter = ls.begin(); iter != ls.end(); ++iter)
            result += *iter;
        // "00"
        if (result[0] == '0')
        	return "0";
        return result;
    }

private:
    void insert(list<string>& ls, int num) {
        string str = std::to_string(num);
        for (auto iter = ls.begin(); iter != ls.end(); ++iter) {
            string s1 = str + *iter, s2 = *iter + str;
            if (s1 >= s2) {
                ls.insert(iter, str);
                return;
            }
        }
        ls.insert(ls.end(), str);
    }
};

class Solution2 {
public:
    string largestNumber(vector<int>& nums) {
        if (nums.empty())
            return "";
        vector<string> vec;
        for (int num : nums)
        	vec.push_back(std::to_string(num));
        std::sort(vec.begin(), vec.end(), [](const string &str1, const string &str2) { return str1 + str2 > str2 + str1; });
        string result;
        for (string &s : vec)
        	result += s;
        if (result[0] == '0')
        	return "0";
        return result;
    }
};