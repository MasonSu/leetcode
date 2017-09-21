/**
 * 给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
 * 例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一
 * 共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 针对数组
 * {2,3,4,2,6,2,5,1}的滑动窗口有以下6个： {[2,3,4],2,6,2,5,1}，
 * {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}，
 * {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
 */

#include <set>
#include <vector>
#include <deque>

using std::multiset;
using std::vector;
using std::deque;

class Solution {
public:
  vector<int> maxInWindows(const vector<int>& num, unsigned int size)
  {
    if (num.empty() || size < 1 || size > num.size())
      return {};

    multiset<int> hash;
    vector<int> result;
    for (int i = 0; i < num.size(); ++i) {
      if (i < size) {
        hash.insert(num[i]);
      } else {
        result.push_back(*(--hash.end()));
        int count = hash.erase(num[i - size]);
        if (count > 1) {
          while (--count)
            hash.insert(num[i - size]);
        }
        hash.insert(num[i]);
      }
    }
    result.push_back(*(--hash.end()));
    return result;
  }
};

class Solution2 {
public:
  vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
    if (num.empty())
      return{};

    deque<int> index;
    vector<int> result;
    for (int i = 0; i < num.size(); ++i) {
      while (index.size() && num[i] > num[index.back()])
        index.pop_back();

      index.push_back(i);

      if (i - index.front() >= size)
        index.pop_front();

      if (i >= size - 1)
        result.push_back(num[index.front()]);
    }

    return result;
  }
};