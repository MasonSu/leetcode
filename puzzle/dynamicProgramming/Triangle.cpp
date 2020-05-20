// Given a triangle, find the minimum path sum from top to bottom. Each step 
// you may move to adjacent numbers on the row below.

// For example, given the following triangle

// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty())
            return 0;
        if (triangle.size() == 1)
            return triangle[0][0];
        int result = INT_MAX;
        for (int i = 1; i < triangle.size(); ++i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                if (j == 0) {
                    triangle[i][j] = triangle[i - 1].front() + triangle[i][j];
                } else if (j == triangle[i].size() - 1) {
                    triangle[i][j] = triangle[i - 1].back() + triangle[i][j];
                } else {
                    triangle[i][j] = std::min(triangle[i - 1][j - 1], triangle[i - 1][j]) + triangle[i][j];
                }
                if (i == triangle.size() - 1) {
                    result = std::min(result, triangle[i][j]);
                }
            }
        }
        return result;
    }
};