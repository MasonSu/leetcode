// Given a string, find the length of the longest substring without repeating characters.

// Example 1:

// Input: "abcabcbb"
// Output: 3 
// Explanation: The answer is "abc", with the length of 3. 
// Example 2:

// Input: "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3. 
//              Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

/*
 * 第一种思路比较简单，两个指针first和second，如果second
 * 碰到之前有重复的值则清空hash表，同时first从下一个位置
 * 开始重新遍历，复杂度比较高
 */
class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
        int max = 0;
        unordered_set<char> hashTable;
        for (int first = 0; first < s.size(); ++first) {
            hashTable.insert(s[first]);
            int count = 1;
            for (int second = first + 1; second < s.size(); ++second) {
                if (hashTable.insert(s[second]).second == false)
                    break;
                count++;
            }
            if (count > max)
                max = count;
            hashTable.clear();
        }
        return max;
    }
};

/*
 * 第二种思路针对第一种思路进行优化，second遇到重复值的时候，
 * first应该从重复值的位置的下一个位置开始遍历，单纯从first
 * 的下一个位置遍历会做很多无用功
 */
class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
        unordered_map<char, int> hashTable;
        int max = 0, first = 0;
        while (first < s.size()) {
            hashTable.insert({s[first], first});
            int count = 1, last = s.size();
            for (int second = first + 1; second < s.size(); ++second) {
                if (hashTable.insert({s[second], second}).second == false) {
                    last = hashTable[s[second]] + 1;
                    break;
                }
                count++;
            }
            if (count > max)
                max = count;
            first = last;
            hashTable.clear();
        }
        return max;
    }
};

/*
 * 第三种思路针对第二种思路进行优化，second直接从下一个位置开始，
 * frist移到重复值位置的下一个位置，不需要清空hash表，也不需要
 * 重新计数count，只需要修改它们的值就行了
 */
class Solution3 {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
        unordered_map<char, int> hashTable;
        int max = 0, first = 0, count = 1;
        hashTable.insert({s[first], first});
        for (int second = first + 1; second < s.size(); ++second) {
            if (hashTable.insert({s[second], second}).second == false) {
                if (count > max)
                    max = count;

                int last = hashTable[s[second]];
                for (int i = first; i <= last; ++i)
                    hashTable.erase(s[i]);
                hashTable.insert({s[second], second});
                count = count - (last - first);
                first = last + 1;
            } else {
                count++;
            }
        }
        if (count > max)
            max = count;
        return max;
    }
};

/*
 * 第四种思路针对第三种思路进行优化，当找到重复值的时候，
 * 不需要对重复值之前的hash表进行清空，只需要调整start
 * 就行了，如果下次再找到重复值，但是重复值所处的位置在
 * start的左侧，则不用调整start的位置，只需要更新hash
 * 表就行了
 */
class Solution4 {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
        unordered_map<char, int> hashTable;
        int start = -1, max = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (hashTable.find(s[i]) != hashTable.end()) {
                start = std::max(start, hashTable[s[i]]);
            }
            hashTable[s[i]] = i;
            max = std::max(max, i - start);
        }
        return max;
    }
};

// https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems
class Solution5 {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
        unordered_map<char, int> str_count;
        int start = 0, end = 0, count = 0, result_length = 1;
        while (end < s.size()) {
            if (++str_count[s[end]] == 2) {
                count--;
            }

            while (count < 0) {
                if (str_count[s[start]]-- == 2) {
                    count++;
                }
                start++;
            }

            result_length = std::max(result_length, end - start + 1);
            end++;
        }
        return result_length;
    }
};

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    Solution4 test;
    REQUIRE(test.lengthOfLongestSubstring("abcabcbb") == 3);
    REQUIRE(test.lengthOfLongestSubstring("bbbbb") == 1);
    REQUIRE(test.lengthOfLongestSubstring("pwwkew") == 3);
    REQUIRE(test.lengthOfLongestSubstring("abcbda") == 4);
    REQUIRE(test.lengthOfLongestSubstring("jfieioqp") == 5);
}
