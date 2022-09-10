#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string line, token;
    set<string> assumptions;
    bool read_arrow = false;

    getline(cin, line);
    n = stoi(line);

    for (int i = 1; i <= n; i++) {
        getline(cin, line);
        istringstream iss(line);

        while (iss >> token) {
            if (token == "->") read_arrow = true;
            else if (!read_arrow) {
                if (assumptions.find(token) == assumptions.end()) {
                        cout << i;
                        return 0;
                    }
            } else assumptions.insert(token);
        }
        read_arrow = false;
    }

    cout << "correct";
    return 0;
}
