class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map;
        for (auto c: s) {
            if (map.find(c) == map.end()) map[c] = 1;
            else map[c]++;
        }
        for (auto c: t) {
            if (map.find(c) == map.end( )) return false;
            else map[c]--;
        }
        for (auto item: map) {
            if (item.second > 0) return false;
        }
        return true;
    }
};
