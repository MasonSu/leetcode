#include <iostream>
#include <vector>

using std::cout;
using std::vector;

void ShellSort(vector<int>& nums)
{
  int step = nums.size() / 2;
  while (step) {
    for (int begin = 0; begin < step; ++begin) {
      for (int i = begin + step; i < nums.size(); i = i + step) {
        int target = nums[i];
        while (i > begin && target < nums[i - step]) {
          nums[i] = nums[i - step];
          i = i - step;
        }
        nums[i] = target;
      }
    }
    step /= 2;
  }
}

int main(int argc, char const *argv[])
{
  vector<int> test{3, 44, 38, 5, 47, 15};
  ShellSort(test);
  for (int i : test)
    cout << i << ' ';
  cout << '\n';
  return 0;
}