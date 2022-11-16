class Solution {
public:
    struct cmp {
        bool operator()(vector<int>& a, vector<int>& b) {
            return a[0] * a[0] + a[1] * a[1] > b[0] * b[0] + b[1] * b[1];
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, cmp> queue;
        vector<vector<int>> res;

        for (auto point: points) {
            queue.push(point);
        }

        for (int i = 0; i < k; i++) {
            vector<int> point = queue.top();
            queue.pop();
            res.push_back(point);
        }

        return res;
    }
};
