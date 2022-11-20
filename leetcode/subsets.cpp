class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n, length;
        vector<vector<int>> s;

        if (nums.size() == 1) return {{}, {nums[0]}};

        n = nums.back();
        nums.pop_back();

        s = subsets(nums);
        length = s.size();

        for (int i = 0; i < length; i++) {
            vector<int> subset = s[i];
            subset.push_back(n);
            s.push_back(subset);
        }

        return s;
    }
};
