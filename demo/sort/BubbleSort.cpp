#include <iostream>
#include <vector>

using std::cout;
using std::vector;

void BubbleSort(vector<int>& nums)
{
  for (int length = nums.size(); length > 1; --length) {
    for (int i = 0; i < length - 1; ++i) {
      if (nums[i] > nums[i + 1]) {
        int temp = nums[i];
        nums[i] = nums[i + 1];
        nums[i + 1] = temp;
      }
    }
  }
}

int main(int argc, char const *argv[])
{
  vector<int> test{3, 44, 38, 5, 47, 15};
  BubbleSort(test);
  for (int i : test)
    cout << i << ' ';
  cout << '\n';
  return 0;
}