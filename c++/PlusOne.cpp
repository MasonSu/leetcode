/**
 *
 * Given a non-negative integer represented as a non-empty array
 * of digits, plus one to the integer.
 *
 * You may assume the integer do not contain any leading zero,
 * except the number 0 itself.
 *
 * The digits are stored such that the most significant digit is at the
 * head of the list.
 *
 */

#include <vector>

using std::vector;

/*class Solution {
public:
  vector<int> plusOne(vector<int>& digits) {
    bool ten = true;
    for (auto iter = digits.rbegin(); iter != digits.rend(); ++iter) {
      if (ten) {
        (*iter)++;
        if (*iter == 10)
          *iter = 0;
        else
          ten = false;
        continue;
      }
      break;
    }
    // {9}
    if (ten)
      digits.insert(digits.begin(), 1);
    return digits;
  }
};*/

class Solution {
public:
  vector<int> plusOne(vector<int>& digits) {
    for (auto iter = digits.rbegin(); iter != digits.rend(); ++iter) {
      if (*iter < 9) {
        (*iter)++;
        return digits;
      }
      *iter = 0;
    }
    /* 999 */
    digits[0] = 1;
    digits.push_back(0);
    return digits;
  }
};