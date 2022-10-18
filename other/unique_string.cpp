#include <bits/stdc++.h>

using namespace std;

bool check_unique(string s) {
    unordered_set<char> set;

    for (auto c: s) {
        if (set.find(c) == set.end()) set.insert(c);
        else return false;
    }

    return true;
}

int main() {
    string test1 = "abcda";
    string test2 = "abcd";
    cout << check_unique(test1) << endl;
    cout << check_unique(test2) << endl;

    return 0;
}
