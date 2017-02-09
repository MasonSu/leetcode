/**
 *
 * Given an array of integers that is already sorted in ascending order, 
 * find two numbers such that they add up to a specific target number.
 * The function twoSum should return indices of the two numbers such that they 
 * add up to the target, where index1 must be less than index2. Please note that 
 * your returned answers (both index1 and index2) are not zero-based.
 * You may assume that each input would have exactly one solution and you may not use 
 * the same element twice.
 *
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 *
 */

#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    for (int i = 0, j = numbers.size() - 1; i < j; ) {
      int sum = numbers[i] + numbers[j];
      if (sum < target)
        ++i;
      else if (sum > target)
        --j;
      else {
        return vector<int>({i+1, j+1});
      }
    }
  }
};


int main(int argc, char const *argv[])
{
  Solution test;
  vector<int> input, output;
  input = {2, 7, 11, 15};
  output = test.twoSum(input, 18);
  for (auto &r : output)
    std::cout << r << " ";
  std::cout << std::endl;
  return 0;
}