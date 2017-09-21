/**
 * 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
 * 如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同
 */

#include <vector>

using std::vector;

class Solution1 {
public:
  bool VerifySquenceOfBST(vector<int> sequence) {
    if (sequence.empty())
      return false;

    int rootValue = sequence.back();
    int index = 0;

    for (; index < sequence.size() - 1; ++index)
      if (sequence[index] > rootValue)
        break;

    vector<int> left(sequence.begin(), sequence.begin() + index);
    vector<int> right(sequence.begin() + index, sequence.end() - 1);

    for (; index < sequence.size() - 1; ++index)
      if (sequence[index] < rootValue)
        return false;

    if (left.size() <= 1 && right.size() <= 1)
      return true;
    else if (left.size() <= 1)
      return VerifySquenceOfBST(right);
    else if (right.size() <= 1)
      return VerifySquenceOfBST(left);
    else
      return VerifySquenceOfBST(left) && VerifySquenceOfBST(right);
  }
};

class Solution2 {
public:
  bool VerifySquenceOfBST(vector<int> sequence) {
    if (sequence.empty())
      return false;

    return verify(sequence);
  }

private:
  bool verify(const vector<int>& sequence) {
    if (sequence.size() <= 1)
      return true;

    int rootValue = sequence.back();
    int index = 0;

    for (; index < sequence.size() - 1; ++index)
      if (sequence[index] > rootValue)
        break;

    vector<int> left(sequence.begin(), sequence.begin() + index);
    vector<int> right(sequence.begin() + index, sequence.end() - 1);

    for (; index < sequence.size() - 1; ++index)
      if (sequence[index] < rootValue)
        return false;

    return verify(left) && verify(right);
  }
};