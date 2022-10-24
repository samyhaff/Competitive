class Solution {
public:
    void floodFill_aux(vector<vector<int>>& image, int sr, int sc, int new_color, int old_color) {
        int m = image.size(), n = image[0].size();
        if (sr < 0 || sr >= m || sc < 0 || sc >= n) return;
        if (image[sr][sc] == new_color) return;
        if (image[sr][sc] != old_color) return;

        image[sr][sc] = new_color;
        floodFill_aux(image, sr + 1, sc, new_color, old_color);
        floodFill_aux(image, sr - 1, sc, new_color, old_color);
        floodFill_aux(image, sr, sc + 1, new_color, old_color);
        floodFill_aux(image, sr, sc - 1, new_color, old_color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int old_color = image[sr][sc];
        floodFill_aux(image, sr, sc, color, old_color);
        return image;
    }
};
