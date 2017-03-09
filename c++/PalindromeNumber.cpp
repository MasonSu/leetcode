/**
 *
 * Determine whether an integer is a palindrome. Do this without extra space.
 *
 */

#include <iostream>

/*class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0)
      return false;
    int size = 0, tmpNum = x;
    while (tmpNum) {
      size++;
      tmpNum /= 10;
    }
    int left = x / power((size + 1) / 2), right = x % power(size / 2);
    int rightSize = size / 2, result = 0;
    while (rightSize) {
      int num = right % 10;
      result += num * power(--rightSize);
      right /= 10;
    }
    return left == result ? true : false;
  }

private:
  int power(int n) {
    int result = 1;
    while (n) {
      result *= 10;
      n--;
    }
    return result;
  }
};*/

class Solution {
public:
  bool isPalindrome(int x) {
    /* if the last bit of x is 0, then it can't be palindrome execpt 0 */
    if (x < 0 || (x != 0 && x % 10 == 0))
      return false;
    int result = 0;
    while (x > result) {
      result = result * 10 + x % 10;
      x /= 10;
    }
    /* the length of x is even or odd */
    return x == result || x == result / 10;
  }
};

int main(int argc, char const *argv[])
{
  Solution test;
  std::cout << test.isPalindrome(12331) << '\n';
  return 0;
}