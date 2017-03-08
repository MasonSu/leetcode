#include <iostream>
#include <vector>
#include <cmath>

using std::cout;
using std::vector;

bool isValid(vector<int>& tmp, int row, int value)
{
  /* Check each line before */
  for (int i = 0; i < row; ++i)
    if (tmp[i] == value || std::abs(value - tmp[i]) == std::abs(row - i))
      return false;

  return true;
}

void queen(vector<vector<int>>& result, vector<int>& tmp, int row)
{
  if (row == 4) {
    result.push_back(tmp);
    return;
  }

  for (int col = 0; col < 4; ++col) {
    if (isValid(tmp, row, col)) {
      tmp.push_back(col);
      queen(result, tmp, row + 1);
      tmp.pop_back();
    }
  }
}

int main(int argc, char const *argv[])
{
  vector<vector<int>> result;
  vector<int> combin;
  queen(result, combin, 0);
  for (auto vec : result) {
    for (int i : vec)
      cout << i << ' ';
    cout << '\n';
  }
  return 0;
}