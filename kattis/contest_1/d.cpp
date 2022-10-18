#include <iostream>
#include <algorithm>

#define SIZE 40

using namespace std;

int main() {
    int count[SIZE];
    int n, m, max;

    cin >> n >> m;
    for (int i = 0; i < SIZE; i++) count[i] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            count[i + j]++;
        }
    }
    max = *max_element(count, count + SIZE) ;

    for (int i = 0; i < SIZE; i++)
        if (count[i] == max) cout << i + 2 << endl;

    return 0;
}
