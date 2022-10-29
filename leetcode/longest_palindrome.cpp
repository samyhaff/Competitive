class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> count;
        int ans = 0;

        for (char c: s) {
            if (count.find(c) == count.end()) count[c] = 1;
            else count[c]++;
        }
        for (auto x: count) {
            ans += x.second - x.second % 2;
        }
        for (auto x: count) {
            if (x.second % 2 == 1) {
                ans++;
                break;
            }
        }

        return ans;
    }
};
