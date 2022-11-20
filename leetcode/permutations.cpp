class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n;
        vector<vector<int>> perms, res;

        if (nums.size() == 1) return {nums};


        for (int i = 0; i < nums.size(); i++) {
            n = nums[0]; nums.erase(nums.begin());

            perms = permute(nums);
            for (auto& perm: perms)
                perm.push_back(n);

            res.insert(res.end(), perms.begin(), perms.end());
            nums.push_back(n);
        }

        return res;
    }
};
