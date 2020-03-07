// Suppose you have a random list of people standing in a queue. 
// Each person is described by a pair of integers (h, k), where 
// h is the height of the person and k is the number of people 
// in front of this person who have a height greater than or 
// equal to h. Write an algorithm to reconstruct the queue.

// Note:
// The number of people is less than 1,100.

 
// Example

// Input:
// [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

// Output:
// [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        if (people.empty())
            return {};
        // 先按照身高降序排列，身高相同则按照编号升序排列
        std::sort(people.begin(), people.end(), [](vector<int>& v1, vector<int>& v2){return v1[0] > v2[0] || (v1[0] == v2[0] && v1[1] < v2[1]);});
        vector<vector<int>> result;
        // 当插入一个元素时，队列中的其他元素height都大于它，所以这个时候可以简单利用编号进行插入
        for (auto p : people)
            result.insert(result.begin() + p[1], p);
        return result;
    }
};