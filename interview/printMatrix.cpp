#include <vector>
#include "catch.hpp"

using std::vector;

/**
 * (0,0)
 * (1,0) (0,1)
 * (0,2) (1,1) (2,0)
 * (3,3) (2,1) (1,2) (0,3)
 * (1,3) (2,2) (3,1)
 * (3,2) (2,3)
 * (3,3)
 */

class Solution {
public:
  vector<int> print(const vector<vector<int>> &vec) {
    if (vec.empty())
      return {};

    vector<int> result;

    int n = vec.front().size();
    bool flag = true;
    int begin = 0, end = 0;

    for (int k = 1; k < 2 * n; ++k) {
      if (flag) {
        for (int i = begin, j = end; i <= end && j >= begin; ++i, --j)
          result.push_back(vec[i][j]);

        /* 不能这么改，改完begin之后，会影响end的值 */
        /*if (k < n) {
          begin = end + 1;
          end = begin;
        } else {
          begin = end;
          end = begin + 1;
        }*/

        if (k < n) {
          begin = end + 1;
          end = k - begin;
        } else {
          begin = end;
          end = k - begin;
        }

        flag = false;
      } else {
        for (int i = begin, j = end; i >= end && j <= begin; --i, ++j)
          result.push_back(vec[i][j]);

        if (k < n) {
          begin = end;
          end = k - begin;
        } else {
          begin = end + 1;
          end = k - begin;
        }

        flag = true;
      }
    }

    return result;
  }
};

/**
 * (0,3)
 * (0,2) (1,3)
 * (0,1) (1,2) (2,3)
 * (0,0) (1,1) (2,2) (3,3)
 * (1,0) (2,1) (3,2)
 * (2,0) (3,1)
 * (3,0)
 */

/*class Solution {
public:
  vector<int> print(vector<vector<int>>& vec) {
    if (vec.empty())
      return {};

    vector<int> result;
    int n = vec.front().size();

    int begin = 0, end = n - 1;
    int k = 1;

    while (k < n) {
      for (int i = 0, j = end; j < n; ++i, ++j)
        result.push_back(vec[i][j]);

      end--;
      ++k;
    }

    while (k < 2 * n) {
      for (int i = begin, j = 0; i < n; ++i, ++j)
        result.push_back(vec[i][j]);

      begin++;
      ++k;
    }

    return result;
  }
};*/

TEST_CASE("print matrix", "[matrix]") {
  Solution test;

  /*vector<vector<int>> vec1 {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
  REQUIRE(test.print(vec1) == vector<int>({4, 3, 8, 2, 7, 12, 1, 6, 11, 16, 5, 10, 15, 9, 14, 13}));

  vector<vector<int>> vec2 {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}, {21, 22, 23, 24, 25}};
  REQUIRE(test.print(vec2) == vector<int>({5, 4, 10, 3, 9, 15, 2, 8, 14, 20, 1, 7, 13, 19, 25, 6, 12, 18, 24, 11, 17, 23, 16, 22, 21}));*/

  vector<vector<int>> vec1{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  REQUIRE(test.print(vec1) == vector<int>({1, 4, 2, 3, 5, 7, 8, 6, 9}));

  vector<vector<int>> vec2{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
  REQUIRE(test.print(vec2) == vector<int>({1, 5, 2, 3, 6, 9, 13, 10, 7, 4, 8, 11, 14, 15, 12, 16}));

  vector<vector<int>> vec3{{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}, {21, 22, 23, 24, 25}};
  REQUIRE(test.print(vec3) == vector<int>({1, 6, 2, 3, 7, 11, 16, 12, 8, 4, 5, 9, 13, 17, 21, 22, 18, 14, 10, 15, 19, 23, 24, 20, 25}));
}