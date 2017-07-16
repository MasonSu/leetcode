/**
 * Given two sorted integer arrays nums1 and nums2, merge nums2
 * into nums1 as one sorted array.
 *
 * Note:
 * You may assume that nums1 has enough space (size that is greater
 * or equal to m + n) to hold additional elements from nums2.
 * The number of elements initialized in nums1 and nums2 are m and n respectively.
 *
 */

#include <vector>

using std::vector;

/* After insert, only the iterators before the insertion
 * point remain valid, so it need to update iterator
 * http://en.cppreference.com/w/cpp/container/vector/insert
 */
/*class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int length = m;
    auto iter1 = nums1.begin(), iter2 = nums2.begin();

    while (iter1 != nums1.begin() + m && iter2 != nums2.begin() + n) {
      if (*iter1 > *iter2) {
        iter1 = nums1.insert(iter1, *iter2);
        m++;
        iter2++;
      }
      iter1++;
    }

    if (iter2 != nums2.end())
      nums1.insert(iter1, iter2, nums2.end());

    nums1.erase(nums1.begin() + length + n, nums1.end());
  }
};*/

class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int length = m + n - 1;
    m--;
    n--;

    while (m >= 0 && n >= 0) {
      if (nums1[m] > nums2[n]) {
        nums1[length] = nums1[m];
        m--;
      } else {
        nums1[length] = nums2[n];
        n--;
      }
      length--;
    }

    while (n >= 0)
      nums1[length--] = nums2[n--];
  }
};