/**
 *
 * Given n non-negative integers a1, a2, ..., an, where each
 * represents a point at coordinate (i, ai). n vertical lines
 * are drawn such that the two endpoints of line i is at (i, ai)
 * and (i, 0). Find two lines, which together with x-axis forms
 * a container, such that the container contains the most water.
 *
 * Note: You may not slant the container and n is at least 2.
 *
 */

/* Failed */
#include <vector>
#include <algorithm>

using std::vector;

/*class Solution {
public:
  int maxArea(vector<int>& height) {
    int max = 0;
    for (int i = 0; i < height.size(); ++i) {
      for (int j = i + 1; j < height.size(); ++j) {
        int area = std::min(height[i], height[j]) * (j - i);
        if (max < area)
          max = area;
      }
    }
    return max;
  }
};*/

class Solution {
public:
  int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int max = 0;
    while (left < right) {
      int area = std::min(height[left], height[right]) * (right - left);
      if (max < area)
        max = area;
      if (height[left] < height[right])
        left++;
      else
        right--;
    }
    return max;
  }
};