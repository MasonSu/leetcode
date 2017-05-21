/**
 *
 * Implement int sqrt(int x).
 * Compute and return the square root of x.
 *
 */

#include <iostream>

class Solution {
public:
  int mySqrt(int x) {
    if (x == 0)
      return 0;
    int low = 1, high = x;
    while (low <= high) {
      int middle = low + (high - low) / 2;  
      if (middle < x / middle)
        low = middle + 1;
      else if (middle > x / middle)
        high = middle - 1;
      else
        return middle;
    }
    return high;
  }
};

int main(int argc, char const *argv[])
{
  Solution test;
  int number;
  while (std::cin >> number)
    std::cout << test.mySqrt(number) << std::endl;
  return 0;
}