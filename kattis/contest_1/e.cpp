#include <iostream>

using namespace std;

// height i <-> sum_k (2k + 1) ** 2

int get_num_blocks(int height) {
    int s = 0;
    for (int i = 0; i < height; i++)
        s += (2 * i + 1) * (2 * i + 1);
    return s;
}

int main() {
    int n;
    cin >> n;

    int h = 0;
    while (get_num_blocks(h) <= n) h++;
    cout << h - 1;

    return 0;
}
