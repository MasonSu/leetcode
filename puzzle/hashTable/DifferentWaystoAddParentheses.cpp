// Given a string of numbers and operators, return all possible results 
// from computing all the different possible ways to group numbers and
// operators. The valid operators are +, - and *.

// Example 1:

// Input: "2-1-1"
// Output: [0, 2]
// Explanation: 
// ((2-1)-1) = 0 
// (2-(1-1)) = 2
// Example 2:

// Input: "2*3-4*5"
// Output: [-34, -14, -10, -10, 10]
// Explanation: 
// (2*(3-(4*5))) = -34 
// ((2*3)-(4*5)) = -14 
// ((2*(3-4))*5) = -10 
// (2*((3-4)*5)) = -10 
// (((2*3)-4)*5) = 10

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        if (input.empty())
            return {};
        unordered_map<string, vector<int>> um;
        vector<int> result = diffways(um, input);
        return result;
    }
    
private:
    vector<int> diffways(unordered_map<string, vector<int>>& um, string str) {
        if (um.count(str) != 0)
            return um[str];
        vector<int> result;
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] == '+' || str[i] == '-' || str[i] == '*') {
                vector<int> v1 = diffways(um, str.substr(0, i));
                vector<int> v2 = diffways(um, str.substr(i + 1));
                for (int j : v1) {
                    for (int k : v2) {
                        int r = 0;
                        switch (str[i]) {
                            case '+':
                                r = j + k;
                                break;
                            case '-':
                                r = j - k;
                                break;
                            case '*':
                                r = j * k;
                                break;
                        }
                        result.push_back(r);
                    }
                }
            }
        }
        // 字符串只含有一个数字
        if (result.empty())
            result.push_back(std::stoi(str));
        um.insert({str, result});
        return result;
    }
};