// Write an efficient algorithm that searches for a value 
// in an m x n matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer 
// of the previous row.
// Example 1:

// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 3
// Output: true
// Example 2:

// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 13
// Output: false

// 先将第一列抽出来，定位到所处的行后再采用二分查找
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty() || target < matrix[0][0])
            return false;
        int lengthX = matrix.size(), lengthY = matrix[0].size();
        vector<int> vec(lengthX);
        for (int i = 0; i < lengthX; ++i)
            vec[i] = matrix[i][0];
        int pos = search(vec, target);
        if (pos < lengthX && matrix[pos][0] == target)
            return true;
        // 在前一行查找
        int index = search(matrix[pos - 1], target);
        if (index < lengthY && matrix[pos - 1][index] == target)
            return true;
        return false;
    }
    
private:
    int search(vector<int>& vec, int target) {
        int start = 0, end = vec.size();
        while (start < end) {
            int middle = start + (end - start) / 2;
            if (vec[middle] < target) {
                start = middle + 1;
            } else {
                end = middle;
            }
        }
        return end;
    }
};