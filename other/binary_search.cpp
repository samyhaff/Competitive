#include <bits/stdc++.h>

using namespace std;

bool binary_search(const vector<int> &v, int i, int j, int value) {
    if (j < i) return false;
    int m = (i + j) / 2;
    if (v[m] == value) return true;
    if (v[m] < value) return binary_search(v, m+1, j, value);
    return binary_search(v, i, m-1, value);
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int value = 2;
    bool found = binary_search(v, 0, v.size(), value);
    if (found) cout << "Found " << value << " in the array" << endl;
    else cout << value << " wasn't found in the array";

    return 0;
}
