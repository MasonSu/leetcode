/**
 * https://i.imgur.com/u7SXuXH.jpg
 * https://i.imgur.com/Zk9crwV.jpg
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using std::cin;
using std::cout;
using std::vector;
using std::priority_queue;

int main() {
  int m, n;
  cin >> m >> n;

  int c;
  vector<int> vec;
  for (int i = 0; i < m; ++i) {
    cin >> c;
    vec.push_back(c);
  }

  if (m < n) {
    auto max = std::max_element(vec.begin(), vec.end());
    cout << *max << "\n";
  }
  else {
    priority_queue<int, vector<int>, std::greater<int>> heap;
    for (int i = 0; i < n; ++i)
      heap.push(vec[i]);

    for (int i = n; i < m; ++i) {
      int num = heap.top() + vec[i];
      heap.pop();
      heap.push(num);
    }

    while (heap.size() != 1)
      heap.pop();

    cout << heap.top() << "\n";
  }

  return 0;
}