/* 求最短通路值 */
#include <bits/stdc++.h>

using namespace std;

#include "catch.hpp"

/* DFS，会重复经过一些位置，但能得到所有路径 */
class Solution {
public:
    int minPathValue(vector<vector<int>>& vec) {
        if (vec.empty())
            return 0;
        int lengthX = vec.size(), lengthY = vec[0].size(), count = 0;
        vector<vector<int>> visted(lengthX, vector<int>(lengthY, 0));
        set<int> result;
        dfs(vec, visted, result, 0, 0, count);
        if (result.empty())
            return 0;
        return *result.begin();
    }
private:
    void dfs(vector<vector<int>>& vec, vector<vector<int>>& visted, set<int>& result, int i, int j, int count) {
        if (i < 0 || i >= vec.size() || j < 0 || j >= vec[0].size())
            return;
        if (!vec[i][j] || visted[i][j])
            return;
        count++;
        visted[i][j] = 1;
        if (i == vec.size() - 1 && j == vec[0].size() - 1) {
            result.insert(count);
            visted[i][j] = 0;
            return;
        }
        dfs(vec, visted, result, i - 1, j, count);
        dfs(vec, visted, result, i + 1, j, count);
        dfs(vec, visted, result, i, j - 1, count);
        dfs(vec, visted, result, i, j + 1, count);
        visted[i][j] = 0;
    }
};

/* BFS，不会重复经过位置，能得到最小值 */
class Solution2 {
public:
    int minPathValue(vector<vector<int>>& vec) {
        if (vec.empty() || vec[0][0] == 0)
            return 0;
        int lengthX = vec.size(), lengthY = vec[0].size();
        vector<vector<int>> path(lengthX, vector<int>(lengthY, 0));
        path[0][0] = 1;
        queue<pair<int, int>> nodes;
        nodes.push({0, 0});
        while (nodes.size()) {
            pair<int, int> node = nodes.front();
            nodes.pop();
            int x = node.first, y = node.second;
            if (x == lengthX - 1 && y == lengthY - 1)
                return path[x][y];
            bfs(vec, path, nodes, x - 1, y, path[x][y]);
            bfs(vec, path, nodes, x + 1, y, path[x][y]);
            bfs(vec, path, nodes, x, y - 1, path[x][y]);
            bfs(vec, path, nodes, x, y + 1, path[x][y]);
        }
        return 0;
    }
private:
    void bfs(vector<vector<int>>& vec, vector<vector<int>>& path, queue<pair<int, int>>& nodes, int i, int j, int value) {
        if (i < 0 || i >= vec.size() || j < 0 || j >= vec[0].size())
            return;
        if (!vec[i][j] || path[i][j])
            return;
        path[i][j] = value + 1;
        nodes.push({i, j});
    }
};

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    Solution2 test;
    vector<vector<int>> v1{{1,0,1,1,1},
                           {1,0,1,0,1},
                           {1,1,1,0,1},
                           {0,0,0,0,1}};
    REQUIRE(test.minPathValue(v1) == 12);
    vector<vector<int>> v2{{1,1,1,1,0},
                           {0,0,0,1,0},
                           {1,1,1,1,0},
                           {1,0,0,1,0},
                           {1,1,1,1,1},
                           {0,0,0,0,1}};
    REQUIRE(test.minPathValue(v2) == 10);
}
