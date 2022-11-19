class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(2, 0));
        int max_positive = INT_MIN;

        if (nums.size() == 1) return nums[0];

        if (nums[0] > 0) dp[0][0] = nums[0];
        else if (nums[0] < 0) dp[0][1] = -nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > 0) {
                dp[i][0] = max(nums[i], dp[i - 1][0] * nums[i]);
                dp[i][1] = dp[i - 1][1] * nums[i];
            } else if (nums[i] < 0) {
                dp[i][0] = -dp[i - 1][1] * nums[i];
                dp[i][1] = max(-dp[i - 1][0] * nums[i], -nums[i]);
            } else {
                dp[i] = {0, 0};
            }
        }

        for (int i = 0; i < nums.size(); i++)
            cout << dp[i][0] << " " << dp[i][1] << endl;

        for (int i = 0; i < nums.size(); i++)
            if (dp[i][0] > max_positive)
                max_positive = dp[i][0];

        return max_positive;
    }
};
