class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> newIntervals;

        for (auto it = intervals.begin(); it != intervals.end(); it++) {
            if (newInterval[1] < (*it)[0]) {
                newIntervals.push_back(newInterval);
                newIntervals.insert(newIntervals.end(), it, intervals.end());
                return newIntervals;
            }
            if (newInterval[0] > (*it)[1])
                newIntervals.push_back(*it);
            else
            newInterval = {min(newInterval[0], (*it)[0]), max(newInterval[1], (*it)[1])};
        }
        newIntervals.push_back(newInterval);
        return newIntervals;
    }
};
