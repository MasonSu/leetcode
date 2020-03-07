// Given a non-negative integer numRows, generate the first 
// numRows of Pascal's triangle.

// Example:

// Input: 5
// Output:
// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (int n = 1; n <= numRows; ++n) {
            vector<int> vec(n, 1);
            for (int i = 1; i < vec.size() - 1; ++i)
                vec[i] = result.back()[i - 1] + result.back()[i];
            result.push_back(vec);
        }
        return result;
    }
};