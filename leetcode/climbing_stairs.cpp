class Solution {
public:
    int climbStairs(int n) {
        vector<int> count(n + 1 ,1);
        for (int i = 2; i <= n; i++)
            count[i] = count[i-1] + count[i-2];
        return count[n];
    }
};
