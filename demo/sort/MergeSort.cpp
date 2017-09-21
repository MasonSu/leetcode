#include <iostream>
#include <vector>

using std::cout;
using std::vector;

/*vector<int> Merge(vector<int>& left, vector<int>& right)
{
  vector<int> result;
  int i = 0, j = 0;
  while (i < left.size() && j < right.size()) {
    if (left[i] < right[j]) {
      result.push_back(left[i]);
      i++;
    } else {
      result.push_back(right[j]);
      j++;
    }
  }

  if (i == left.size()) {
    result.insert(result.end(), right.begin() + j, right.end());
  } else if (j == right.size()) {
    result.insert(result.end(), left.begin() + i, left.end());
  }
  return result;
}

vector<int> MergeSort(vector<int>& nums)
{
  int middle = nums.size() / 2;
  if (middle == 0)
    return nums;
  vector<int> left(nums.begin(), nums.begin() + middle);
  vector<int> right(nums.begin() + middle, nums.end());
  left = MergeSort(left);
  right = MergeSort(right);
  return Merge(left, right);
}*/

void sort(vector<int>& vec, vector<int>& tmpVec, int low, int middle, int high) {
  int index = low;
  int left = low, right = middle + 1;

  while (left <= middle && right <= high) {
    if (vec[left] < vec[right])
      tmpVec[index++] = vec[left++];
    else
      tmpVec[index++] = vec[right++];
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

void merge(vector<int>& vec, vector<int>& tmpVec, int low, int high) {
  if (low >= high)
    return;

  int middle = low + (high - low) / 2;

  merge(vec, tmpVec, low, middle);
  merge(vec, tmpVec, middle + 1, high);
  sort(vec, tmpVec, low, middle, high);
}

void MergeSort(vector<int> &vec) {
  vector<int> tmpVec;
  /* 因为要用到下标，所以需要提前扩容 */
  tmpVec.resize(vec.size());

  merge(vec, tmpVec, 0, vec.size() - 1);
}

int main(int argc, char const *argv[])
{
  vector<int> test{3, 4, 1, 6, 5, 9, 2, 8, 7, 10};

  MergeSort(test);

  for (int i : test)
    cout << i << ' ';
  cout << '\n';
  return 0;
}