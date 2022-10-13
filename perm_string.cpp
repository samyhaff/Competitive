#include <bits/stdc++.h>

using namespace std;

bool check_permutation(string a, string b) {
    unordered_map<char, int> count;

    for (char c: a) {
        if (count.find(c) == count.end()) count[c] = 1;
        else count[c]++;
    }

    for (char c: b) {
        if (count.find(c) == count.end()) return false;
        else count[c]--;
    }

    for (auto x: count) if (x.second != 0) return false;

    return true;
}

int main() {
    string a = "abc";
    string b = "bca";
    string c ="abb";

    cout << check_permutation(a, b) << endl;
    cout << check_permutation(a, c) << endl;

    return 0;
}
