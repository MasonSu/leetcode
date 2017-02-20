/**

29, 20, 73, 34, 64

29, 20, 73, 34, 64
20, 29, 73, 34, 64
20, 29, 73, 34, 64
20, 29, 34, 73, 64
20, 29, 34, 64, 73

 */

#include <iostream>
#include <vector>

using std::vector;
using std::cout;

void InsertionSort(vector<int>& nums)
{
  for (int i = 1; i < nums.size(); ++i) {
    int target = nums[i];
    while (i > 0 && target < nums[i - 1]) {
      nums[i] = nums[i - 1];
      i--;
    }
    nums[i] = target;
  }
}

int main(int argc, char const *argv[])
{
  vector<int> test{3, 44, 38, 5, 47, 15};
  InsertionSort(test);
  for (int i : test)
    cout << i << ' ';
  cout << '\n';
  return 0;
}