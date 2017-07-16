/**
 *
 * Given an array of integers, return indices of the 
 * two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one 
 * solution, and you may not use the same element twice.
 * 
 * Example:
 * Given nums = [2, 7, 11, 15], target = 9,
 *
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 *
 */

#include <vector>
#include <iostream>
#include <unordered_map>

using std::vector;
using std::unordered_map;

// class Solution {
// public:
//   vector<int> twoSum(vector<int>& nums, int target) {
//     for (int i = 0; i < nums.size() - 1; ++i) {
//       for (int j = i + 1; j < nums.size(); ++j) {
//         if (nums[i] + nums[j] == target) {
//           vector<int> result;
//           result.push_back(i);
//           result.push_back(j);
//           return result;
//         }
//       }
//     }
//   }
// };

/* Use map to reduce the look up time*/
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> container;

    for (int i = 0; i < nums.size(); ++i) {
      int number = target - nums[i];
      
      if (container.find(number) != container.end() && i != container[number]) {
        vector<int> result;
        result.push_back(i);
        result.push_back(container[number]);
        return result;
      }

      container.insert({nums[i], i});
    }
  }
};

int main(int argc, char const *argv[])
{
  Solution test;
  vector<int> input, output;
  input = {3, 2, 4};
  output = test.twoSum(input, 6);
  for (auto &r : output)
    std::cout << r << " ";
  std::cout << std::endl;
  return 0;
}