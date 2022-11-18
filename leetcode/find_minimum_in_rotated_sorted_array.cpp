class Solution {
public:
    int findMinAux(const vector<int>& nums, int left, int right) {
        int mid = (left + right) / 2;

        if (left >= right) return nums[mid];
        if (mid > 0 && nums[mid] < nums[mid - 1]) return nums[mid];
        else if (nums[left] <= nums[mid] && nums[mid] > nums[right])
            return findMinAux(nums, mid + 1, right);
        else return findMinAux(nums, left, mid - 1);
    }

    int findMin(vector<int>& nums) {
        return findMinAux(nums, 0, nums.size() - 1);
    }
};
