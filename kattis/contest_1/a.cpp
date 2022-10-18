#include <iostream>

#define MASK 5550000

using namespace std;

int main() {
    int n;
    cin >> n;

    cout << (n / MASK == 1 && n % MASK < 10000);

    return 0;
}
