class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, len = s.length();
        while(i < len) {
            if (!isalnum(s[i]) || s[i] == ' '){
                s.erase(i,1);
                len--;
            } else {
                s[i] = tolower(s[i]);
                i++;
            };
        }
        for (int i = 0, j = len - 1; i < j; i++, j--)
            if (s[i] != s[j]) return false;
        return true;
    }
};
