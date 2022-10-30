class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int res = 1, left, right;
        left = right = 0;

        while (right < s.length()) {
            while (set.find(s[right]) != set.end()) {
                set.erase(s[left++]);
            }
            set.insert(s[right]);
            right++;
            res = max(res, right - left);
        }

        return (s.length() == 0) ? 0 : res;
    }
};
