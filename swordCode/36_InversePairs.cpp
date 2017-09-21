/**
* 在数组中的两个数字，如果前面一个数字大于后面的数字，
* 则这两个数字组成一个逆序对。输入一个数组,求出这个数
* 组中的逆序对的总数P。并将P对1000000007取模的结果输出。
* 即输出P%1000000007
*/

#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
  int InversePairs(vector<int> data) {
    if (data.empty())
      return 0;

    long long int count = 0;
    vector<int> result = merge(data, count);

    return count % 1000000007;
  }

private:
  vector<int> merge(vector<int>& vec, long long int& count) {
    /* 这里不能写成high = vec.size() - 1, 如果vec.size()为2的话,
     * 算出来的middle为0, 会导致这两个数不会排序而直接返回
     */
    /*int low = 0, high = vec.size() - 1;
    int middle = low + (high - low) / 2;
    if (middle == 0)
      return vec;*/

    int middle = vec.size() / 2;
    if (middle == 0)
      return vec;

    vector<int> left(vec.begin(), vec.begin() + middle);
    vector<int> right(vec.begin() + middle, vec.end());

    left = merge(left, count);
    right = merge(right, count);

    return sort(left, right, count);
  }

  vector<int> sort(vector<int>& v1, vector<int>& v2, long long int& count) {
    vector<int> result;
    result.reserve(v1.size() + v2.size());

    int i = 0, j = 0;
    while (i < v1.size() && j < v2.size()) {
      if (v1[i] < v2[j])
        result.push_back(v1[i++]);
      else {
        count += v1.size() - i;
        result.push_back(v2[j++]);
      }
    }

    if (i == v1.size())
      result.insert(result.end(), v2.begin() + j, v2.end());
    else if (j == v2.size())
      result.insert(result.end(), v1.begin() + i, v1.end());

    return result;
  }
};

class Solution2 {
public:
  int InversePairs(vector<int> data) {
    long long int count = 0;

    MergeSort(data, count);

    return count % 1000000007;
  }

private:
  void MergeSort(vector<int> &vec, long long int& count) {
    vector<int> tmpVec;
    tmpVec.resize(vec.size());

    merge(vec, tmpVec, 0, vec.size() - 1, count);
  }

  void merge(vector<int>& vec, vector<int>& tmpVec, int low, int high, long long int& count) {
    if (low >= high)
      return;

    int middle = low + (high - low) / 2;

    merge(vec, tmpVec, low, middle, count);
    merge(vec, tmpVec, middle + 1, high, count);
    sort(vec, tmpVec, low, middle, high, count);
  }

  void sort(vector<int>& vec, vector<int>& tmpVec, int low, int middle, int high, long long int& count) {
    int index = low;
    int left = low, right = middle + 1;

    while (left <= middle && right <= high) {
      if (vec[left] < vec[right])
        tmpVec[index++] = vec[left++];
      else {
        count += middle + 1 - left;
        tmpVec[index++] = vec[right++];
      }
    }

    while (left <= middle)
      tmpVec[index++] = vec[left++];

    while (right <= high)
      tmpVec[index++] = vec[right++];

    /* copy back */
    while (low <= high) {
      vec[low] = tmpVec[low];
      low++;
    }
  }
};
