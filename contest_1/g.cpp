#include <bits/stdc++.h>

using namespace std;

int main() {
    int theta1, theta2, sign;

    cin >> theta1 >> theta2;
    int dist = max(theta1, theta2) - min(theta1, theta2);
    int change = min(dist, 360 - dist);
    if (change == 180) sign = 1;
    else if (theta2 >= theta1) {
        if (dist <= 360 - dist) sign = 1;
        else sign = -1;
    } else {
        if (dist <= 360 - dist) sign = -1;
        else sign = 1;
    }
    cout << sign * change;

    return 0;
}
