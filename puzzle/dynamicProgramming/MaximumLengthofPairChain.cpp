// You are given n pairs of numbers. In every pair, the first number is always smaller 
// than the second number.

// Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. 
// Chain of pairs can be formed in this fashion.

// Given a set of pairs, find the length longest chain which can be formed. You needn't 
// use up all the given pairs. You can select pairs in any order.

// Example 1:
// Input: [[1,2], [2,3], [3,4]]
// Output: 2
// Explanation: The longest chain is [1,2] -> [3,4]
// Note:
// The number of given pairs will be in the range [1, 1000].

// Longest Increasing Subsequence
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
  		if (pairs.empty())
  			return 0;
  		std::sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });
  		vector<int> vec;
  		vec.push_back(pairs[0][1]);
  		for (int i = 1; i < pairs.size(); ++i) {
  			if (pairs[i][0] > vec.back()) {
  				vec.push_back(pairs[i][1]);
  			} else {
                if (pairs[i][1] < vec.back()) {
                    int pos = getposition(vec, vec.size(), pairs[i][1]);
                    assert(pos < vec.size());
                    vec[pos] = pairs[i][1];
                }
  			}
  		}
  		return vec.size();      
    }
    
private:
	int getposition(vector<int>& vec, int length, int target) {
		int start = 0, end = length;
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