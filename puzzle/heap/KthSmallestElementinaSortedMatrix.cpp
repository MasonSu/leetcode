// Given a n x n matrix where each of the rows and columns are sorted in 
// ascending order, find the kth smallest element in the matrix.

// Note that it is the kth smallest element in the sorted order, not the 
// kth distinct element.

// Example:

// matrix = [
//    [ 1,  5,  9],
//    [10, 11, 13],
//    [12, 13, 15]
// ],
// k = 8,

// return 13.
// Note:
// You may assume k is always valid, 1 ≤ k ≤ n2.

// O(N + klogN)
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        auto comp = [](element a, element b){return a.val > b.val;};
        priority_queue<element, vector<element>, decltype(comp)> q(comp);
        int lengthX = matrix.size(), lengthY = matrix[0].size();
        // 将第一行的数据插入
        for (int i = 0; i < lengthY; ++i) {
            q.push(element(matrix[0][i], 0, i));
        }
        element e;
        while (k) {
            e = q.top();
            q.pop();
            // 下一个较小的值可能为弹出元素的下一行
            if (e.row + 1 < lengthX)
                q.push(element(matrix[e.row + 1][e.column], e.row + 1, e.column));
            k--;
        }
        return e.val;
    }

private:
    struct element {
        element() {}
        element(int val, int row, int column): val(val), row(row), column(column) {}
        int val;
        int row;
        int column;
    };
};