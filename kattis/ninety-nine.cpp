#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 0;

    cout << 2 << endl;
    while (n != 99) {
        cin >> n;
        if ((n + 2) % 3 == 0) n+=2;
        else n++;
        cout << n << endl;
    }

    return 0;
}
