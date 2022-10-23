class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> set;
        vector<int> ans;

        for (auto n: nums) {
            if (set.find(n) != set.end()) ans.push_back(n);
            else set.insert(n);
        }

        for (int i = 1; i <= nums.size(); i++)
            if (set.find(i) == set.end()) ans.push_back(i);

        return ans;
    }
};
