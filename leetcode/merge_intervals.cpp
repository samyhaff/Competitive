struct sort_intervals {
    bool operator()(vector<int> a, vector<int> b) {
        return a[0] < b[0];
    }
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), sort_intervals());
        vector<vector<int>> res = {intervals[0]};
        int n;
        for (int i = 1; i < intervals.size(); i++) {
            n = res.size() - 1;
            if (intervals[i][0] <= res[n][1])
                res[n][1] = max(res[n][1], intervals[i][1]);
            else
                res.push_back(intervals[i]);
        }
        return res;
    }
};
