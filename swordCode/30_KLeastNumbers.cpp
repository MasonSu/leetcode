/**
 *
 * 输入n个整数，找出其中最小的K个数。
 * 例如输入4,5,1,6,2,7,3,8这8个数字，
 * 则最小的4个数字是1,2,3,4
 *
 */


#include <vector>
#include <set>
#include <queue>
#include <functional>

using std::vector;
using std::multiset;
using std::priority_queue;

class Solution {
public:
  vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    if (input.empty() || k > input.size())
      return {};
    multiset<int, std::greater<int> > container;
    for (const int i : input) {
      if (container.size() < k) {
        container.insert(i);
        continue;
      }
      if (i < * (container.begin())) {
        container.erase(*(container.begin()));
        container.insert(i);
      }
    }
    vector<int> result(container.begin(), container.end());
    return result;
  }
};

class Solution2 {
public:
  vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    if (input.empty() || k > input.size())
      return {};

    priority_queue<int> container;
    for (const int i : input) {
      if (container.size() < k) {
        container.push(i);
      } else if (i < container.top()) {
        container.pop();
        container.push(i);
      }
    }

    vector<int> result;
    while (container.size()) {
      result.push_back(container.top());
      container.pop();
    }

    return result;
  }
};