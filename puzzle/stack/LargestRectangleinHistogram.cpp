#include <bits/stdc++.h>

using namespace std;

#include "catch.hpp"

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty())
            return 0;
        /* 栈中保存数组下标，保持对应的高度递增 */
        stack<int> risingHeight;
        int max = 0, length = heights.size(), num = 0, area = 0;
        for (int i = 0; i < length;) {
            if (risingHeight.empty() || heights[i] >= heights[risingHeight.top()]) {
                risingHeight.push(i++);
            } else {
                num = risingHeight.top();
                risingHeight.pop();
                /* area是以height[num]为最低点求得的面积，因为不管怎样选取矩形，一定是以最低的高度为基准
                 * 如果栈为空，则表明此高度左侧没有比它低的高度，因此长度为i，如果栈不为空，则当前栈顶就是
                 * 第一个比它低的高度的坐标(因为高度是递增的)
                 */
                area = heights[num] * (risingHeight.empty() ? i : i - risingHeight.top() - 1);
                max = std::max(area, max);
            }
        }
        while (risingHeight.size()) {
            num = risingHeight.top();
            risingHeight.pop();
            area = heights[num] * (risingHeight.empty() ? length : length - risingHeight.top() - 1);
            max = std::max(area, max);
        }
        return max;
    }
};

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    Solution test;
    vector<int> v1{2,1,5,6,2,3};
    REQUIRE(test.largestRectangleArea(v1) == 10);
    v1 = {6,2,5,4,5,1,6};
    REQUIRE(test.largestRectangleArea(v1) == 12);
    v1 = {2,1,0,5,2,3};
    REQUIRE(test.largestRectangleArea(v1) == 6);
}
