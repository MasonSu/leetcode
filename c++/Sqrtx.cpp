/**
 *
 * Implement int sqrt(int x).
 * Compute and return the square root of x.
 *
 */

#include <iostream>

using std::cout;

class Solution {
public:
  int mySqrt(int x) {
    if (x < 0)
      return -1;
    if (x == 1)
      return 1;
    int low = 0, high = x;
    while (low <= high) {
      long middle = low + (high - low) / 2;  /* middle must be long, or middle^2 will overflow*/
      if (middle * middle < x)
        low = middle + 1;
      else if (middle * middle > x)
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