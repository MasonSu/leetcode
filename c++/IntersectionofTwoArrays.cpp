/** 
 * Given two arrays, write a function to compute their intersection.
 *
 * Example:
 * Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
 * 
 * Note:
 * Each element in the result must be unique.
 * The result can be in any order.
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using std::vector;
using std::unordered_set;


/*class Solution {
public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.empty() || nums2.empty())
      return {};

    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());

    vector<int> result;
    for (int i = 0, j = 0; i < nums1.size() && j < nums2.size(); ) {
      if (nums1[i] < nums2[j])
        i++;
      else if (nums1[i] > nums2[j])
        j++;
      else {
        result.push_back(nums1[i]);
        i++;
        j++;

        while (i < nums1.size() && nums1[i] == nums1[i - 1])
          i++;
        while (j < nums2.size() && nums2[j] == nums2[j - 1])
          j++;
      }
    }

    return result;
  }
};*/

class Solution {
public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> hash;

    for (int i : nums1)
      hash.insert(i);

    vector<int> result;
    for (int i : nums2) {
      if (hash.find(i) != hash.end()) {
        hash.erase(i);
        result.push_back(i);
      }
    }

    return result;
  }
};