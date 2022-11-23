class TimeMap {
private:
       unordered_map<string, vector<pair<int, string>>> map;
public:
    TimeMap() {
       map = unordered_map<string, vector<pair<int, string>>>();
    }

    void set(string key, string value, int timestamp) {
        if (map.find(key) == map.end())
            map[key] = {make_pair(timestamp, value)};
        else
            map[key].push_back(make_pair(timestamp, value));
    }

    string get(string key, int timestamp) {
        if (map.find(key) == map.end()) return "";

        vector<pair<int, string>>& v = map[key];
        int l = 0, r = v.size() - 1, m;
        string res = "";

        while (l <= r) {
            m = (l + r) / 2;
            if (v[m].first == timestamp) {
                res = v[m].second;
                return res;
            } else if (v[m].first < timestamp) {
                res = v[m].second;
                l = m + 1;
            } else r = m - 1;
        }

        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
