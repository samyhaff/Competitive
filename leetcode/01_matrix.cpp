class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> distances(m, vector<int>(n, INT_MAX));

        if (mat[0][0] == 0) distances[0][0] = 0;
        for (int i = 1; i < m; i++) {
            if (mat[i][0] == 0)
                distances[i][0] = 0;
            else if (distances[i - 1][0] != INT_MAX)
                distances[i][0] = 1 + distances[i - 1][0];
        }
        for (int j = 1; j < n; j++) {
            if (mat[0][j] == 0)
                distances[0][j] = 0;
            else if (distances[0][j - 1] != INT_MAX)
                distances[0][j] = 1 + distances[0][j - 1];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (mat[i][j] == 0) distances[i][j] = 0;
                else if (distances[i - 1][j] != INT_MAX || distances[i][j - 1] != INT_MAX)
                    distances[i][j] = 1 + min(distances[i - 1][j], distances[i][j - 1]);
            }
        }

        for (int i = m - 2; i >= 0; i--)
            distances[i][n - 1] = min(distances[i][n - 1], 1 + distances[i + 1][n - 1]);
        for (int j = n - 2; j >= 0; j--)
            distances[m - 1][j] = min(distances[m - 1][j], 1 + distances[m - 1][j + 1]);
        for (int i = m - 2; i >= 0; i--)
            for (int j = n - 2; j >= 0; j--)
                distances[i][j] = min(distances[i][j], 1 + min(distances[i + 1][j], distances[i][j + 1]));

        return distances;
    }

};
