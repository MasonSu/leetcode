#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::vector;

int sort(vector<int>& nums, int low, int high)
{
  int pivot = nums[high];
  int index = low;
  for (int i = low; i < high; ++i) {
    if (nums[i] < pivot) {
      std::swap(nums[index], nums[i]);
      index++;
    }
  }
  std::swap(nums[index], nums[high]);
  return index;
}

void quickSort(vector<int>& nums, int low, int high)
{
  if (low >= high)
    return;
  int middle = sort(nums, low, high);
  quickSort(nums, low, middle - 1);
  quickSort(nums, middle + 1, high);
}

int main(int argc, char const *argv[])
{
  vector<int> test {9, 7, 5, 11, 12, 2, 14, 3, 10, 6};
  quickSort(test, 0, test.size() - 1);
  for (int i : test)
    cout << i << ' ';
  cout << '\n';
  return 0;
}