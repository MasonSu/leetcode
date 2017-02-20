#include <iostream>
#include <vector>

using std::cout;
using std::vector;

vector<int> Merge(vector<int>& left, vector<int>& right)
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
}

int main(int argc, char const *argv[])
{
  vector<int> test{27,10,12,25,34,16,15,31};
  vector<int> result = MergeSort(test);
  for (int i : result)
    cout << i << ' ';
  cout << '\n';
  return 0;
}