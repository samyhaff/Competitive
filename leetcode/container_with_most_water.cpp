class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int area, max_area = 0;

        while (left < right) {
            area = (right - left) * min(height[left], height[right]);
            if (area > max_area)
                max_area = area;
            if (height[left] < height[right]) left++;
            else right--;
        }

        return max_area;
    }
};
