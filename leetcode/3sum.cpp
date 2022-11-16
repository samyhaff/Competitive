class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         int n = nums.size();
        vector<vector<int>> triplets;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i - 1] == nums[i]) continue;

            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                if (nums[j] + nums[k] > -nums[i]) k--;
                else if (nums[j] + nums[k] < -nums[i]) j++;
                else {
                    triplets.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while (nums[j] == nums[j - 1] && j < k) j++;
                }
            }
        }

        return triplets;
    }
};
