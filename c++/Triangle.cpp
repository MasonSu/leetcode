/**
 * Given a triangle, find the minimum path sum from top to bottom.
 * Each step you may move to adjacent numbers on the row below.
 *
 * For example, given the following triangle
 *
 * [
 *      [2],
 *     [3,4],
 *    [6,5,7],
 *   [4,1,8,3]
 * ]
 *
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using std::vector;

/*class Solution {
public:
  int minimumTotal(vector<vector<int>>& triangle) {
    if (triangle.empty())
      return 0;
    vector<int> vec(triangle.back().size(), INT_MAX);
    vec[0] = triangle[0][0];
    for (int i = 1; i < triangle.size(); ++i) {
      for (int j = triangle[i].size() - 1; j >= 0; --j) {
        if (j == triangle[i].size() - 1)
          vec[j] = vec[j - 1] + triangle[i][j];
        else if (j == 0)
          vec[j] = vec[j] + triangle[i][j];
        else
          vec[j] = std::min(vec[j - 1], vec[j]) + triangle[i][j];
      }
    }
    return *std::min_element(vec.begin(), vec.end());
  }
};*/

class Solution {
public:
  int minimumTotal(vector<vector<int>> & triangle) {
    if (triangle.empty())
      return 0;
    vector<int> vec(triangle.back());
    for (int i = triangle.size() - 2; i >= 0; --i)
      for (int j = 0; j < triangle[i].size(); ++j)
        vec[j] = std::min(vec[j], vec[j + 1]) + triangle[i][j];
    return vec[0];
  }
};