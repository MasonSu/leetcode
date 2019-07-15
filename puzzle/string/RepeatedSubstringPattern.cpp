class Solution1 {
public:
    bool repeatedSubstringPattern(string s) {
        if (s.empty())
            return true;
        for (int i = 1; i <= s.size() / 2; ++i) {
            string str = s.substr(0, i);
            if (s.size() % str.size())
                continue;
            int j;
            for (j = i; j < s.size(); j += str.size())
                if (str != s.substr(j, str.size()))
                    break;
            if (j == s.size())
                return true;
        }
        return false;
    }
};

/* O(n) */
class Solution2 {
public:
    bool repeatedSubstringPattern(string s) {
        if (s.empty())
            return true;
        for (int i = 1; i <= s.size() / 2; ++i) {
            string str = s.substr(0, i);
            if (s.size() % str.size())
                continue;

            string leftShift = s.substr(i) + str;
            if (leftShift == s)
                return true;
        }
        return false;
    }
};