// Given a 2D matrix matrix, find the sum of the elements inside 
// the rectangle defined by its upper left corner (row1, col1) 
// and lower right corner (row2, col2).

// Example:
// Given matrix = [
//   [3, 0, 1, 4, 2],
//   [5, 6, 3, 2, 1],
//   [1, 2, 0, 1, 5],
//   [4, 1, 0, 1, 7],
//   [1, 0, 3, 0, 5]
// ]

// sumRegion(2, 1, 4, 3) -> 8
// sumRegion(1, 1, 2, 2) -> 11
// sumRegion(1, 2, 2, 4) -> 12
// Note:
// You may assume that the matrix does not change.
// There are many calls to sumRegion function.
// You may assume that row1 ≤ row2 and col1 ≤ col2.

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return;
        int lengthX = matrix.size(), lengthY = matrix[0].size();
        vec = vector<vector<int>>(lengthX, vector<int>(lengthY + 1));
        for (int i = 0; i < lengthX; ++i) {
            int sum = 0;
            for (int j = 0; j < lengthY; ++j) {
                sum += matrix[i][j];
                vec[i][j + 1] = sum;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (vec.empty())
            return 0;
        int sum = 0;
        for (int i = row1; i <= row2; ++i) {
            sum += vec[i][col2 + 1] - vec[i][col1];
        }
        return sum;
    }
    
private:
    vector<vector<int>> vec;
};

class NumMatrix2 {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return;
        int lengthX = matrix.size(), lengthY = matrix[0].size();
        vec = vector<vector<int>>(lengthX + 1, vector<int>(lengthY + 1));
        for (int i = 1; i <= lengthX; ++i) {
            for (int j = 1; j <= lengthY; ++j) {
                vec[i][j] = vec[i - 1][j] + vec[i][j - 1] - vec[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (vec.empty())
            return 0;
        return vec[row2 + 1][col2 + 1] - vec[row2 + 1][col1] - vec[row1][col2 + 1] + vec[row1][col1];
    }
    
private:
    vector<vector<int>> vec;
};