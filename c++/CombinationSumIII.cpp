/**
 * Find all possible combinations of k numbers that
 * add up to a number n, given that only numbers from
 * 1 to 9 can be used and each combination should be
 * a unique set of numbers.
 *
 * Example 1:
 *
 * Input: k = 3, n = 7
 *
 * Output:
 *
 * [[1,2,4]]
 *
 * Example 2:
 *
 * Input: k = 3, n = 9
 *
 * Output:
 *
 * [[1,2,6], [1,3,5], [2,3,4]]
 */

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> result;
    vector<int> vec;

    backtracking(result, vec, k, 1, n);

    return result;
  }

private:
  void backtracking(vector<vector<int>>& result, vector<int>& vec, int k, int begin, int n) {
    for (auto c : vec)
      std::cout << c << " ";
    std::cout << "\n";

    if (vec.size() == k && n == 0) {
      result.push_back(vec);
      return;
    }

    for (int i = begin; i < 10; ++i) {
      /* 这个条件用来剪枝 */
      if (i > n)
        break;
      vec.push_back(i);
      /* 注意这个条件是i+1，不是i，表示从下一个数开始遍历，而不是从当前数开始遍历 */
      backtracking(result, vec, k, i + 1, n - i);
      vec.pop_back();
    }
  }
};

int main(int argc, char const *argv[])
{
  Solution test;
  vector<vector<int>> result;
  result = test.combinationSum3(3, 9);

  std::cout << "result\n";

  for (auto v : result) {
    for (auto c : v)
      std::cout << c << " ";
    std::cout << "\n";
  }
  return 0;
}