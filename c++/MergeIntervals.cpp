/** 
 * Given a collection of intervals, merge all overlapping intervals.
 *
 * For example,
 * Given [1,3],[2,6],[8,10],[15,18],
 * return [1,6],[8,10],[15,18].
 */

/* Failed */
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

struct Interval {
  int start;
  int end;
  Interval(): start(0), end(0) {}
  Interval(int s, int e): start(s), end(e) {}
};

class Solution {
public:
  vector<Interval> merge(vector<Interval>& intervals) {
    if (intervals.empty())
      return {};
    std::sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {return a.start < b.start;});
    vector<Interval> result{intervals[0]};
    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i].start > result.back().end)
        result.push_back(intervals[i]);
      else {
        if (intervals[i].end > result.back().end)
          result.back().end = intervals[i].end;
      }
    }
    return result;
  }
};