class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, res;

        for (auto num: nums) {
            if (count == 0)
                res = num;
            count = (num == res) ? ++count : --count;
        }

        return res;
    }
};
