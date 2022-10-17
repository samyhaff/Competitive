#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &v, int l, int m, int r) {
    vector<int> tmp;
    int i, j;
    i = l;
    j = m + 1;

    while (i <= m && j <= r) {
        if (v[i] <= v[j]) tmp.push_back(v[i++]);
        else tmp.push_back(v[j++]);
    }

    while (i <= m) tmp.push_back(v[i++]);
    while (j <= r) tmp.push_back(v[j++]);

    for (int i = l; i <= r; i++) v[i] = tmp[i - l];
}

void merge_sort(vector<int> &v, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        merge_sort(v, l, m);
        merge_sort(v, m + 1, r);
        merge(v, l, m, r);
    }
}

int main() {
    vector<int> v = {5, 4, 3, 2, 1};
    merge_sort(v, 0, v.size() - 1);
    for (auto x: v) cout << x << " ";
    cout << endl;

    return 0;
}
