/**
 *
 * 在一个二维数组中，每一行都按照从左到右递增的顺序排序，
 * 每一列都按照从上到下递增的顺序排序。请完成一个函数，
 * 输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 *
 */


#include <vector>

using std::vector;

class Solution {
public:
  bool Find(int target, vector<vector<int> > array) {
    if (array.empty())
      return false;
    int length = array[0].size() - 1, width = 0;
    bool found = false;
    while (length >= 0 && width < array.size()) {
      if (array[width][length] > target)
        length--;
      else if (array[width][length] < target)
        width++;
      else {
        found = true;
        break;
      }
    }
    return found;
  }
};