// There are N children standing in a line. Each child is assigned a rating value.

// You are giving candies to these children subjected to the following requirements:

// Each child must have at least one candy.
// Children with a higher rating get more candies than their neighbors.
// What is the minimum candies you must give?

// Example 1:

// Input: [1,0,2]
// Output: 5
// Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
// Example 2:

// Input: [1,2,2]
// Output: 4
// Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
//              The third child gets 1 candy because it satisfies the above two conditions.

// two direction
class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.empty())
            return 0;
        int length = ratings.size();
        vector<int> vec(length, 1);
        for (int i = 1; i < length; ++i) {
            if (ratings[i] > ratings[i - 1])
                vec[i] = vec[i - 1] + 1;
        }
        for (int i = length - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1])
                vec[i] = std::max(vec[i], vec[i + 1] + 1);
        }
        int result = 0;
        for (int i : vec)
            result += i;
        return result;
    }
};