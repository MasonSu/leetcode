/**
 * Given a set of non-overlapping intervals, insert a new
 * interval into the intervals (merge if necessary).
 *
 * You may assume that the intervals were initially sorted
 * according to their start times.
 *
 * Example 1:
 * Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 *
 * Example 2:
 * Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
 *
 * This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 */

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

/*class Solution {
public:
  vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    if (intervals.empty())
      return {newInterval};
    int low = binarySearch(intervals, newInterval.start), high = binarySearch(intervals, newInterval.end);
    vector<Interval> result;
    if (high == -1) {
      result.push_back(newInterval);
      result.insert(result.end(), intervals.begin(), intervals.end());
      return result;
    }
    if (low == -1) {
      low++;
      intervals[low].start = newInterval.start;
    }
    result.insert(result.end(), intervals.begin(), intervals.begin() + low);

    if (intervals[low].end > newInterval.start) {
      if (intervals[high].end > newInterval.end)
        result.push_back(Interval(intervals[low].start, intervals[high].end));
      else
        result.push_back(Interval(intervals[low].start, newInterval.end));
    } else if (intervals[low].end < newInterval.start) {
      result.push_back(Interval(intervals[low].start, intervals[low].end));
      if (intervals[high].end > newInterval.end)
        result.push_back(Interval(newInterval.start, intervals[high].end));
      else
        result.push_back(Interval(newInterval.start, newInterval.end));
    } else {
      newInterval.start = intervals[low].start;
      if (intervals[high].end > newInterval.end)
        result.push_back(Interval(newInterval.start, intervals[high].end));
      else
        result.push_back(Interval(newInterval.start, newInterval.end));
    }
    if (result.back().end == intervals[high + 1].start) {
      result.back().end = intervals[high + 1].end;
      result.insert(result.end(), intervals.begin() + high + 2, intervals.end());
    }
    else
      result.insert(result.end(), intervals.begin() + high + 1, intervals.end());
    return result;
  }

private:
  int binarySearch(const vector<Interval>& vec, int num) {
    int low = 0, high = vec.size() - 1;
    while (low < high) {
      int middle = low + (high - low) / 2;
      if (vec[middle].start < num)
        low = middle + 1;
      else
        high = middle - 1;
    }
    if (num < vec[low].start)
      low--;
    return low;
  }
};*/

class Solution {
public:
  vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    if (intervals.empty())
      return {newInterval};
    vector<Interval> result;
    int i = 0;
    while (i < intervals.size() && newInterval.start > intervals[i].end)
      result.push_back(intervals[i++]);
    while (i < intervals.size() && newInterval.end > intervals[i].start) {
      newInterval = Interval(std::min(intervals[i].start, newInterval.start),
                             std::max(intervals[i].end, newInterval.end));
      i++;
    }
    if (i < intervals.size() && newInterval.end == intervals[i].start) {
      result.push_back(Interval(newInterval.start, intervals[i].end));
      result.insert(result.end(), intervals.begin() + i + 1, intervals.end());
    } else {
      result.push_back(newInterval);
      result.insert(result.end(), intervals.begin() + i, intervals.end());
    }
    return result;
  }
};