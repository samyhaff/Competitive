class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> solution;

        for (int i = 0; i < nums.size(); i++) {
            if (map.find(target - nums[i]) != map.end()) {
                solution.push_back(i);
                solution.push_back(map[target - nums[i]]);
                return solution;
            }
            else  map[nums[i]] = i;
        }

        return solution;
    }
};
