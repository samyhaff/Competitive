#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, depth = 0, search_depth;
    string instruction, identifier, type;
    map<string, map<int, string>> variables;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> instruction;
        if (instruction == "DECLARE") {
            cin >> identifier >> type;
            if (variables[identifier].find(depth) == variables[identifier].end()) {
                variables[identifier][depth] = type;
            } else {
                cout << "MULTIPLE DECLARATION";
                return 0;
            }
        } else if (instruction == "TYPEOF") {
            cin >> identifier;
            search_depth = depth;
            while (variables[identifier].find(search_depth) == variables[identifier].end() && search_depth-- >= 0);
            if (search_depth < 0) cout << "UNDECLARED" << endl;
            else  cout << variables[identifier][search_depth] << endl;
        } else if (instruction == "{") {
            depth++;
        } else {
            for (auto it = variables.begin(); it != variables.end(); it++)
                variables[it->first].erase(depth);
            depth--;
        }
    }

    return 0;
}
