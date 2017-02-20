/**

29, 64, 73, 34, 20 

20, 64, 73, 34, 29 
20, 29, 73, 34, 64 
20, 29, 34, 73, 64 
20, 29, 34, 64, 73 

 */


#include <iostream>
#include <vector>

using std::cout;
using std::vector;

void SelectionSort(vector<int>& nums)
{
  for (int i = 0; i < nums.size() - 1; ++i) {
    int index = i, min = nums[i];
    for (int j = i + 1; j < nums.size(); ++j) {
      if (nums[j] < min) {
        index = j;
        min = nums[j];
      }
    }
    nums[index] = nums[i];
    nums[i] = min;
  }
}

int main(int argc, char const *argv[])
{
  vector<int> test{3, 44, 38, 5, 47, 15};
  SelectionSort(test);
  for (int i : test)
    cout << i << ' ';
  cout << '\n';
  return 0;
}